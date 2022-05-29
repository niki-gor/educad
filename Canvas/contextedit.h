#ifndef CONTEXTEDIT_H
#define CONTEXTEDIT_H

#include <QPushButton>
#include <QTextEdit>

class ConnectedToPlaneContextEdit : public QTextEdit {
Q_OBJECT;
public:
    ConnectedToPlaneContextEdit();
    QMenu* connectedToPlaneContextEditWidget;
private slots:
    void handleProjectOnPlaneButton();
};

class UnprojectedPointContextEdit : public QTextEdit {
    Q_OBJECT;
public:
    UnprojectedPointContextEdit();
    QMenu* unprojectedObjectContextEditWidget;
private slots:
    void handleConnectToPlaneButton();
};


class DontProjectObjectContextEdit : public QTextEdit {
    Q_OBJECT;
public:
    DontProjectObjectContextEdit();
    QMenu* unfinishedPointContextEditWidget;
private slots:
    void handleDontProjectButon();
};

class TwoPointsContextEdit : public QTextEdit {
    Q_OBJECT
private:
    QPushButton lineByTwoPoints;
public:
    TwoPointsContextEdit();
    QMenu* twoPointsContextEditWidget;
private slots:
    void handleLineByTwoPointsButton ();
};

class PointAndLineContextEdit : public QTextEdit {
    Q_OBJECT
private:
    QPushButton lineByTwoPoints;
public:
    PointAndLineContextEdit();
    QMenu* pointAndLineContextEditWidget;
private slots:
    void handleMakeStraightLine ();
    void handlePerpendicularFromPointToLineButton();
    void handleParallelLineThroughPointButton ();
    void handlePlaneThroughLineAndPointButton ();
};

class ContextEdit : public QTextEdit {
protected:
    QPushButton projectOnPlaneButton;
    QPushButton drawPerpendicularButton;
    QPushButton renameButton;
    QPushButton getDistanceButton;
    QPushButton resizeButton;
    QPushButton deleteButton;
    QPushButton cutButton;
    QPushButton copyButton;
public:
    QMenu* contextEditWidget;
    virtual void handleProjectOnPlaneButton () = 0;
    virtual void handleDrawPerpendicularButton () = 0;
    virtual void handleRenameButton () = 0;
    virtual void handleGetDistanceButton () = 0;
    virtual void handleResizeButton () = 0;
    virtual void handleDeleteButton () = 0;
    virtual void handeCutButton () = 0;
    virtual void handleCopyButton () = 0;
    virtual ~ContextEdit() {}
};



class LineContextEdit : public ContextEdit {
protected:
    QPushButton realSizeButton;
    QPushButton buildIntersectionButton;
    QPushButton buildParallelLineButton;
public:
    virtual void handleProjectOnPlaneButton () ;
    virtual void handleDrawPerpendicularButton () ;
    virtual void handleRenameButton () ;
    virtual void handleGetDistanceButton ();
    virtual void handleResizeButton () ;
    virtual void handleDeleteButton () ;
    virtual void handeCutButton ();
    virtual void handleCopyButton ();
    LineContextEdit ();
    void handleRealSizeButton ();
    void handlebuildIntersectionButton();
    void handleBuildParallelLineButton();
    virtual ~LineContextEdit() {}
};

class PointContextEdit : public ContextEdit {
public:
    virtual void handleProjectOnPlaneButton () ;
    virtual void handleDrawPerpendicularButton () ;
    virtual void handleRenameButton () ;
    virtual void handleGetDistanceButton ();
    virtual void handleResizeButton () ;
    virtual void handleDeleteButton () ;
    virtual void handeCutButton ();
    virtual void handleCopyButton ();
    PointContextEdit();
    virtual ~PointContextEdit () {}
};

#endif // CONTEXTEDIT_H
