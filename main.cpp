#include "ByteConverterDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ByteConverterDialog mainDialog;
    mainDialog.show();

    return a.exec();
}
