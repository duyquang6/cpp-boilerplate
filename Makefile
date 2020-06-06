SHELL = /bin/sh
PROJECT ?= "cpp-boilerplate"
PROJECT_NAME := $(PROJECT)
BUILD_DATE := `date +%FT%T%z`
CURRENT_DIR := $(abspath $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))) )))
BUILD_DIR := $(CURRENT_DIR)/build
.PHONY: all test build prepare clean dep

prepare:
	@echo $(BUILD_DATE)

dep:
	@mkdir -p build && cd build && conan install ..

build:
	@cd build && cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build .

test: build
	@./build/test/bin/runUnitTests

clean:
	@rm -rf *.o build cmake-build-debug


