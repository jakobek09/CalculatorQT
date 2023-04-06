#include "calculator.h"
#include "ui_calculator.h"

double firstNum;
bool userSec = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(math_operations_released()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(math_operations_released()));
    connect(ui->pushButton_devide,SIGNAL(released()),this,SLOT(math_operations_released()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(math_operations_released()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_devide->isChecked() || ui->pushButton_multiply->isChecked()) && (!userSec))
    {
        labelNumber = button->text().toDouble();
        userSec = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == '0')
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }
    ui->label->setText(newLabel);
}

void Calculator::on_pushButton_dot_released()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}

void Calculator::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}


void Calculator::on_pushButton_CLR_released()
{
    ui->label->setText("0");
}


void Calculator::on_pushButton_equal_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
        ui->label2->setText("");
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
        ui->label2->setText("");
    }
    else if(ui->pushButton_devide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_devide->setChecked(false);
        ui->label2->setText("");
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
        ui->label2->setText("");
    }

    userSec = false;
}

void Calculator::math_operations_released()
{
    QPushButton * button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        ui->pushButton_plus->setChecked(false);
        button->setChecked(true);
        ui->label2->setText(ui->label->text() + " " + button->text());
    }
    if(ui->pushButton_minus->isChecked())
    {
        ui->pushButton_minus->setChecked(false);
        button->setChecked(true);
        ui->label2->setText(button->text());
        ui->label2->setText(ui->label->text() + " " + button->text());
    }
    if(ui->pushButton_devide->isChecked())
    {
        ui->pushButton_devide->setChecked(false);
        button->setChecked(true);
        ui->label2->setText(button->text());
        ui->label2->setText(ui->label->text() + " " + button->text());
    }
    if(ui->pushButton_multiply->isChecked())
    {
        ui->pushButton_multiply->setChecked(false);
        button->setChecked(true);
        ui->label2->setText(button->text());
        ui->label2->setText(ui->label->text() + " " + button->text());
    }


}
