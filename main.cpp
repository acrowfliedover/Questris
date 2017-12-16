//I don't have as much time as I expected on this project...
//So I would just create some functions that would be used in the project...
//which I may complete during winter break.
#include "blocks.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Grid G;
    Mino_I I;
    G.move_left(I);
    QApplication a(argc, argv);
    blocks w;
    w.show();

    return a.exec();
}
