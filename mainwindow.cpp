#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->tableWidget->setRowCount(ui->spinBox->value());
    ui->tableWidget->setColumnCount(ui->spinBox->value());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCells(unsigned n)
{
    QTableWidgetItem* cell;

    for(unsigned i=0;i<n;i++)
    {
		for(unsigned j=0;j<n;j++)
		{
			if(ui->tableWidget->item(int(j), int(i)) == nullptr)
			{
				cell = new QTableWidgetItem();
				ui->tableWidget->setItem(int(j), int(i), cell);
			}
		}
    }
}


void MainWindow::fillCells(int** matr, unsigned n)
{
    for(unsigned i=0;i<n;i++)
    {
		for(unsigned j=0;j<n;j++)
		{
			ui->tableWidget->item(int(j), int(i))->setText(QString::number(matr[i][j]));
		}
    }
}

void MainWindow::printToTextEdit(int** matr, unsigned n)
{
	for(unsigned i=0; i<n; i++)
	{
		for(unsigned j=0; j<n; j++)
		{
			ui->textEdit->setText(ui->textEdit->toPlainText() + " " + QString::number(matr[i][j]));
		}
		ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
	}
}

void MainWindow::on_btnCreateMatr_clicked()
{
    ui->textEdit->clear();

    n = unsigned(ui->spinBox->value());
	matrix = createRandMatr(n);
	matrToFile(matrix, n, fileName);


	n = unsigned(sqrt(countLines(fileName)));
	matrix2 = fileToMatr(fileName, n);
	printToTextEdit(matrix2, n);
	createCells(n);
	fillCells(matrix2, n);

	deleteMatr(matrix, n);
	deleteMatr(matrix2, n);
}


void MainWindow::on_btnRestoreMatr_clicked()
{
    ui->textEdit->clear();

	n = unsigned(sqrt(countLines(fileName)));
	ui->tableWidget->setRowCount(int(n));
	ui->tableWidget->setColumnCount(int(n));

	matrix2 = fileToMatr(fileName, n);
	printToTextEdit(matrix2, n);

    createCells(n);
	fillCells(matrix2, n);

	deleteMatr(matrix2, n);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    n = unsigned(arg1);
    ui->tableWidget->setColumnCount(arg1);
	ui->tableWidget->setRowCount(arg1);
}
