#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Khởi tạo ứng dụng Qt
    MainWindow w;                // Tạo cửa sổ chính
    w.show();                    // Hiển thị cửa sổ
    return a.exec();             // Bắt đầu vòng lặp sự kiện
}
