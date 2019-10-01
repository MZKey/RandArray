#ifndef MODULE_H
#define MODULE_H

#endif // MODULE_H

#include <fstream>
#include <string>
#include <cstdlib>

#include <QString>


// Count of lines in file
unsigned countLines(std::string fileName);

// Count of cullumns in file
unsigned countCol(std::string fileName);

// Create random matrix
int** createRandMatr(unsigned rows, unsigned columns);

// Delete matrix
void deleteMatr(int** matr, unsigned n);

// From file to matrix
int** fileToMatr(std::string fileName, unsigned rows, unsigned columns);

// From matrix to file
void matrToFile(int** matr, unsigned rows, unsigned columns, std::string fileName);
