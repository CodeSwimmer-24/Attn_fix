sudo docker build -f dockerize/crow/Dockerfile . -t crow:latest
sudo docker build -f dockerize/server/Dockerfile . -t test:latest

sudo docker container prune -f
sudo docker run --name testc -p 8080:8080 test:latest
