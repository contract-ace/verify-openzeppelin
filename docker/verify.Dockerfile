FROM seahorn/seahorn-llvm10:nightly

# nvm defaults for Scribble install.
ENV NVM_DIR /home/usea/.nvm
ENV NODE_VERSION 10.24.1

# Installs nvm.
USER usea
RUN curl https://raw.githubusercontent.com/creationix/nvm/v0.30.0/install.sh | bash && \
    . $NVM_DIR/nvm.sh && \
    nvm install $NODE_VERSION && \
    nvm alias default $NODE_VERSION && \
    nvm use default

# Installs scribble through npm.
USER usea
ENV NODE_PATH $NVM_DIR/versions/node/v$NODE_VERSION/lib/node_modules
ENV PATH $NVM_DIR/versions/node/v$NODE_VERSION/bin:$PATH
RUN npm install --global eth-scribble

# Unpacks smartace and klee.
USER usea
COPY smartace-*.tar.gz /tmp
COPY klee.tar.gz /tmp
WORKDIR /home/usea
RUN mkdir -p /home/usea/smartace && \
    mkdir -p /home/usea/klee && \
    tar xf /tmp/smartace-*.tar.gz -C smartace --strip-components=1 && \
    tar xf /tmp/klee.tar.gz -C klee --strip-components=3 && \
    git clone https://github.com/contract-ace/verify-openzeppelin.git /home/usea/contracts

# Cleanup.
USER root
RUN rm -rf /tmp/smartace-*.tar.gz && \
    rm -rf /tmp/klee.tar.gz

# Evaluation environment.
USER usea
ENV PATH $PATH:/home/usea/klee/bin:/home/usea/smartace/bin

