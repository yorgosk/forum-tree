CC = g++
CFLAGS = -Wall
OBJECTS = main.o forum.o thread.o post.o date.o generator.o tree.o list.o

forum2: $(OBJECTS)
	$(CC) $(CFLAGS) -o forum2 $(OBJECTS)

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc

forum.o: forum.cc
	$(CC) $(CFLAGS) -c forum.cc

thread.o: thread.cc
	$(CC) $(CFLAGS) -c thread.cc

post.o: post.cc
	$(CC) $(CFLAGS) -c post.cc

date.o: date.cc
	$(CC) $(CFLAGS) -c date.cc

generator.o: generator.cc
	$(CC) $(CFLAGS) -c generator.cc

tree.o: tree.cc
	$(CC) $(CFLAGS) -c tree.cc

list.o: list.cc
	$(CC) $(CFLAGS) -c list.cc

.PHONY: clean

clean:
	rm -f forum2 $(OBJECTS)
