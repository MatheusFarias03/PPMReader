install: PPMReader

PPMReader: build/main.o build/ImageReader.o
	g++ build/main.o build/ImageReader.o -o PPMReader

build/main.o: main.cpp build
	g++ -c main.cpp -o build/main.o

build/ImageReader.o: ImageReader/ImageReader.cpp ImageReader/ImageReader.hpp build
	g++ -c ImageReader/ImageReader.cpp -o build/ImageReader.o

build:
	mkdir build

uninstall:
	rm -r build
	rm -r PPMReader
