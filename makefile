# name of executable 
EXEC=tetris

# list of headers
HEADERS= 

# list of .c and .cpp files
SOURCE=Main.cpp

CC=g++

FLAGS=-Wall -g 

LIBS=-lGLEW -lglut -lX11 -lGL -lGLU


$(EXEC): $(SOURCE) $(HEADERS)
	$(CC) -o $(EXEC) $(FLAGS) $(LIBS) $(SOURCE)

clean:
	rm -f $(EXEC) *.o 
