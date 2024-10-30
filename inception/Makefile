# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down logs

all: build up

build:
	docker-compose -f $(COMPOSE_FILE) build

up:
	docker-compose -f $(COMPOSE_FILE) up -d

down:
	docker-compose -f $(COMPOSE_FILE) down
