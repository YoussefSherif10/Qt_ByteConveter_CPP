#include "ByteConverterDialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QLineEdit>

ByteConverterDialog::ByteConverterDialog(){
    /**
     *  this constructor generates the widgets for the dialog and set up the object hierarchy.
     *  retsricts the user input to a specific range
     *  make the signal/slot connections
     */

    // generate the needed layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);    // making this dialog as the main layout
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();   // stretches occupy the uneeded spaces by the components. so, it creates spaces
    mainLayout->addLayout(buttonLayout);

    // initialize the private members with the edit lines
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    // generate the labels
    QLabel *decLabel = new QLabel(tr("Decimal"));
    QLabel *hexLabel = new QLabel(tr("Hex"));
    QLabel *binLabel = new QLabel(tr("Binary"));

    // add labels and edit lines to the grid
    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);

    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);

    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    // generate the button and it to its layout
    QPushButton *quitButton = new QPushButton(tr("Quit"));
    buttonLayout->addStretch(); // to make the button appear on the right
    buttonLayout->addWidget(quitButton);

    //------------------------------------------------------------ More Improvements ------------------------------------------------

    // making the quit button, the default one means it is pressed by hitting "enter" key.
    // setting default button only has an effect if the button in a dialog
    // it doesn't work if this is defined in the main window
    quitButton->setDefault(true);

    /* validators are derived from the QValidator class. it takes input from the user and decide its validity. */
    // limit the decimal values from 0 to 255 max.
    QIntValidator *decValidator = new QIntValidator(0, 255, decEdit);
    decEdit->setValidator(decValidator);

    // limit the hex to two digits only
    QRegularExpressionValidator *hexValidator = new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"), hexEdit);
    hexEdit->setValidator(hexValidator);

    // limit binary to 8 digits
    QRegularExpressionValidator *binValidator = new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"), binEdit);
    binEdit->setValidator(binValidator);

    // since, Qwidget is a base class then, we can call the setWindowTitle method.
    setWindowTitle(tr("Byte Converter"));

    // adding the slot for the quit button to exit the dialog when clicked.
    // accept method simply exit the dialog. rejec method also exits a dialog. this is a convension as each dialog
    // is expected to have OK and Cancel buttons.
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(accept()));

    //------------------------------------------------------ connections--------------------------------------------------------
    connect(decEdit, SIGNAL(textChanged(const QString&)), this, SLOT(decChanged(const QString&)));
    connect(hexEdit, SIGNAL(textChanged(const QString&)), this, SLOT(hexChanged(const QString&)));
    connect(binEdit, SIGNAL(textChanged(const QString&)), this, SLOT(binChanged(const QString&)));
}

/* always start with the outer layout then goes to inner layers
   by creating, the GUI elements using QObject and allocating them in the heap, Qt takes care of memory releasing if one or more element is
   deleted. the memory it occupies will be released and all its children will be deleted as well.
*/

void ByteConverterDialog::decChanged(const QString & newValue){
    /**
     * @brief convertable
     * params: a reference to a string that is given to input line (QString object)
     * return: nothing
     * description: it takes a signal textChanged from edit line and match the content of the other lines with it
     * so, that the content in all lines are the same number.
     */
    bool convertable = false;
    int num = newValue.toInt(&convertable);

    if(convertable){
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    }
    else {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

void ByteConverterDialog::binChanged(const QString & newValue){
    /**
     * @brief convertable
     * params: a reference to a string that is given to input line (QString object)
     * return: nothing
     * description: it takes a signal textChanged from edit line and match the content of the other lines with it
     * so, that the content in all lines are the same number.
     */
    bool convertable = false;
    int num = newValue.toInt(&convertable);

    if(convertable){
        decEdit->setText(QString::number(num, 10));
        hexEdit->setText(QString::number(num, 16));
    }
    else {
        hexEdit->setText("");
        decEdit->setText("");
    }
}

void ByteConverterDialog::hexChanged(const QString & newValue){
    /**
     * @brief convertable
     * params: a reference to a string that is given to input line (QString object)
     * return: nothing
     * description: it takes a signal textChanged from edit line and match the content of the other lines with it
     * so, that the content in all lines are the same number.
     */
    bool convertable = false;
    int num = newValue.toInt(&convertable);

    if(convertable){
        decEdit->setText(QString::number(num, 10));
        binEdit->setText(QString::number(num, 2));
    }
    else {
        decEdit->setText("");
        binEdit->setText("");
    }
}
