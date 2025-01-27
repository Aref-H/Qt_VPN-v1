#ifndef VPN_H
#define VPN_H

#include <QMainWindow>
#include <Qprocess>
//#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class VPN;
}
QT_END_NAMESPACE

class VPN : public QMainWindow
{
    Q_OBJECT

public:
    VPN(QWidget *parent = nullptr);
    ~VPN();

//**Another way to change main window background**
/*protected:
    void paintEvent(QPaintEvent *);*/

private:
    Ui::VPN *ui;

private slots:
    void buttonPressed();
};
#endif // VPN_H
