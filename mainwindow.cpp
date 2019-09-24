#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();

    unsigned n;
    int* arr;
    int* arr2;

    //std::string fileName = "text.txt";
    n = unsigned(ui->spinBox->value());
    arr = createRandArr(n);
    fromArrToFile(arr,n,fileName);

    delete arr;

    n = countLines(fileName);
    arr2 = fromFileToArr(fileName, n);
    printToTextEdit(arr,n,ui->textEdit);
    delete arr2;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();

    unsigned n;
    int* arr;
    //std::string fileName = "text.txt";

    n = countLines(fileName);
    arr = fromFileToArr(fileName, n);
    printToTextEdit(arr, n, ui->textEdit);

    delete arr;
}
/*
void MainWindow::on_actionOpen_triggered()
{
    //fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Txt File (*.txt)"));
    QFileDialog dialog;
    dialog.setNameFilter(tr("Txt File (*.txt)"));
    if (dialog.exec())
    {
        QString qfileName = dialog.getSaveFileName(this,
                tr("Save Address Book"), "",
                tr("Address Book (*.abk);;All Files (*)"));

        //fileName = dialog.select
        //fileName = dialog.selectFile().toUtf8().constData();
    }
}
*/
