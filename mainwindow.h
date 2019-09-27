#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <string>
#include <fstream>

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
    void on_createArrBtn_clicked();

    void on_restoreArrBtn_clicked();

    void on_spinBox_valueChanged(int arg1);


private:
    Ui::MainWindow *ui;
    unsigned n;
    int* arr;
    int* arr2;
    std::string fileName = "text.txt";

};

#endif // MAINWINDOW_H
