TARGET = asciilines
CXX = g++
CXXFLAGS = -Wall -g

BUILD = ./build
OBJ_DIR = $(BUILD)/obj
SRC = $(wildcard ./*.cpp)
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(BUILD)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILD)/$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/$(TARGET) $(OBJ)

.PHONY: all build clean debug release

build:
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
