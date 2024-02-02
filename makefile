CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32
LLIBS = -lm 
OBJ = main.o Window.o
includePath = -I src/objects/player -I src/utils 
libraryPath = -L /library

main:
	$(CC) src/win32_window.cpp $(includePath) $(libraryPath) $(LIBS) -o ratan
Window : 
	echo "building window.cpp"
	$(CC) src/Window.cpp $(LIBS)
linux :
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LLIBS) -o ratan
clean :
	rm -fr *.exe *.o *.out *ratan
	echo "cleaned"
