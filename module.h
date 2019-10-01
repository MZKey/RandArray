#ifndef MODULE_H
#define MODULE_H

#endif // MODULE_H

#include <fstream>
#include <string>
#include <cstdlib>

#include <QString>


// Count of lines in file
unsigned countLines(std::string fileName);

// Create random matrix
int** createRandMatr(unsigned n);

// Delete matrix
void deleteMatr(int** matr, unsigned n);

// From file to matrix
int** fileToMatr(std::string fileName, unsigned n);

// From matrix to file
void matrToFile(int** matr, unsigned n, std::string fileName);
