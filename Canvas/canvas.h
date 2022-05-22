#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include "QPushButton"
#include <QPen>
#include "QDialog"
#include "QLineEdit"
#include "QMainWindow"
#include "projectstructurelist.h"
#include "QMessageBox"
#include "contextedit.h"
#include "../ControllerObservable/ControllerObservable.h"

class InputName : public QDialog {
    Q_OBJECT
public:
    InputName( QWidget* parent = nullptr );
    ~InputName() {}
    QString getInput() const {return m_edit->text();}
signals:
    void applied();
private:
    QLineEdit* m_edit;
};

class removeRelated : public QMessageBox {
    Q_OBJECT
public:
    removeRelated( QWidget* parent = nullptr );
    ~removeRelated() {}
signals:
    void applied();
private:
    QPushButton* YESButton;
    QPushButton* NOButton;
};

enum ObjectType {
    POINT=0,
    LINE=1,
    NOTHING=2
};

struct qp //структура для хранения координаты при рисовании
{
    QPoint pos;
    QPoint endpos;
    ObjectType objType;
    QColor qpColor;
    QString qpName;
    bool needsProjection;
    int planeNumber;
    int fl;
};

class Canvas : public QWidget
{
    Q_OBJECT
public:
    void clear();
    explicit Canvas(QWidget* parent = nullptr,QMainWindow* _parent=nullptr, ProjectStructureList* _projectStructureList=nullptr, ControllerObservable* controllerObservable= nullptr);
    void prepareCanvas ();
    int condition; //0=dead 1=point 2=line
    void addPoint (int x, int y, QString name);
    void addLine (int x1, int y1, int x2, int y2, QString name);
private:
    ControllerObservable* controllerObservable;
    LineContextEdit lineRMB;
    PointContextEdit pointRMB;
    QMainWindow* parentWindow;
    int findInVcp (int x, int y);
    void paintEvent(QPaintEvent *event);
    QPoint pos; //координаты точки для рисования
    void mouseMoveEvent(QMouseEvent *event);
    removeRelated rRelated;
    QVector<qp> vcp; //массив (вектор) для хранения рисунка
    QVector<qp> help; //массив (вектор) для хранения рисунка
    QVector<qp> xMatch; //массив (вектор) для хранения рисунка
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    int f;
    bool blocked=false;
    ObjectType selected;
    QPainter p;
    QPen pen;
    int xBlocked;
    int yBlocked;
    ProjectStructureList* projectStructureList;
signals:
};

#endif // CANVAS_H
