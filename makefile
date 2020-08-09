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

catedra.o: directorios Catedra.cpp Catedra.h
	$(CXX) $(CXXFLAGS) -c Catedra.cpp -o build/catedra.o

sala.o:	directorios Sala.cpp Sala.h
	$(CXX) $(CXXFLAGS) -c Sala.cpp -o build/sala.o


all: clean main.o funciones.o catedra.o sala.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/funciones.o build/catedra.o build/sala.o $(LIBS) 
	rm -fr build


clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all