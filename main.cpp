#include <QApplication>
#include <QPushButton>
#include "utility/utility.h"
#include "page/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qApp->setStyleSheet(loadStyle("../Resources/qss/app.qss"));

    MainWindow window;
    window.show();

    return QApplication::exec();
}