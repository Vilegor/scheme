#include <QtGui/QApplication>
#include "mainwindow.h"
#include "DialogWindows/changeparameter.h"
#include "Elements/resistance.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//   ChangeParameter *_test = new ChangeParameter();
//    _test->show();
//    QImage *_image = new QImage("C:\\Users\\i_r\\Documents\\scheme\\Resources\\resistor.jpg");

    return a.exec();
}
