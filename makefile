CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32
LLIBS = -lm 
OBJ = main.o Window.o

gameInclude = -I sdl/include -I src/objects/player -I src/utils 
gameLibrary = -L sdl/lib

includePath = -I src/objects/player -I src/utils 
libraryPath = -L /library

all:
	$(CC) $(gameInclude) $(gameLibrary) -o ratan src\ratan.cpp -lmingw32 -lSDL2main -lSDL2
win32 : 
	echo "building window.cpp"
	$(CC) src/Window.cpp $(LIBS)
linux :
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LLIBS) -o 
clean :
	rm -fr *.exe *.o *.out *ratan
	echo "cleaned"
