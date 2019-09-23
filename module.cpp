#include "module.h"


int* createRandArr(unsigned n)
{
    int* arr;
    unsigned i;

    arr = new int[n];

    for(i=0;i<n;i++)
    {
        arr[i] = rand();
    }
    return arr;
}


void deleteArray(int* arr)
{
    delete arr;
}


void fromArrToFile(int* arr, unsigned n, std::string fileName)
{
    unsigned i;
    std::ofstream file;
    file.open(fileName);

    for(i=0;i<n;i++)
    {
        file<<arr[i]<<"\n";
    }
    file.close();
}



QString fromFileTxt(std::string fileName)
{
    char str[50];
    QString strOut;
    std::ifstream file;

    file.open(fileName);
    file.getline(str,50);
    file.close();

    strOut = QString::fromStdString(str);
    return strOut;
}


void printToTextEdit(int* arr, unsigned n, QTextEdit* textEdit)
{
    unsigned i;
    QString str;

    for(i=0; i<n; i++)
    {
        textEdit->append(str.setNum(arr[i]));
    }
}


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


int* fromFileToArr(std::string fileName, unsigned n)
{
    int* arr;
    unsigned i;
    //char endLine;
    std::string str;
    //char str[50];
    std::ifstream file;
    QString strOut;

    file.open(fileName);

    arr = new int[n];

    for(i=0;i<n;i++)
    {
        std::getline(file,str);
        //file >> arr[i];
        arr[i] = std::atoi(str.c_str());
    }

    file.close();
    return arr;
}

