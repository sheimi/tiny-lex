CC=gcc
LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
CFLAGS=-I$(INC_DIR) -Wall -c
TARGET=$(LIB_DIR)/error.o $(LIB_DIR)/array.o\
			 $(SRC_DIR)/mylex.o $(SRC_DIR)/state.o

ifneq ($(DEBUG),)
	CFLAGS += -g -DDEBUG
else
	CFLAGS += -O2
endif
all: clean mylex

mylex: $(TARGET)
	$(CC) $(TARGET) -o mylex

mylex.o:$(SRC_DIR)/mylex.c
	$(CC) $(CFLAGS) $< -o $(SRC_DIR)/mylex.o

state.o:$(SRC_DIR)/state.c
	$(CC) $(CFLAGS) $< -o $(SRC_DIR)/state.o

error.o:$(LIB_DIR)/error.c
	$(CC) $(CFLAGS) $< -o $(LIB_DIR)/error.o

array.o:$(LIB_DIR)/array.c
	$(CC) $(CFLAGS) $< -o $(LIB_DIR)/array.o

clean:
	rm -rf $(LIB_DIR)/*.o
	rm -rf $(SRC_DIR)/*.o
	rm -rf mylex
