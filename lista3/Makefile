CC = gcc
CFLAGS = -Wall
OUTPUT = out
SRC_FILE = 02.c

.PHONY: all clean run debug

all: $(OUTPUT)

$(OUTPUT): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OUTPUT)

run: all
	./$(OUTPUT)

debug: CFLAGS += -g
debug: all
	gdb ./$(OUTPUT)