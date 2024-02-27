#include "fileInputOutput.h"
#include "multiplication.h"

#include <iostream>
#include <fstream>
#include <vector>

// parameterized ctor
FileClass::FileClass(string file_name)
{
    inFile.open(file_name);

    if (!inFile.is_open()) // if file failed to open
    {
        std::cout << "\nFailed to open the file" << std::endl;
        exit(-1);
    }

    outFile.open(file_name);
}

// dtor
FileClass::~FileClass()
{
    inFile.close();
    outFile.close();
}

// reads contents of file and inputs it into the vector
void getData(std::vector<Multiplication> &multiplications, const std::string &filename)
{
    std::ifstream inFile;

    inFile.open(filename);

    if (!inFile.is_open()) // if file failed to open
    {
        std::cout << "\nFailed to open the file" << std::endl;
        exit(-1);
    }

    std::string skip = "";
    std::getline(inFile, skip); // skip first line

    int mcand, mul, bits;
    while (inFile >> mcand >> mul >> bits)
        multiplications.push_back(Multiplication(mcand, mul, bits));
}