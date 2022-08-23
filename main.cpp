#include "Headers/mcts_hex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MCTS_HEX w;
    w.show();
    return a.exec();
}
