#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if(!file.isEmpty())
    {
        mFilename = file;
        QFile sFile(file);
        if(sFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionDelete_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.deleteChar();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files(*.txt);;All Files(*)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, QString("Warning"), QString("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files(*.txt);;All Files(*)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, QString("Warning"), QString("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_actionWord_Wrap_triggered()
{
    bool wordWrapEnabled = ui->textEdit->wordWrapMode() == QTextOption::WrapAtWordBoundaryOrAnywhere;
    ui->textEdit->setWordWrapMode(wordWrapEnabled ? QTextOption::NoWrap : QTextOption::WrapAtWordBoundaryOrAnywhere);
}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->actionBold->isChecked() ? QFont::Bold : QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionSuper_script_triggered()
{
    QTextCharFormat fmt;
    fmt.setVerticalAlignment(ui->actionSuper_script->isChecked() ? QTextCharFormat::AlignSuperScript : QTextCharFormat::AlignNormal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}



void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat fmt;
    fmt.setVerticalAlignment(ui->actionSubscript->isChecked() ? QTextCharFormat::AlignSubScript : QTextCharFormat::AlignNormal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

