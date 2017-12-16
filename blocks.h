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
private:
    char type;
    Cell space[4][4];
public:
    mino(char);
    void rotate_left();
    void rotate_right();

};

class Mino_I: public Mino{
private:
    Cell I_space[4][4];
public:
    Mino_I(){
        for (int i=0; i<4; ++i){
            I_space[i][3].fill();
        }
    }
    void rotate_left();
    void rotate_right();
};

class Mino_S{
private:
    Cell S_space[4][4];
public:
    Mino_S();
    void rotate_left();
    void rotate_right();
};

class Mino_L{
private:
    Cell L_space[4][4];
public:
    Mino_L();
    void rotate_left();
    void rotate_right();
};

class Mino_T{
private:
    Cell T_space[4][4];
public:
    Mino_T();
    void rotate_left();
    void rotate_right();
};

class Mino_O{
private:
    Cell O_space[4][4];
public:
    Mino_O();
    void rotate_left();
    void rotate_right();
};

class Mino_J{
private:
    Cell J_space[4][4];
public:
    Mino_J();
    void rotate_left();
    void rotate_right();
};

class Mino_Z{
private:
    Cell Z_space[4][4];
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
    void move_left(Mino M);
    void move_right(Mino M);
    void move_down(Mino M);

};

#endif // BLOCKS_H
