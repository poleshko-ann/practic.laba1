#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <conio.h>
#include <QTextStream>
#include <QTextEdit>
#include <QFile>
#include "QString"
using namespace std;

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
    dialogWindow.setModal(true);
    dialogWindow.exec();


}
void MainWindow::on_pushButton_clicked()
{
    QList<QString> chislo = {"степень", "корень", "факториал"};
    QString firstBox = ui->comboBox->currentText();
    qreal chislo1=(ui->textEdit)->toPlainText().toDouble();
    string checkString = (ui->textEdit)->toPlainText().toStdString();
   if(chislo1 > 0){
        ui->label->setText("Степень, корень, факториал числа вычислены :)");
        if (firstBox == chislo.at(0)){
            ui->label->setText("Степень числа вычислена :)");
            chislo1 = pow(chislo1,chislo1);
            QString str = QString::number(chislo1);
            ui->textEdit_2->setText(str);
        }
        else if (firstBox == chislo.at(1)){
            ui->label->setText("Корень числа вычислен :)");
            chislo1 = sqrt(chislo1);
            QString str = QString::number(chislo1);
            ui->textEdit_2->setText(str);
        }
        else if (firstBox == chislo.at(2)){
            ui->label->setText("Факториал числа вычислен(от целой части) :)");
            int res=1;
            for (int i = 1; i <= chislo1; ++i) {
                res*=i;
            }
            getch();
            QString str = QString::number(res);
            ui->textEdit_2->setText(str);
        }
    }else{
       ui->label->setText("Степень, корень, факториал числа не вычислены :(");
        ui->textEdit_2->setText("недопустимость ввода данных");
    }
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked){ui->pushButton->setEnabled(true);}
    else{ui->pushButton->setEnabled(false);};
}


void MainWindow::on_pushButton_2_clicked()
{
    QFile file("in.txt");
    if(!file.exists())
    {
        ui->label->setText("Файл не существует");
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->label->setText("Файл не открывается");
    }
    QByteArray text = file.readLine();
    ui->textEdit->setText(text);

}


void MainWindow::on_pushButton_3_clicked()
{
    QFile fileOut("log.txt");
    if(!fileOut.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&fileOut);

    out << ui->textEdit_2->toPlainText();

    fileOut.close();
}

