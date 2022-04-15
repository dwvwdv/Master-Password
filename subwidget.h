#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <QApplication>
#include <QClipboard>
#include <QDebug>

#include "dataprocess.h"

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);
    void read_data();

signals:
    void signalClose();
public slots:
    void slotClose();
private:

    QPushButton *click;
    QLabel *labelData;

};

#endif // SUBWIDGET_H
