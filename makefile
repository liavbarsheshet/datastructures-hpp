# Application Information
NAME = ds-hpp
VERSION = 1.0.0

# Enviroment
CFLAGS = -Wall -g -std=c++20
OBJS = main.o
CC = g++
EXEC =

ifeq ($(OS),Windows_NT)
	EXEC += .exe
endif

# Path Alias
RELEASE_PATH = release/$(VERSION)
BUILD_PATH = debug/$(VERSION)

# Main
main.o: ./source/main.cpp
	$(CC) $(CFLAGS) -c $^ -o ./objects/main.o


all: $(OBJS)
	$(CC) $(CFLAGS) -o ./debug/$(NAME)@$(VERSION)$(EXEC) ./objects/*

publish:
	mkdir -p ./source
	cp -r ./source/*.hpp ./$(RELEASE_PATH)

clean:
	rm -f ./objects/*.o