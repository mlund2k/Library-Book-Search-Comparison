CC = g++ -std=c++14
CFLAGS = -g -Wall -Werror
INC_CL = book.h timer.h
OBJ = book.o timer.o SearchNewBooks.o

all:	SearchNewBooks

book.o: book.cc
	$(CC) -c $(CFLAGS) book.cc
timer.o: timer.cc
	$(CC) -c $(CFLAGS) timer.cc
SearchNewBooks.o: SearchNewBooks.cc
	$(CC) -c $(CFLAGS) SearchNewBooks.cc

SearchNewBooks: $(OBJ)
	$(CC) -o SearchNewBooks $(OBJ)

.PHONY: clean

clean:
	-rm -f *.o *.exe *~ SearchNewBooks