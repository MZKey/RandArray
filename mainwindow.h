#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <string>
#include <fstream>
#include <math.h>

#include "module.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
	void on_btnCreateMatr_clicked();

	void on_btnRestoreMatr_clicked();

    void createCells(unsigned rows, unsigned columns);

    void fillCells(int** matr, unsigned rows, unsigned columns);

    void printToTextEdit(int** matr, unsigned rows, unsigned columns);

    void on_spinBoxColumns_valueChanged(int arg1);

    void on_spinBoxRows_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    unsigned rows;
    unsigned columns;
    int* arr;
    int* arr2;
	int** matrix;
	int** matrix2;
    std::string fileName = "text.txt";

};

#endif // MAINWINDOW_H
