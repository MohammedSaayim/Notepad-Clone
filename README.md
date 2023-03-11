# Notepad-Clone
I have developed a simple notepad application using the Qt framework. The application allows users to create, open, edit, and save plain text files.

## Features
File menu options to create new files, open existing files, and save files.
Edit menu options to cut, copy, paste, and undo text.
View menu option to toggle word wrap on/off.
The status bar shows the current cursor position, line number, and column number.
The application uses a standard font and font size for consistency.

## Implementation
The application is implemented mainly using the QPlainTextEdit widget and QTextDocument class. The QPlainTextEdit widget is used as the view to display and edit the text. The QTextDocument class is used as the model to represent the text data. The controller is implemented using slots and signals to handle user input and update the view and model accordingly.

The application uses the QFileDialog class to allow users to select files to open or save. The QMessageBox class is used to display error messages if there are any issues with file operations.

Overall, the notepad application is a simple yet functional text editor with basic features for everyday use.
