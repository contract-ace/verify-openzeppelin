FROM seahorn/smartace:baijiu

# Installs time command.
USER root
RUN apt-get install -y time

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
RUN npm install --global eth-scribble@0.5.3

# Pulls contracts from github.
USER usea
RUN git clone https://github.com/contract-ace/verify-openzeppelin.git /home/usea/verify

