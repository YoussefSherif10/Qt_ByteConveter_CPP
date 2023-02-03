#include "ByteConverterDialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>

ByteConverterDialog::ByteConverterDialog(){
    // generate the needed layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
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
}

/* always start with the outer layout then goes to inner layers
   by creating, the GUI elements using QObject and allocating them in the heap, Qt takes care of memory releasing if one or more element is
   deleted. the memory it occupies will be released and all its children will be deleted as well.
*/
