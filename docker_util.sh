if [ $1 = "prod" ]; then
    cp ./docker-compose_prod.yml ./docker-compose.yml
    cp ./Dockerfile_prod ./Dockerfile
elif [ $1 = "dev" ]; then
    cp ./docker-compose_dev.yml ./docker-compose.yml
    cp ./Dockerfile_dev ./Dockerfile
else
  echo "Only prod and dev are valid"
fi