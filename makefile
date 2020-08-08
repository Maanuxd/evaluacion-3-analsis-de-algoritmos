CXX = g++
CXXFLAGS = -fopenmp -g3 -Wall -lm
MKDIR = mkdir -p

LIBS = -lm 

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

funciones.o: directorios Funciones.cpp Funciones.h
	$(CXX) $(CXXFLAGS) -c Funciones.cpp -o build/funciones.o

semestre.o: directorios Semestre.cpp Semestre.h
	$(CXX) $(CXXFLAGS) -c Semestre.cpp -o build/semestre.o


all: clean main.o funciones.o semestre.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/funciones.o build/semestre.o $(LIBS) 
	rm -fr build


clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all