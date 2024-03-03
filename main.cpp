//
//  main.cpp
//  PPMReader
//
//  Created by Matheus Matsumoto on 01/03/24.
//
//  References: 
//      https://cplusplus.com/reference/istream/istream/read/
//      https://netpbm.sourceforge.net/doc/ppm.html 
//      https://onlinetools.com/ascii/convert-bytes-to-ascii 
//      https://support.ptc.com/help/mathcad/r9.0/en/index.html#page/PTC_Mathcad_Help/example_grayscale_and_color_in_images.html 
//      https://www.w3schools.com/cpp/cpp_files.asp

#include <iostream>
#include "ImageReader/ImageReader.hpp"

int main(int argc, const char * argv[]) {
    
    std::string fileNameInput = "";
    std::cout << "Insert the name of the file to be read.\n>> ";
    std::cin >> fileNameInput;
    
    ImageReader reader;
    if (reader.readImage(fileNameInput)) {
        reader.applyGrayFilter();
        return 0;
    }
    return 1;
}
