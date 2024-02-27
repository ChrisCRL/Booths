#ifndef H_fileInputOutput
#define H_fileInputOutput

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "multiplication.h"

using namespace std;


class FileClass
{

public:
    ifstream inFile;
    ofstream outFile;
    bool fileError;

    /* Open the input and output files in the constructor; 
    print error messages accordingly if the files are not present */
    FileClass(string file_name); // constructor with a single parameter

    /* This destructor is to close input and output files*/
    ~FileClass();                // Destructor
};

// global functions
/*To read data from input file and copy it to vector object. It reads 
multiplicand, multiplier and bits amount for each operation
*/
void getData(std::vector<Multiplication> &multiplications, const std::string &filename);

#endif // H_fileInfo
