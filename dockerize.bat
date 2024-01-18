docker build -f dockerize/crow/Dockerfile . -t crow:latest
docker build -f dockerize/server/Dockerfile . -t test:latest

docker container prune -f
docker run --name testc -p 8080:8080 test:latest
