#ifndef MODULE_H
#define MODULE_H

#endif // MODULE_H

#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

#include <QString>

using namespace std;

// Count of lines in file
unsigned countRows(string fileName);

// Count of cullumns in file
unsigned countColumns(string fileName);

// Create random matrix
vector<vector<int>> createRandMatr(unsigned rows, unsigned columns);

// Delete matrix
void deleteMatr(int** matr, unsigned n);

// From file to matrix
vector<vector<int>> fileToMatr(string fileName, unsigned& rows, unsigned& columns);

// From matrix to file
void matrToFile(vector<vector<int>> &matr, unsigned rows, unsigned columns, string fileName);

// Delete matrix(vector)
void deleteMatr(vector<vector<int>> &matr);
