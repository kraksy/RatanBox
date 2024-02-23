CC = g++
WCC = winegcc 
CFLAGS = -g -Wall
LIBS = -lm -lstdc++ -lgdi32 -lfmt
OBJ = main.o Window.o
includePath = -I src/utils -I src -I src/3rd_party/fmt -I src/3rd_party/sokol -I src\3rd_party\fmt -I src/3rd_party/imgui
libraryPath = -L /library -L glfw -L glfw3.lib -L /usr/X11/lib

main:
	g++ src/ratan.cpp -I src/utils -I src -I src/3rd_party/fmt -I src/3rd_party/sokol -I path/to/fmt -L /library -L glfw -L glfw3.lib -o main -lm -lstdc++ -lgdi32 -lfmt
win32 : 
	$(CC) src\win32_window.cpp $(includePath) $(libraryPath) -o win32_window $(LIBS)
linux :
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) -lX11 -lfmt
clean :
	del /F /Q *.exe *.o *.out
	echo "cleaned"
