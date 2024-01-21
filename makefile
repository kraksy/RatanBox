CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++
OBJ = main.o Window.o
includePath = -I src/objects/player -I src/utils # Point to the directory, not the file
libraryPath = -L /library

main:
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LIBS) -o main
Window : 
	echo "building window.cpp"
	$(CC) src/Window.cpp $(LIBS)
clean :
	rm -fr *.exe *.o *.out
	echo "cleaned"