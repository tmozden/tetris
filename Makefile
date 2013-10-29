# name of executable 
EXEC=tetris

# list of headers
HEADERS= 

# list of .c and .cpp files
SOURCE=

CC=g++

FLAGS=-Wall -g 

LIBS=-l


$(EXEC): $(SOURCE) $(HEADERS)
  $(CC) -p $(EXEC) $(FLAGS) $(LIBS) $(SOURCE)

clean:
  rm -f $(EXEC) *.o 
