sudo docker build -f ../dockerize/drogon/Dockerfile .. -t drogon:latest
sudo docker build -f ../dockerize/server/Dockerfile .. -t test:latest

sudo docker container prune -f
sudo docker run --name testc -p 8080:80 test:latest
