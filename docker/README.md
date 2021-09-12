# Building the Environment

This directory containers Dockerfiles to build the experiment environment, and to package its dependencies.
To build the experiment environment, first install [Docker](https://hub.docker.com/).
After Docker has been installed, build the environment by running:

```
docker build --tag verify-builder-klee -f ./verify-build-klee.Dockerfile .
docker build --tag verify-builder-smartace -f ./verify-build-smartace.Dockerfile .
docker run -v $(pwd):/host -it verify-builder-klee /bin/sh -c "cp *.tar.gz /host/"
docker run -v $(pwd):/host -it verify-builder-smartace /bin/sh -c "cp *.tar.gz /host/"
docker build --tag verify-openzeppelin -f ./verify.Dockerfile .
```
