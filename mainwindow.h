#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QClipboard>
#include <QDebug>

#include "base64.h"
#include "subwidget.h"
#include "dataprocess.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    //slot
    void slotEncode();
    void slotShow_subwidget();
    void slotOpenWindow();


    QString countPassword(QString ,int );
    ~MainWindow();
private:
    QPlainTextEdit *inputHost;
    QPlainTextEdit *inputKey;
    QPlainTextEdit *ResultText;
    QPushButton *btn_generate;
    QPushButton *btn_copy;
    QPushButton *myPassword;
    QClipboard *clipboard;
    subwidget control_window;
};

#endif // MAINWINDOW_H
