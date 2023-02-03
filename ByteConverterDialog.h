#ifndef BYTECONVERTERDIALOG_H
#define BYTECONVERTERDIALOG_H

#include <QDialog>
class QLineEdit;    // forward declaration

class ByteConverterDialog : public QDialog {
    /* that macro should be declared in every derived class of QObject base class as it defines functions for the signal/slot concept
    NOTE: if that macro is missing nor the compiler neither the linker complains instead the connections won't work in the runtime  */
    Q_OBJECT

public:
    ByteConverterDialog();

private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;
};

#endif // BYTECONVERTERDIALOG_H
