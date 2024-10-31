# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down clean

all: clean build up

build:
	docker-compose -f $(COMPOSE_FILE) build

up:
	docker-compose -f $(COMPOSE_FILE) up -d

down:
	docker-compose -f $(COMPOSE_FILE) down

clean:
	docker rm -f $$(docker ps -aq) || true  # Remove all stopped containers
	docker rmi -f $$(docker images -aq) || true  # Remove all images
