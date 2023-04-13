#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_openDirectoryButton_clicked();

    void on_clearContentButton_clicked();

    void on_closeAppButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
