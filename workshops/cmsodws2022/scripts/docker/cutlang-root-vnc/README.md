### vnc password
```
cutlang-adl
```

### Setup
*Requirements*
- [Docker](https://www.docker.com/products/docker-desktop)

Download the image and run the container using
```bash
 docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v $PWD/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest # download image and run container in current directory from downloaded image
 # for windows: docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v %cd%/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest
 # if you want to re-run by mounting another directory, you should run:
 # docker stop CutLang-root-vnc && docker container rm CutLang-root-vnc
 # and go back step 2 with different path 'docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v /path/to/you/want/:/src ...'
 # example:
 # docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v ~/example_work_dir/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest
```
Exec the container using
```bash
 docker exec -it CutLang-root-vnc bash
```
Now, you can run CutLang

### Update
Update the docker image using
```bash
 docker pull cutlang/cutlang-root-vnc:latest # install the latest image
 # and
 docker stop CutLang-root-vnc && docker container rm CutLang-root-vnc
 docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v $PWD/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc
```

### Remove
Remove the docker container and image using
```bash
  docker stop CutLang-root-vnc
  docker ps -a | grep "CutLang-root-vnc" | awk '{print $1}' | xargs docker rm
  docker images -a | grep "cutlang-root-vnc" | awk '{print $3}' | xargs docker rmi
```
