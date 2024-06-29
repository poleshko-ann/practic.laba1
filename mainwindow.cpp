#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QApplication::quit();
}

//надо написать
void MainWindow::on_pushButton_clicked()
{
    qreal fact;
    ui->label->setText("Степень, корень, факториал числа вычислены :)");
    qreal val1=(ui->textEdit)->toPlainText().toDouble();
    if(val1<=0){ ui->textEdit_2->setText("недопустимость ввода данных");
    }
    //QString val2=(ui->comboBox)->toPlainText().toDouble();
    //if( val2 = "степень"){ ui->textEdit_2->setText(QString::number(val1));}

   // else{ui->textEdit_2->setText(QString::number(val1));}

}

