//
// Created by George on 29.05.2022.
//

#ifndef EDUCAD_HINTWINDOW_H
#define EDUCAD_HINTWINDOW_H

#include "QMessageBox"
#include "QPushButton"
#include "QObject"

class HintWindow : public QMessageBox {
Q_OBJECT
public:
    HintWindow(QWidget *parent = nullptr);
    ~HintWindow() {}
    int movement;
private slots:
    void back();
    void forward();
private:
    QPushButton *forwardButton;
    QPushButton *backButton;
};

#endif //EDUCAD_HINTWINDOW_H
