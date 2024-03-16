#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int diff);
    void changeEnabled();

private slots:
    void on_pbcoin10_clicked();

    void on_pbcoin100_clicked();

    void on_pbcoin500_clicked();

    void on_pbcoin50_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbTang_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
