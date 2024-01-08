
includePath = -I include/glm
libraryPath = -L /library

main:
	echo "building main.cpp"
	gcc src/main.cpp $(includePath) $(libraryPath) 

Window : 
	echo "building window.cpp"
	gcc src/Window.cpp
	
clean : 
	echo "cleaned"
