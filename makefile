CC = g++
CFLAGS = -g -Wall
LIBS = 
OBJ = main.o Window.o
includePath = -I src/objects/player -I src/utils 
libraryPath = -L /library

main:
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LIBS) -o main
Windows : 
	$(CC) src/Window.cpp $(LIBS)
linux :
	$(CC) src/linuxWindow.cpp $(includePath) $(libraryPath) $(LIBS) -o main
clean :
	rm -fr *.exe *.o *.out
	echo "cleaned"
