CC=g++
CFLAGS=-Wall -Werror -O3 -std=c++11

SOURCES=*cc
OBJECTS=$(SOURCES:.cc=.o)

EXECUTABLE=test.app

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

test: clean $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *o
