#include "dataprocess.h"


void write_data(QString hosts,QString password){
    QString filePath = "./";
    QString fileName = "1.txt";
    QFile file(filePath + fileName);
    if (!file.open(QIODevice::Append)){
        qDebug() << "Cannot open file for writing:" << qPrintable(file.errorString());
        return;
    }

    QTextStream out(&file);
    out << hosts << "\n";
    out << password << "\n";

    file.close();
}

void read_data(){
    qDebug() << "hello?";

    QString filePath = "./";
    QString fileName = "1.txt";
    QFile file(filePath + fileName);
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot open file for reading:" << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QString fileline = in.readLine();
        qDebug() << fileline;
    }

    file.close();
}
