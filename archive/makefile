CC = g++
WCC = winegcc # for linux win32 cross compilation

CFLAGS = -g -Wall

LIBS = -lm -lstdc++ -lgdi32 

includePath = -I src/utils -I src -I src/3rd_party/glad/include -I src/3rd_party/glfw/include
libraryPath = -L /library -L glfw -L glfw3.lib -L /usr/X11/lib

glad = -I src/3rd_party/glad/include
glfw = -lglfw3
gl = -lGL 

x11 = -lX11 -lXrandr -lXi -ldl

all:
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) -o ratan
main:
	g++ src/ratan.cpp $(includePath) $(libraryPath) -lX11 -lfmt -lglfw3 -lGL -lGLEW -lstdc++ -lm -lGL -lX11 -lpthread -lXrandr -lXi -ldl
win : 
	$(CC) src/win32_window.cpp $(includePath) $(libraryPath) -o win $(LIBS)
linux :
	$(CC) src/ratan.cpp $(includePath) $(libraryPath) -lX11 -lfmt -lglfw3 -lGL -lGLEW -lstdc++ -lm -lGL -lX11 -lpthread -lXrandr -lXi -ldl
clean :
	del /F /Q *.exe *.o *.out
	echo "cleaned"
