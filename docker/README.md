# Building the Environment

This directory containers Dockerfiles to build the experiment environment, and to package its dependencies.
To build the experiment environment, first install [Docker](https://hub.docker.com/).
After Docker has been installed, build the environment by running:

```
docker build --tag verify-openzeppelin -f ./verify.Dockerfile .
```
