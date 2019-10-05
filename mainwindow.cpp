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
		for(unsigned j=0; j<columns; j++)
		{
			if(ui->tableWidget->item(int(i), int(j)) == nullptr)
			{
				cell = new QTableWidgetItem();
				ui->tableWidget->setItem(int(i), int(j), cell);
			}
		}
    }
}


void MainWindow::fillCells(vector<vector<int> > &matrix)
{
	for(unsigned i=0;i<matrix.size();i++)
    {
		for(unsigned j=0;j<matrix[i].size();j++)
		{
			ui->tableWidget->item(int(i), int(j))->setText(QString::number(matrix[i][j]));
		}
    }
}

void MainWindow::printToTextEdit(vector<vector<int> > &matrix)
{
	QString str;
	for(unsigned i=0; i<matrix.size(); i++)
	{
		str = "";
		for(unsigned j=0; j<matrix[i].size(); j++)
		{
			str += QString::number(matrix[i][j]) + " ";
		}
		ui->textEdit->append(str);
	}
}

void MainWindow::on_btnCreateMatr_clicked()
{
    ui->textEdit->clear();


    rows = unsigned(ui->spinBoxRows->value());
    columns = unsigned(ui->spinBoxColumns->value());
	ui->tableWidget->setRowCount(int(rows));
	ui->tableWidget->setColumnCount(int(columns));

    matrix = createRandMatr(rows, columns);
	matrToFile(matrix, fileName);

    matrix2 = fileToMatr(fileName,rows,columns);
	printToTextEdit(matrix2);
    createCells(rows, columns);
	fillCells(matrix2);

	deleteMatr(matrix);
	deleteMatr(matrix2);
}


void MainWindow::on_btnRestoreMatr_clicked()
{
    ui->textEdit->clear();

    matrix2 = fileToMatr(fileName, rows, columns);
    ui->tableWidget->setRowCount(int(rows));
    ui->tableWidget->setColumnCount(int(columns));
	printToTextEdit(matrix2);

    createCells(rows, columns);
	fillCells(matrix2);

	deleteMatr(matrix2);
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

void MainWindow::on_btnClear_clicked()
{
	ui->tableWidget->clear();
	ui->textEdit->clear();
}
