CC=g++
LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
CFLAGS=-I$(INC_DIR) -Wall -c
TARGET=$(LIB_DIR)/error.o $(LIB_DIR)/util.o\
			 $(SRC_DIR)/mylex.o $(SRC_DIR)/nfa.o $(SRC_DIR)/dfa.o $(SRC_DIR)/file_parser.o
TARGET_OBJ=error.o util.o\
					 mylex.o nfa.o dfa.o file_parser.o

ifneq ($(DEBUG),)
	CFLAGS += -g -DDEBUG
else
	CFLAGS += -O2
endif

all: clean mylex

mylex: $(TARGET_OBJ)
	$(CC) $(TARGET) -o mylex

mylex.o:$(SRC_DIR)/mylex.cpp
	$(CC) $< -o $(SRC_DIR)/mylex.o $(CFLAGS) 

nfa.o:$(SRC_DIR)/nfa.cpp
	$(CC) $< -o $(SRC_DIR)/nfa.o $(CFLAGS) 

dfa.o:$(SRC_DIR)/dfa.cpp
	$(CC) $< -o $(SRC_DIR)/dfa.o $(CFLAGS) 

file_parser.o:$(SRC_DIR)/file_parser.cpp
	$(CC) $< -o $(SRC_DIR)/file_parser.o $(CFLAGS) 

error.o:$(LIB_DIR)/error.cpp
	c++ $< -o $(LIB_DIR)/error.o $(CFLAGS) 

util.o:$(LIB_DIR)/util.cpp
	c++ $< -o $(LIB_DIR)/util.o $(CFLAGS) 

clean:
	rm -rf $(LIB_DIR)/*.o
	rm -rf $(SRC_DIR)/*.o
	rm -rf mylex
