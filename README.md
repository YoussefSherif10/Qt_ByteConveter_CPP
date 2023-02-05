# Qt_ByteConveter_CPP

This dialogue box has a grid of labels, editable lines, and a cancel button. The three lines show a number in decimal, hexadecimal, and binary formats. the quit button is used to terminate the programme. 

the GUI is developed using the ByteConverterDialog that inherits from QDialog class. This class is in charge of producing the necessary layouts and validating user input by capping the values within a certain range. 

The ByteConverter class, which derives from the QObject class, implements the logic for altering the content of the three lines. The three lines are kept in sync by this class. 

Signal-slot connections are used for the two classes' communication.
