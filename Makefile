CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o initialize.o execute.o
EXEC = shell

all: $(EXEC)
	@echo "I will begin building your program."
	@echo "The program is complete and its name is 'shell'."
	@echo "To execute it, type './shell' in your terminal."
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(EXEC): $(OBJ)

main.o: main.c initialize.h execute.h
	$(CC) $(CFLAGS) -c main.c

initialize.o: initialize.c initialize.h
	$(CC) $(CFLAGS) -c initialize.c

execute.o: execute.c execute.h
	$(CC) $(CFLAGS) -c execute.c

clean:
	rm -f $(OBJ) # Removes only object files, keeps the executable
