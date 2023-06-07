CC = gcc
SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
C_HEADER_FILES := $(wildcard *.h)

all: $(OBJECTS) $(C_HEADER_FILES)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c $(C_HEADER_FILES)
	$(CC) -std=c89 -pedantic -I$(SRC) -c $< -o $@