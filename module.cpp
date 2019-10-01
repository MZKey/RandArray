#include "module.h"


unsigned countLines(std::string fileName)
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
    }
    n--;
    file.close();
    return n;
}

int** createRandMatr(unsigned n)
{
    int** matr;

    matr = new int*[n];

    for(unsigned i = 0; i<n; i++)
    {
        matr[i] = new int[n];
        for(unsigned j = 0; j<n; j++)
        {
            matr[i][j] = rand();
        }
    }
    return matr;
}

void deleteMatr(int** matr, unsigned n)
{
    for(unsigned i = 0; i<n; i++)
    {
        delete matr[i];
    }

    delete matr;
}

int** fileToMatr(std::string fileName, unsigned n)
{
	int** matrix;
	std::string str;
	std::ifstream file;

	file.open(fileName);

	matrix = new int*[n];

	for(unsigned i=0; i<n; i++)
	{
		matrix[i] = new int[n];
		for(unsigned j = 0; j < n; j++ ){
			std::getline(file, str);
			matrix[i][j] = std::atoi(str.c_str());
		}
	}

	file.close();
	return matrix;
}

void matrToFile(int** matr, unsigned n, std::string fileName)
{
	std::ofstream file;
	file.open(fileName);

	for(unsigned i=0;i<n;i++)
	{
		for(unsigned j=0;j<n;j++)
		{
			file<<matr[i][j]<<"\n";
		}
	}
	file.close();
}

