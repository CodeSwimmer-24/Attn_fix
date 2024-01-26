sudo docker build -f ../dockerize/drogon/Dockerfile .. -t drogon:latest
sudo docker build -f ../dockerize/server/Dockerfile .. -t test:latest

sudo docker container prune -f
sudo docker run --name testc -p 5555:5555 test:latest
