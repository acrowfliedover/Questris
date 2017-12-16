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
class Cell{ //some graphic unit
private:
    bool full;
    friend class Line; //I may add colors to the cells, which is the point of the cell
    friend class Grid;
    friend class Mino;
};

class Line{
private:
    Cell cells[10];

public:
    void clear();
    friend class Grid;
};

class Grid{
private:
    Line lines[20];
public:
    void line_clear(int);
    void move_left(Mino);
    void move_right(Mino);
    void move_down(Mino);

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

class Mino_I{
private:
    Cell I_space[4][4];
public:
    Mino_I();
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
}



#endif // BLOCKS_H
