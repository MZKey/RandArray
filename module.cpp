#include "module.h"


unsigned countRows(string fileName)
{
	string str;
	ifstream file;
    unsigned n;
    n = 0;
    file.open(fileName);
    while(!file.eof())
    {
		getline(file, str);
        if(str == "")
           n++;
    }
    n--;
    file.close();
    return n;
}

unsigned countColumns(string fileName)
{
	string str;
	ifstream file;
    unsigned n;
    n = 0;
    file.open(fileName);
    while(!file.eof())
    {
		getline(file,str);
        n++;
        if(str == "")
            break;
    }
    n--;
    file.close();
    return n;
}

vector<vector<int>> createRandMatr(unsigned rows, unsigned columns)
{
	vector<vector<int>> matr;

	matr.resize(rows);

    for(unsigned i = 0; i<rows; i++)
    {
		matr[i].resize(columns);
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

vector<vector<int>> fileToMatr(string fileName, unsigned &rows, unsigned &columns)
{
	vector<vector<int>> matrix;
	string str;
	ifstream file;

	file.open(fileName);
    rows = countRows(fileName);
    columns = countColumns(fileName);

	matrix.resize(rows);

    for(unsigned i=0; i<rows; i++)
	{
		matrix[i].resize(columns);
        for(unsigned j = 0; j < columns; j++ ){
			getline(file, str);
			matrix[i][j] = atoi(str.c_str());
		}
		getline(file,str);
	}

	file.close();
	return matrix;
}

void deleteMatr(vector<vector<int>> &matr)
{
	for(unsigned i = 0; i < matr.size(); i++)
	{
		matr[i].clear();
	}
	matr.clear();
}

void matrToFile(vector<vector<int>> &matr, string fileName)
{
	ofstream file;
	file.open(fileName);

	for(unsigned i=0;i<matr.size();i++)
	{
		for(unsigned j=0;j<matr[i].size();j++)
		{
			file<<matr[i][j]<<"\n";
		}
		file<<"\n";
	}
	file.close();
}

