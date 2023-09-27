CC = gcc

CFLAGS = -Wall

OUTPUT = out

SRC_FILE = x.c

all: $(OUTPUT)

$(OUTPUT): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE) -lm

clean:
	rm -f $(OUTPUT) $(SRC_FILE:.c=.o)

run:
	./$(OUTPUT)

debug: CFLAGS += -g
debug: $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)
	gdb ./$(OUTPUT)

.PHONY: all clean run debug