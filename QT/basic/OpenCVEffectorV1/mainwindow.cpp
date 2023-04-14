#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMessageBox>
#include <opencv2/imgproc.hpp>

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

void MainWindow::on_loadImageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
        image = cv::imread(fileName.toStdString(), cv::IMREAD_COLOR);
        if (!image.empty()) {
            showImage(image);
        }
}

void MainWindow::on_convertToGrayscaleButton_clicked()
{
    if (image.empty()) {
            QMessageBox::warning(this, tr("Warning"), tr("Please load an image first."));
            return;
        }
        cv::Mat grayImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
        showImage(grayImage);
}

void MainWindow::on_histogramEqualizationButton_clicked()
{
    if (image.empty()) {
            QMessageBox::warning(this, tr("Warning"), tr("Please load an image first."));
            return;
        }
        cv::Mat grayImage, equalizedImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
        cv::equalizeHist(grayImage, equalizedImage);
        showImage(equalizedImage);
}

void MainWindow::showImage(const cv::Mat &img)
{
    cv::Mat temp;
    cv::cvtColor(img, temp, cv::COLOR_BGR2RGB);
    QImage qImage(temp.data, temp.cols, temp.rows, static_cast<int>(temp.step), QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
}
