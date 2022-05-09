# Building the Environment

This directory containers Dockerfiles to build the experiment environment, and to package its dependencies.
To build the experiment environment, first install [Docker](https://hub.docker.com/).
After Docker has been installed, build the environment by running:

```
docker build --tag verify-openzeppelin -f ./verify.Dockerfile .
```

## Overriding the Scribble Version

The Dockerfile locks Scribble at version `0.5.3` to ensure compatibility with all test scripts.
However, you can override the Scribble version by setting `NODE_V_ARG` and `SCRIBBLE_VERSION` appropriately.
For example, the following command builds the environment with Scribble at version `0.6.7`:
```
docker build --build-arg NODE_V_ARG=16.5.0 --build-arg SCRIBBLE_V_ARG=0.6.7 --tag verify-openzeppelin -f ./verify.Dockerfile .
```
Note that this is known to break `postprocess_scribble.py` (see [this issue](https://github.com/contract-ace/verify-openzeppelin/issues/1) for more details).
