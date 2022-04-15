#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // QFile qss(R"(C:\Users\USER\Desktop\example.css)");
    QFile qss(R"(C:\Users\USER\Desktop\example.qss)");
    qss.open(QFile::ReadOnly);
    if(qss.isOpen()){
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }

    MainWindow w;
    w.show();

    return a.exec();
}
