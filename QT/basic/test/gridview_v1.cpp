#include "mainwindow.h"
#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QDir>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    // 이미지 경로 설정
    //QString imagePath = "/path/to/your/images"; // 여기에 실제 이미지 경로를 입력하세요.
    QString imagePath = "/home/iot/work/opencv/image/face/w/";

    // 이미지 파일을 읽어올 수 있는 QDir 객체 생성
    QDir imageDir(imagePath);
    imageDir.setNameFilters(QStringList() << "*.jpg" << "*.png" << "*.bmp");
    QStringList imageFiles = imageDir.entryList();

    // QListWidget 생성
    QListWidget listWidget;

    // 이미지를 읽어와 QListWidget에 추가
    for (const QString &imageFile : imageFiles) {
        QListWidgetItem *listItem = new QListWidgetItem(QIcon(imagePath + "/" + imageFile), imageFile);
        listWidget.addItem(listItem);
    }

    // QListWidget의 레이아웃 및 스타일 설정
    listWidget.setResizeMode(QListView::Adjust);
    listWidget.setViewMode(QListView::IconMode);
    listWidget.setGridSize(QSize(100, 100));
    listWidget.setSpacing(10);
    listWidget.setMovement(QListView::Static);
    listWidget.setIconSize(QSize(64, 64));

    listWidget.show();


    return a.exec();
}
