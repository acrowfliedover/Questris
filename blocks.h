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
    Mino(){
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j)
                space[i][j]=false;
        }
    }
    void rotate_left(){//first ignore edge cases
        Mino M;
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j)
                M[i][j]=space[3-j][i];
                }
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j)
                space[i][j]=M[i][j];
                }
    }
    void rotate_right(){
        Mino M;
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j)
                M[i][j]=space[j][3-i];
        }
        for (int i=0; i<4; ++i){
            for (int j=0; j<4; ++j)
                space[i][j]=M[i][j];
        }
    }

};

class Mino_I: public Mino{
public:
    Mino_I(){
        for (int i=0; i<4; ++i){
            space[i][2].fill();
        }
    }
};

class Mino_S: public Mino{ //not optimal for rotations
public:
    Mino_S(){
        space[0][1].fill();
        space[1][1].fill();
        space[1][2].fill();
        space[2][2].fill();
    }
};

class Mino_L: public Mino{//not optimal for rotations
public:
    Mino_L(){
        space[0][1].fill();
        space[1][1].fill();
        space[2][1].fill();
        space[2][2].fill();
    }
};

class Mino_T: public Mino{ //not optimal for rotations
public:
    Mino_T(){
        space[0][1].fill();
        space[1][1].fill();
        space[2][1].fill();
        space[1][2].fill();
    }
};

class Mino_O: public Mino{
public:
    Mino_O(){
        space[1][1].fill();
        space[2][1].fill();
        space[1][2].fill();
        space[2][2].fill();
    }

};

class Mino_J: public Mino{ //not optimal for rotations
public:
    Mino_J(){
        space[0][1].fill();
        space[0][1].fill();
        space[0][1].fill();
        space[0][1].fill();
    }

};

class Mino_Z: public Mino{ //not optimal for rotations
public:
    Mino_Z(){
        space[1][1].fill();
        space[2][1].fill();
        space[0][2].fill();
        space[1][2].fill();
    }

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
