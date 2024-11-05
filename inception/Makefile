# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down

all: build up

build:
	sudo mkdir -p /home/root/data/wordpress
	sudo mkdir -p /home/root/data/mariadb
	docker-compose -f $(COMPOSE_FILE) build

up:
	docker-compose -f $(COMPOSE_FILE) up

down:
	docker-compose -f $(COMPOSE_FILE) down

clean :
	rm -rf /home/root/data/wordpress
	rm -rf /home/root/data/mariadb
	docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null