# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down

all: build up

build:
	@if [ "$$(docker ps -aq)" ]; then \
		docker rm -f $$(docker ps -aq); \
	fi;  # Remove all stopped containers if any
	@if [ "$$(docker images -aq)" ]; then \
		docker rmi -f $$(docker images -aq); \
	fi;  # Remove all images if any
	sudo rm -rf /home/root/data/mariadb
	sudo mkdir -p /home/root/data/mariadb
	docker-compose -f $(COMPOSE_FILE) build

up:
	docker-compose -f $(COMPOSE_FILE) up

down:
	docker-compose -f $(COMPOSE_FILE) down
