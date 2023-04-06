#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void digit_pressed();
    void on_pushButton_dot_released();
    void unary_operation_pressed();
    void on_pushButton_CLR_released();
    void on_pushButton_equal_released();
    void math_operations_released();
};
#endif // CALCULATOR_H
