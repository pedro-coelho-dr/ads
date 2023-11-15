CC = gcc
CFLAGS = -Wall
OUTPUT = out
SRC_FILE = arvore_binaria.c

all: $(OUTPUT)

$(OUTPUT): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)

clean:
	rm -f $(OUTPUT)

run:
	./$(OUTPUT)

debug: CFLAGS += -g
debug: all
	gdb ./$(OUTPUT)

.PHONY: all clean run debug