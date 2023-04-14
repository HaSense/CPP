#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <opencv2/opencv.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadImageButton_clicked();

    void on_convertToGrayscaleButton_clicked();

    void on_histogramEqualizationButton_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat image;
    void showImage(const cv::Mat &img);
};

#endif // MAINWINDOW_H
