docker container prune -f
docker run --name workersdb -p 3306:3306 -e MYSQL_ROOT_PASSWORD=password123 -d mysql:latest
