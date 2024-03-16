#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnabled();
}

Widget::~Widget()
{
    delete ui;

}


void Widget::changeMoney(int diff){

    money += diff;
    ui->lcdNumber->display(money);
    changeEnabled();

}

void Widget::changeEnabled(){
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);

}


void Widget::on_pbcoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbcoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbcoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbcoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int FH_coin = money / 500;
    money = money % 500;
    int OH_coin = money / 100;
    money = money % 100;
    int FT_coin = money / 50;
    money = money % 50;
    int TEN_coin = money / 10;

    QString msg;
    if(FH_coin){
        msg += QString("500won : ") + QString::number(FH_coin) + QString("\n");
    }
    if(OH_coin){
        msg += QString("100won : ") + QString::number(OH_coin) + QString("\n");
    }
    if(FT_coin){
        msg += QString("50won : ") + QString::number(FT_coin) + QString("\n");
    }
    if(TEN_coin){
        msg += QString("10won : ") + QString::number(TEN_coin) + QString("\n");
    }

    mb.information(nullptr,"title",msg);

    changeMoney(-money);
}

