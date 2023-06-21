#include "Header/configFile.hpp"
#include <iostream>
#include <fstream>
#include <string>

configFile::configFile(){}
configFile::~configFile(){}
configFile::configFile(char *file,bool valid_file){
    this->file = file;
    this->valid_file = valid_file  ;
}
bool configFile::validefile(){
    return this->valid_file;
}
void configFile::parsing(){

    std::ifstream inputFile(this->file); 

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}





