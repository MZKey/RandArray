#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(ui->spinBox->value());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createArrBtn_clicked()
{
    ui->textEdit->clear();

    n = unsigned(ui->spinBox->value());
    arr = createRandArr(n);
    fromArrToFile(arr, n, fileName);

    createCells(ui->tableWidget, n);
    fillCells(ui->tableWidget, arr, n);

    n = countLines(fileName);
    arr2 = fromFileToArr(fileName, n);
    printToTextEdit(arr2, n, ui->textEdit);

    delete arr;
    delete arr2;
}


void MainWindow::on_restoreArrBtn_clicked()
{
    ui->textEdit->clear();

    n = countLines(fileName);
    ui->tableWidget->setColumnCount(int(n));
    arr = fromFileToArr(fileName, n);
    printToTextEdit(arr, n, ui->textEdit);

    createCells(ui->tableWidget, n);
    fillCells(ui->tableWidget, arr, n);

    delete arr;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    n = unsigned(arg1);
    ui->tableWidget->setColumnCount(arg1);
}
