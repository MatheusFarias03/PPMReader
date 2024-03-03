//
//  ImageReader.hpp
//  PPMReader
//
//  Created by Matheus Matsumoto on 01/03/24.
//

#ifndef ImageReader_hpp
#define ImageReader_hpp

#include <iostream>
#include <string>
#include <fstream> // File Stream.


class ImageReader {
private:
    std::ifstream inputFile;
    char *imageData;
    int fileSize;
    std::string format;
    int width;
    int height;
    int maxColor;
    
public:
    
    ImageReader();
    ~ImageReader();

    bool readImage(std::string imagePath);

    void printImageData();
    
    void applyGrayFilter();
};

#endif /* ImageReader_hpp */
