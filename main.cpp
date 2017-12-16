#include "blocks.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    blocks w;
    w.show();

    return a.exec();
}
