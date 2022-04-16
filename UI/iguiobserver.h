#ifndef IGUIOBSERVER_H
#define IGUIOBSERVER_H

class IGUIObserver {
    virtual int onCreate () = 0;
    virtual int onChange () = 0;
    virtual int onDelete () = 0;
    virtual ~IGUIObserver();
};

class IGUIPointObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};

class IGUILineObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};

class IGUIPlaneObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};

class IGUIUserPointObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};


class IGUIUserLineObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};


class IGUIUserPlaneObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};

#endif // IGUIOBSERVER_H
