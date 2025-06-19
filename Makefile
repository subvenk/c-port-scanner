CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/scanner.c
OBJ = $(SRC:.c=.o)
EXEC = port_scanner

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(EXEC)
