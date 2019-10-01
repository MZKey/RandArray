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

    void on_spinBox_valueChanged(int arg1);

    void createCells(unsigned n);

	void fillCells(int** matr, unsigned n);

	void printToTextEdit(int** matr, unsigned n);


private:
    Ui::MainWindow *ui;
    unsigned n;
    int* arr;
    int* arr2;
	int** matrix;
	int** matrix2;
    std::string fileName = "text.txt";

};

#endif // MAINWINDOW_H
