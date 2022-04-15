#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600,600);
//    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明化
    this->setWindowFlags(Qt::FramelessWindowHint);   //無邊窗口

    click = new QPushButton("back",this);
    click->move(500,500);
    labelData = new QLabel("無資料...",this);
    labelData->move(200,200);

    connect(click,&QPushButton::clicked,this,&subwidget::slotClose);
//    labelData->setText();
}


void subwidget::slotClose(){
    emit signalClose();
}


void subwidget::read_data(){

    QString filePath = "./";
    QString fileName = "1.txt";
    QFile file(filePath + fileName);
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot open file for reading:" << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    QString AllData;
    int rawLength = 0;
    while(!in.atEnd()){
        QString fileline = in.readLine();
        AllData += fileline;
        if(rawLength++ % 2 == 0)
            AllData += "　：　";
        else
            AllData += "\n";
    }
    labelData->setText(AllData);


    file.close();
}
