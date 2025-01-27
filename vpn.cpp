#include "vpn.h"
#include "ui_vpn.h"

//Files addresse
QString defaultBat = "E:/Project/New/Qt/Project3-Qt_VPN/Qt_VPN/Netsh/Default.bat";
QString shecanBat = "E:/Project/New/Qt/Project3-Qt_VPN/Qt_VPN/Netsh/Shecan.bat";

//Boolian to save state of vpn
static bool isOnOff = false;

VPN::VPN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VPN)
{
    ui->setupUi(this);

    //Default style sheeting part
    if(isOnOff == false) {
        this->setStyleSheet
            ("QMainWindow {border-image: url(:/imgs/Backgrounds/Off.jpg);}");

        ui->vOnOff->setStyleSheet
            ("QPushButton {"
                "image: url(:/imgs/Icons/Off.png);"
                "background-color: #ffffff;"
                "border-radius: 65px;"
             "}"
             "QPushButton:pressed {"
                "background-color: #00FFFF;"
                "border: 15px solid gray;"
                "border-radius: 65px;"
             "}");
    }

    connect(ui->vOnOff, SIGNAL(released()), this, SLOT(buttonPressed()));
}

VPN::~VPN()
{
    delete ui;
}

//Function that is linked to push button
void VPN::buttonPressed() {
    if(isOnOff == true) {
        isOnOff = false;
        //Style sheeting
        this->setStyleSheet
            ("QMainWindow {border-image: url(:/imgs/Backgrounds/Off.jpg);}");
        ui->vOnOff->setStyleSheet
            ("QPushButton {"
                "image: url(:/imgs/Icons/Off.png);"
                "background-color: #ffffff;"
                "border-radius: 65px;"
             "}"
                "QPushButton:pressed {"
                "background-color: #00FFFF;"
                "border: 15px solid gray;"
                "border-radius: 65px;"
             "}");

        //Making QProcess object
        QProcess process;
        //Starting the process
        process.start(defaultBat);
        //Error handeling part
        if(!process.waitForStarted()) {
            qDebug() << "Faild to start the process.";
        }
        if(!process.waitForFinished()) {
            qDebug() << "Faild to finish the process.";
        }
        //Read output from .bat file
        QString output = process.readAll();
        qDebug() << "Process output:" << output;

    } else {
        isOnOff = true;
        this->setStyleSheet
            ("QMainWindow {border-image: url(:/imgs/Backgrounds/On.jpg);}");
        ui->vOnOff->setStyleSheet
            ("QPushButton {"
                "image: url(:/imgs/Icons/On.png);"
                "background-color: #ffffff;"
                "border-radius: 65px;"
             "}"
                "QPushButton:pressed {"
                "background-color: #00FFFF;"
                "border: 15px solid gray;"
                "border-radius: 65px;"
             "}");

        //Same as above
        QProcess process;
        process.start(shecanBat);
        if(!process.waitForStarted()) {
            qDebug() << "Faild to start the process.";
        }
        if(!process.waitForFinished()) {
            qDebug() << "Faild to finish the process.";
        }
        QString output = process.readAll();
        qDebug() << "process output:" << output;
    }
}

//**Another way to change main window background**
/*void VPN::paintEvent(QPaintEvent *) {
    QPixmap pixmap(":/imgs/Backgrounds/Off.jpg");
    QPainter paint(this);
    pixmap = pixmap.scaled(this->size()
    , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    paint.drawPixmap(0, 0,pixmap);
}*/
