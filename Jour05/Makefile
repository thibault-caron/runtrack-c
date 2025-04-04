CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = music
SRC = main.c music_list.c
OBJ = $(SRC:.c=.o)
BINDIR = .

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(BINDIR)/$(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINDIR)/$(TARGET)
	rm -f $(BINDIR)/$(TARGET).exe

run: all
	./$(BINDIR)/$(TARGET)

.PHONY: all clean fclean run
