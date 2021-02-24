CC=g++
CXXFLAGS=-g -Wall -std=c++17
LIBS=
LIB_DIR=
INCLUDE = -Iinclude/ 
SRC_DIR = ./src
OBJ_DIR = ./obj
TARGET=main
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: main

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS) $(LIB_DIR) $(LIBS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS) $(LIB_DIR) $(LIBS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)