CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32
OBJ = main.o Window.o
includePath = -I src/objects/player -I src/utils 
libraryPath = -L /library

main:
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LIBS) -o ratan
Window : 
	echo "building window.cpp"
	$(CC) src/Window.cpp $(LIBS)
linux :
	$(CC) src/linuxWindow.cpp $(includePath) $(libraryPath) $(LIBS) -o main
clean :
	rm -fr *.exe *.o *.out
	echo "cleaned"
