#include "gra.h"

#include <QApplication>

    Gra *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new Gra;
    w->showFullScreen();
    w->displaymenu();
    return a.exec();
}
