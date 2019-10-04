#include "module.h"


unsigned countRows(std::string fileName)
{
    std::string str;
    std::ifstream file;
    unsigned n;
    n = 0;
    file.open(fileName);
    while(!file.eof())
    {
        std::getline(file, str);
        if(str == "")
           n++;
    }
    n--;
    file.close();
    return n;
}

unsigned countColumns(std::string fileName)
{
    std::string str;
    std::ifstream file;
    unsigned n;
    n = 0;
    file.open(fileName);
    while(!file.eof())
    {
        std::getline(file,str);
        n++;
        if(str == "")
            break;
    }
    n--;
    file.close();
    return n;
}

int** createRandMatr(unsigned rows, unsigned columns)
{
    int** matr;

    matr = new int*[rows];

    for(unsigned i = 0; i<rows; i++)
    {
        matr[i] = new int[columns];
        for(unsigned j = 0; j<columns; j++)
        {
            matr[i][j] = rand();
        }
    }
    return matr;
}

void deleteMatr(int** matr, unsigned rows)
{
    for(unsigned i = 0; i<rows; i++)
    {
        delete[] matr[i];
    }

    delete[] matr;
}

int** fileToMatr(std::string fileName, unsigned rows, unsigned columns)
{
	int** matrix;
	std::string str;
	std::ifstream file;

	file.open(fileName);

    matrix = new int*[rows];

    for(unsigned i=0; i<rows; i++)
	{
        matrix[i] = new int[columns];
        for(unsigned j = 0; j < columns; j++ ){
			std::getline(file, str);
            matrix[i][j] = std::atoi(str.c_str());
		}
        std::getline(file,str);
	}

	file.close();
	return matrix;
}

void matrToFile(int** matr, unsigned rows, unsigned columns, std::string fileName)
{
	std::ofstream file;
	file.open(fileName);

    for(unsigned i=0;i<rows;i++)
	{
        for(unsigned j=0;j<columns;j++)
		{
			file<<matr[i][j]<<"\n";
		}
        file<<"\n";
	}
	file.close();
}

