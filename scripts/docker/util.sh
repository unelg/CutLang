CUTLANG_DIR="$( dirname $( dirname $( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd ) ) )"
DOCKER_UTIL_DIR=$CUTLANG_DIR/scripts/docker

if [ $1 = "prod" ]; then
    cp $DOCKER_UTIL_DIR/docker-compose_prod.yml $CUTLANG_DIR/docker-compose.yml
    cp $DOCKER_UTIL_DIR/Dockerfile_prod $CUTLANG_DIR/Dockerfile
elif [ $1 = "dev" ]; then
    cp $DOCKER_UTIL_DIR/docker-compose_dev.yml $CUTLANG_DIR/docker-compose.yml
    cp $DOCKER_UTIL_DIR/Dockerfile_dev $CUTLANG_DIR/Dockerfile
else
  echo "Only prod and dev are valid"
fi

unset CUTLANG_DIR
unset DOCKER_UTIL_DIR