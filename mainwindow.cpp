#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(300,300);
    this->setWindowFlags(Qt::FramelessWindowHint);   //無邊窗口

    inputHost = new QPlainTextEdit("",this);
    inputHost->setPlaceholderText("輸入完整域名.");
    inputHost->resize(240,30);
    inputHost->move(35,10);


    inputKey = new QPlainTextEdit("",this);
    inputKey->setPlaceholderText("輸入你的鑰匙.");
    inputKey->resize(240,30);
    inputKey->move(35,50);
//    inputKey->show();

    btn_generate = new QPushButton("Get Password",this);
    btn_generate->move(100,100);

    btn_copy = new QPushButton("copy",this);
    btn_copy->resize(50,30);
    btn_copy->move(200,160);
    btn_copy->setEnabled(0);

    myPassword = new QPushButton("My Password",this);
    myPassword->move(200,250);

    ResultText = new QPlainTextEdit("",this);
    ResultText->resize(90,30);
    ResultText->move(105,160);

    connect(btn_generate,&QPushButton::clicked,this,&MainWindow::slotEncode);
    connect(myPassword,&QPushButton::clicked,this,&MainWindow::slotShow_subwidget);
    connect(&control_window,&subwidget::signalClose,this,&MainWindow::slotOpenWindow);
    connect(btn_copy,&QPushButton::clicked,this,[=](){
       clipboard = QApplication::clipboard();
       clipboard->setText(ResultText->toPlainText());
       ResultText->setEnabled(0);
       btn_copy->setEnabled(0);
    });
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotEncode(){
    QString tQdt = inputKey->toPlainText() + inputHost->toPlainText();
    QString Qdt = "";
    for(int i=0;i<tQdt.length();i++){
        if(i % 2)
            Qdt += tQdt[i];
    }
    for(int i=0;i<tQdt.length();i++){
        if(i % 2 == 1)
            Qdt += tQdt[i-1];
    }
//    qDebug() << Qdt;
//    qDebug() << tQdt;
    std::string dt = Qdt.toStdString();
    std::vector<BYTE> Data = {};
    for(int i=0;i<Qdt.length();i++){
     Data.push_back(dt[i]);
    }
    std::string encodedData = base64_encode(&Data[0], Data.size());
    QString Base64_Result = QString::fromStdString(encodedData);
    qDebug() << Base64_Result;
    QString Password = countPassword(Base64_Result,8);
    ResultText->setPlainText(Password);
    btn_copy->setEnabled(1);
    write_data(inputHost->toPlainText(),Password);
}

QString MainWindow::countPassword(QString base64,int max){
    QString password = "";
    for(int i=0;i<max;i++){
        if(base64[i]=='=')
            break;
        password += base64[i];
    }
    return password;
}


void MainWindow::slotShow_subwidget(){
    hide();

    control_window.read_data();
    control_window.show();

}

void MainWindow::slotOpenWindow(){
    show();
    control_window.close();
}
