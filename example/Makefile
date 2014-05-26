CC=g++

# yadda yadda yadda beware -O3 optimizations and threading
CFLAGS=-Wall -Werror -O3 -std=c++11

# std::thread relies on the pthread lib          
LIBS=-lpthread

# remember to add all sources from subdirectories as well here
SOURCES=*cc ../base/*cc ../scheduling/*cc

OBJECTS=$(SOURCES:.cc=.o)

EXECUTABLE=spp.app

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# remember to run unit tests
test: clean $(EXECUTABLE)
	./$(EXECUTABLE) --test

clean:
	rm -f $(EXECUTABLE) *.o
