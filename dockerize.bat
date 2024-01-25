docker build -f dockerize/drogon/Dockerfile . -t drogon:latest
docker build -f dockerize/server/Dockerfile . -t test:latest

docker container prune -f
docker run --name testc -p 5555:5555 test:latest
