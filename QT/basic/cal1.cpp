#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstring>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //std::cout << "Clicked" << std::endl;
    bool ok;
    int a = ui->le_1->text().toInt(&ok);
    int b = ui->le_2->text().toInt(&ok);

    int result = a + b;

    ui->le_result->setText(QString::number(result));


}
