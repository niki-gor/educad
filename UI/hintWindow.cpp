//
// Created by George on 29.05.2022.
//

#include "hintWindow.h"

HintWindow::HintWindow(QWidget *parent) {
    this->setText("uzbek");
    movement=0;
    forwardButton = this->addButton("Вперёд", ButtonRole::YesRole);
    backButton = this->addButton("Назад", ButtonRole::NoRole);
    connect(forwardButton, SIGNAL(clicked()), SLOT(forward()));
    connect(backButton, SIGNAL(clicked()), SLOT(back()));
}

void HintWindow::back() {
    movement=-1;
}

void HintWindow::forward() {
    movement=1;
}
