CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall
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

carrera.o: directorios Carrera.cpp Carrera.h
	$(CXX) $(CXXFLAGS) -c Carrera.cpp -o build/carrera.o

all: clean main.o funciones.o catedra.o sala.o carrera.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/funciones.o build/catedra.o build/sala.o build/carrera.o $(LIBS) 
	rm -fr build


clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all