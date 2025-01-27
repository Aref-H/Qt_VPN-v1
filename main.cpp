#include "vpn.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VPN w;
    w.show();
    return a.exec();
}
