#include <toolbar.h>
#include <QPushButton>
#include "QObject"
#include "QApplication"
//#include "QDesktopWidget"
#include <canvas.h>
#include "QPalette"
#include "QAbstractButton"

ToolBar::ToolBar (QWidget *parent, Canvas* _canvas) {
    parentWidget=parent;
    canvas=_canvas;
    toolBarWidget = new QFrame();
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = rec.height();
    int scrWidth = rec.width();
    int butSize = scrHeight*556/10000;
    toolBarWidget->setGeometry(0,0,scrWidth,butSize);
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(255, 255, 255));
    toolBarWidget->setAutoFillBackground(true);
    toolBarWidget->setPalette(pal);
    toolBarWidget->setFrameShape(QFrame::Box);
    toolBarWidget->setLineWidth(2);
    toolBarWidget->setMidLineWidth(1);
    cursorButton = new QPushButton( toolBarWidget);
  //  cursorButton->setText("Cursor");
    cursorButton->setGeometry(QRect(1,1,butSize,butSize-2));
    QPixmap cursorPixmap ("../Icons/cursor.svg");
    QIcon cursorButtonIcon(cursorPixmap);
    cursorButton->setIcon(cursorButtonIcon);
    cursorButton->setIconSize(cursorButton->rect().size());
    connect(cursorButton, &QPushButton::released, this, &ToolBar::cursorButtonHandler);
    newProjectButton = new QPushButton( toolBarWidget);
    QPixmap newProjectPixmap ("../Icons/new_file.svg");
    QIcon newProjectIcon(newProjectPixmap);
    newProjectButton->setIcon(newProjectPixmap);
    newProjectButton->setIconSize(newProjectButton->rect().size());
    newProjectButton->setGeometry(QRect(1+butSize,1,butSize,butSize-2));
    saveProjectButton = new QPushButton(toolBarWidget);
    QPixmap saveProjectPixmap ("../Icons/Save.svg");
    QIcon saveProjectIcon (saveProjectPixmap);
    saveProjectButton->setIcon(saveProjectIcon);
    saveProjectButton->setIconSize(saveProjectButton->rect().size());
    saveProjectButton->setGeometry(QRect(1+2*butSize,1,butSize,butSize-2));
    openProjectButton = new QPushButton(toolBarWidget);
    QPixmap openProjectPixmap ("../Icons/open_file.svg");
    QIcon openProjectIcon(openProjectPixmap);
    openProjectButton->setIcon(openProjectPixmap);
    openProjectButton->setIconSize(openProjectButton->rect().size());
    openProjectButton->setGeometry(QRect(1+3*butSize,1,butSize,butSize-2));
    createPointButton = new QPushButton(toolBarWidget);
    QPixmap createPointPixmap ("../Icons/point.svg");
    QIcon createPointIcon(createPointPixmap);
    createPointButton->setIcon(createPointPixmap);
    createPointButton->setIconSize(createPointButton->rect().size());
    createPointButton->setGeometry(QRect(1+4*butSize,1,butSize,butSize-2));
    connect(createPointButton, &QPushButton::released, this, &ToolBar::createPointButtonHandler);
    createLineButton = new QPushButton(toolBarWidget);
    QPixmap createLinePixmap ("../Icons/line.svg");
    QIcon createLineIcon(createLinePixmap);
    createLineButton->setIcon(createLinePixmap);
    createLineButton->setIconSize(createLineButton->rect().size());
    createLineButton->setGeometry(QRect(1+5*butSize,1,butSize,butSize-2));
    connect(createLineButton, &QPushButton::released, this, &ToolBar::createLineButtonHandler);
    createProjectionPlaneButton = new QPushButton (toolBarWidget);
    QPixmap createProjectionPlanePixmap ("../Icons/plane.svg");
    QIcon createProjectionPlaneIcon(createProjectionPlanePixmap);
    createProjectionPlaneButton->setIcon(createProjectionPlanePixmap);
    createProjectionPlaneButton->setIconSize(createProjectionPlaneButton->rect().size());
    createProjectionPlaneButton->setGeometry(QRect(1+6*butSize,1,butSize,butSize-2));
    resizeButton = new QPushButton (toolBarWidget);
    QPixmap resizePixmap ("../Icons/transform.svg");
    QIcon resizeIcon(resizePixmap);
    resizeButton->setIcon(resizePixmap);
    resizeButton->setIconSize(resizeButton->rect().size());
    resizeButton->setGeometry(QRect(1+7*butSize,1,butSize,butSize-2));
    eraseButton = new QPushButton ( toolBarWidget);
    QPixmap erasePixmap ("../Icons/Erase.svg");
    QIcon eraseIcon(erasePixmap);
    eraseButton->setIcon(erasePixmap);
    eraseButton->setIconSize(eraseButton->rect().size());
    eraseButton->setGeometry(QRect(1+8*butSize,1,butSize,butSize-2));
    connect(eraseButton, &QPushButton::released, this, &ToolBar::eraseButtonHandler);
    lineMethod = new LineComboBox;
    lineMethod->addItem("Прямая по 2 точкам");
    lineMethod->addItem("Прямая, перпендикулярная выбранной");
    lineMethod->addItem("Прямая, параллельная выбранной");
}

void ToolBar::newProjectButtonHandler() {};
void ToolBar::saveProjectButtonHandler() {};
void ToolBar::openProjectButtonHander () {};
void ToolBar::createPointButtonHandler () {
    canvas->condition = 1;
    printf ("\ncondition is set to %d\n", canvas->condition);
};
void ToolBar::createLineButtonHandler () {
    lineMethod->showPopup(createLineButton->x()+createLineButton->width(), createLineButton->height()+ QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight));
    canvas->condition = 2;
    printf ("\ncondition is set to %d\n", canvas->condition);
};
void ToolBar::createProjectionPlaneButtonHandler () {};
void ToolBar::resizeButtonHandler() {};
void ToolBar::eraseButtonHandler() {

    printf ("\ncondition is set to clear");
    //canvas->clear();
    canvas->condition=3;
};

void ToolBar::cursorButtonHandler() {
    canvas->condition=0;
}

void LineComboBox::showPopup(int x, int y) {
    qApp->setEffectEnabled(Qt::UI_AnimateCombo, false);
    QComboBox::showPopup();
    QWidget *popup = this->findChild<QFrame*>();
    popup->move(x,y);
}
