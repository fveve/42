# Variables
COMPOSE_FILE=srcs/docker-compose.yml

# Targets
.PHONY: all build up down logs

all: build

build:
	docker-compose up -f $(COMPOSE_FILE) build
