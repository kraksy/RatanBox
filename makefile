CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++
OBJ = main.o Window.o
includePath = -I include/glm
libraryPath = -L /library

main:
	$(CC) src/main.cpp $(includePath) $(libraryPath) $(LIBS) -o main
Window : 
	echo "building window.cpp"
	$(CC) src/Window.cpp $(LIBS)
clean :
	rm -fr *.exe *.o *.out
	echo "cleaned"