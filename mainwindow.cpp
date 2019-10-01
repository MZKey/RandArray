#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(ui->spinBoxRows->value());
    ui->tableWidget->setColumnCount(ui->spinBoxColumns->value());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCells(unsigned rows, unsigned columns)
{
    QTableWidgetItem* cell;

    for(unsigned i=0;i<rows;i++)
    {
        for(unsigned j=0;j<columns;j++)
		{
			if(ui->tableWidget->item(int(i), int(j)) == nullptr)
			{
				cell = new QTableWidgetItem();
				ui->tableWidget->setItem(int(i), int(j), cell);
			}
		}
    }
}


void MainWindow::fillCells(int** matr, unsigned rows, unsigned columns)
{
    for(unsigned i=0;i<rows;i++)
    {
        for(unsigned j=0;j<columns;j++)
		{
			ui->tableWidget->item(int(i), int(j))->setText(QString::number(matr[i][j]));
		}
    }
}

void MainWindow::printToTextEdit(int** matr, unsigned rows, unsigned columns)
{
    for(unsigned i=0; i<rows; i++)
	{
        for(unsigned j=0; j<columns; j++)
		{
			ui->textEdit->setText(ui->textEdit->toPlainText() + " " + QString::number(matr[i][j]));
		}
		ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
	}
}

void MainWindow::on_btnCreateMatr_clicked()
{
    ui->textEdit->clear();


    rows = unsigned(ui->spinBoxRows->value());
    columns = unsigned(ui->spinBoxColumns->value());
    matrix = createRandMatr(rows, columns);
    matrToFile(matrix, rows, columns, fileName);

	rows = countRows(fileName);
	columns = countColumns(fileName);
    matrix2 = fileToMatr(fileName,rows,columns);
    printToTextEdit(matrix2, rows, columns);
    createCells(rows, columns);
	fillCells(matrix2, rows, columns);

    deleteMatr(matrix, rows);
    deleteMatr(matrix2, rows);
}


void MainWindow::on_btnRestoreMatr_clicked()
{
    ui->textEdit->clear();

	rows = countRows(fileName);
	columns = countColumns(fileName);
    ui->tableWidget->setRowCount(int(rows));
    ui->tableWidget->setColumnCount(int(columns));

    matrix2 = fileToMatr(fileName, rows, columns);
    printToTextEdit(matrix2, rows, columns);

    createCells(rows, columns);
    fillCells(matrix2, rows, columns);

    deleteMatr(matrix2, rows);
}


void MainWindow::on_spinBoxColumns_valueChanged(int arg1)
{
    columns = unsigned(arg1);
    ui->tableWidget->setColumnCount(arg1);
}

void MainWindow::on_spinBoxRows_valueChanged(int arg1)
{
    rows = unsigned(arg1);
    ui->tableWidget->setRowCount(arg1);
}
