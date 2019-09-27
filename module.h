#ifndef MODULE_H
#define MODULE_H

#endif // MODULE_H

#include <fstream>
#include <string>
#include <cstdlib>

#include <QString>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTableWidget>


// Create array with random numbers
int* createRandArr(unsigned n);

// Delete array
void deleteArray(int* arr);

// Numbers from array to txt file
void fromArrToFile(int* arr, unsigned n, std::string fileName);

// Numbers from array to textEdit widget
void printToTextEdit(int* arr, unsigned n, QTextEdit* textEdit);

// Count of lines in file
unsigned countLines(std::string fileName);

// Numbers from file to QString variable
QString fromFileTxt(std::string fileName);

// Numbers from file to array
int* fromFileToArr(std::string fileName, unsigned n);

// Create cells for tableWidget
void createCells(QTableWidget* tableWidget, unsigned n);

// Fill the cells of tableWidget
void fillCells(QTableWidget* tableWidget, int* arr, unsigned n);
