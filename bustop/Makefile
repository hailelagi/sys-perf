CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -ggdb -std=c++20 -O0

NAME ?= main
BUILD_DIR := build

SRC := $(NAME).cpp lib.cpp
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

.PHONY: all build run clean

all: build run

build: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: build
	./$(BUILD_DIR)/$(NAME)

clean:
	rm -rf $(BUILD_DIR)
