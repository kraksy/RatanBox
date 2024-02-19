CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32 -lfmt
OBJ = main.o Window.o

includePath = -I src/objects/player -I src/utils -I src -I src/3rd_party/fmt -I src/3rd_party/sokol
libraryPath = -L /library -L glfw

main:
	g++ src/ratan.cpp -I src/utils -I src -L /library -o main -lm -lstdc++ -lgdi32 -L glfw3.lib
win32 : 
	$(CC) src\win32_window.cpp $(includePath) $(libraryPath) -o win32_window $(LIBS)
linux :
	$(CC) src/linuxWindow.cpp $(includePath) $(libraryPath) -o main -lX11 -lfmt
clean :
	del /F /Q *.exe *.o *.out
	echo "cleaned"
