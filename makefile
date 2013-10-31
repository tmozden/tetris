# name of executable 
EXEC=tetris

# list of headers
HEADERS= 

#list of object files
OBJECTS=Main.o

# list of .c and .cpp files
SOURCE=Main.cpp

CC=g++

FLAGS=-Wall -g 

LIBS=-lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi


$(EXEC): $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) -o $(EXEC) $(FLAGS) $(LIBS) 

$(OBJECTS): $(SOURCE) $(HEADERS)
	$(CC) -c $(SOURCE)

clean:
	rm -f $(EXEC) *.o 
