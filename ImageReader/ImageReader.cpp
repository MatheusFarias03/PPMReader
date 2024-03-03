//
//  ImageReader.cpp
//  PPMReader
//
//  Created by Matheus Matsumoto on 01/03/24.
//

#include "ImageReader.hpp"

ImageReader::ImageReader() {
    imageData = nullptr;
}

ImageReader::~ImageReader() {
    // Deallocate memory when object is destroyed.
    if (imageData != nullptr) {
        delete[] imageData;  
    } 
}

bool ImageReader::readImage(std::string imagePath) {

    inputFile.open(imagePath, std::ifstream::binary);
    
    // Throw error if not opened.
    if (inputFile.is_open() == false) {
        std::cout << "Error opening file." << std::endl;
        return false;
    }
    
    // Read image format (P6).
    inputFile >> format;

    // Read the image width, height, and maximum color value.
    inputFile >> width >> height >> maxColor;

    // Read the rest of the header.
    std::string dummy;
    std::getline(inputFile, dummy); // Read the newline after maxColor.
    
    // Calculate the size of the pixel data.
    fileSize = width * height * 3; // 3 bytes per pixel (RGB)

    // Store the image's data.
    imageData = new char[fileSize];
    inputFile.read(imageData, fileSize);
    
    inputFile.close();
    
    return true;
};

void ImageReader::printImageData() {
    std::cout << format << "\n" << width << "\n" << height << "\n" << maxColor << std::endl;
    for (int i = 0; i < fileSize; i++) {
        // Convert each byte to an unsigned int before printing.
        std::cout << static_cast<unsigned int>(static_cast<unsigned char>(imageData[i])) << " ";
    }
    std::cout << "\n" << std::endl;
}

void ImageReader::applyGrayFilter() {
    // Data in file is stored as bytes, necessary to use 'unsigned char'.
    unsigned char R, G, B, grayColor;
    char *grayImageData = new char[fileSize];
    std::string grayFileName = "";

    for (int i = 0; i < fileSize; i += 3) {
        R = imageData[i];
        G = imageData[i+1];
        B = imageData[i+2];

        // Calculate grayColor value.
        grayColor = static_cast<unsigned char>(0.299 * R + 0.587 * G + 0.114 * B);

        grayImageData[i] = grayColor; // Red channel.
        grayImageData[i+1] = grayColor; // Green channel.
        grayImageData[i+2] = grayColor; // Blue channel.
    }
    
    std::cout << "\nInsert the name of the file to be written.\n>> ";
    std::cin >> grayFileName;

    std::ofstream grayImageFile(grayFileName, std::ios::binary);
    if (!grayImageFile.is_open()) {
        std::cout << "Error opening file for writing." << std::endl;
        delete[] grayImageData;
        return;
    }

    // Write PPM header.
    grayImageFile << format << "\n" << width << " " << height << "\n" << maxColor << "\n";

    // Write the grayscale pixel data.
    grayImageFile.write(reinterpret_cast<char*>(grayImageData), fileSize);
    
    grayImageFile.close();

    delete[] grayImageData;
}