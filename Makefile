CC=g++
LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
CFLAGS=-I$(INC_DIR) -Wall -c
TARGET=$(LIB_DIR)/error.o \
			 $(SRC_DIR)/mylex.o $(SRC_DIR)/nfa.o
TARGET_OBJ=error.o \
					 mylex.o nfa.o

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

error.o:$(LIB_DIR)/error.cpp
	c++ $< -o $(LIB_DIR)/error.o $(CFLAGS) 

clean:
	rm -rf $(LIB_DIR)/*.o
	rm -rf $(SRC_DIR)/*.o
	rm -rf mylex
