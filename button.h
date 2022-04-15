#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class button : public QPushButton
{
    Q_OBJECT
public:
    explicit button(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // BUTTON_H
