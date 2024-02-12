CC = g++
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32
OBJ = main.o Window.o

includePath = -I src/objects/player -I src/utils -I src -I d3d12
libraryPath = -L /library -L glfw
main:
	g++ src\ratan.cpp -I src/utils -I src -L /library -o main -lm -lstdc++ -lgdi32 -L glfw3.lib -ld3d12 -L d3d12.lib -L dxgi.lib -L dxguid -I d3d12 -I dxgi -I dxguid -I d3d12
win32 : 
	$(CC) src\win32_window.cpp $(includePath) $(libraryPath) -o win32_window $(LIBS)
linux :
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) $(LLIBS) -o 
clean :
	del /F /Q *.exe *.o *.out
	echo "cleaned"