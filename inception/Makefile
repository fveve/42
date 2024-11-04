# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down

all: build up

build:
    docker rm -f $$(docker ps -aq) || true  # Remove all stopped containers
    docker rmi -f $$(docker images -aq) || true  # Remove all images
    sudo mkdir -p /home/root/data/mariadb
    docker-compose -f srcs/docker-compose.yml build
up:
	docker-compose -f $(COMPOSE_FILE) up -d

down:
	docker-compose -f $(COMPOSE_FILE) down
