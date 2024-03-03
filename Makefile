.PHONY: build
build:
	docker compose build

.PHONY: run
run: build
	docker compose up

.PHONY: stop
stop:
	docker compose down
