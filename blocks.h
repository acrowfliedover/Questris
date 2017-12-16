//I don't have as much time as I expected on this project...
//So I would just create some functions that would be used in the project...
//which I may complete during winter break.
#ifndef BLOCKS_H
#define BLOCKS_H

#include <QMainWindow>

class blocks : public QMainWindow
{
    Q_OBJECT

public:
    blocks(QWidget *parent = 0);
    ~blocks();
};
class Cell{
private:
    bool full;
public:
    Cell(){full=false;}
    void fill(){full=true;}
    void clear(){full=false;}

    friend class Line;
};


class Line{
private:
    Cell cells[10];

public:
    bool check_full(){
        for (int i=0; i<10;++i){
            if (!(cells[i].full))
                return false;
        }
        return true;
    }
    friend class Grid;
};

class Mino{
protected:
    Cell space[4][4];
public:
    /*Mino(Mino_I &MinoI){
    for (int i=0; i<4; ++i){
        for (int j=0; j<4; ++j){
            space[i][j]=MinoI[i][j];
            }
        }
    }*/
    void rotate_left();
    void rotate_right();

};

class Mino_I: public Mino{
public:
    Mino_I(){
        for (int i=0; i<4; ++i){
            space[i][3].fill();
        }
    }
    void rotate_left();
    void rotate_right();
};

class Mino_S{
public:
    Mino_S();
    void rotate_left();
    void rotate_right();
};

class Mino_L{
public:
    Mino_L();
    void rotate_left();
    void rotate_right();
};

class Mino_T{
public:
    Mino_T();
    void rotate_left();
    void rotate_right();
};

class Mino_O{
public:
    Mino_O();
    void rotate_left();
    void rotate_right();
};

class Mino_J{
public:
    Mino_J();
    void rotate_left();
    void rotate_right();
};

class Mino_Z{
public:
    Mino_Z();
    void rotate_left();
    void rotate_right();
};

class Grid{
private:
    Line lines[20];
public:
    void line_clear(int);
    virtual void move_left(Mino M);
    void move_right(Mino M);
    void move_down(Mino M);

};

#endif // BLOCKS_H
