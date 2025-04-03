CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = album_program
SRCDIR = Jour04/Job02

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(SRCDIR)/$(TARGET) $(SRCDIR)/main.c $(SRCDIR)/print_album.c

clean:
	rm -f $(SRCDIR)/$(TARGET)
