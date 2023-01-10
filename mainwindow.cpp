#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_answer->clear();
    ui->label_error->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//функция проверяет переменную по полной
bool MainWindow::checkVar(double var, bool flag = true)
{
    if (flag)
    {
        if(!qIsInf(var) && !qIsNaN(var))
            return true;
    }
    return false;
}

// показывает все операнды
void MainWindow::showAll()
{
    ui->label_answer->clear();
    ui->label_error->clear();
    ui->lineEdit_op2->setVisible(true);
    ui->label_op2->setVisible(true);
}

// прячет 2 операнд
void MainWindow::hideOp()
{
    ui->label_answer->clear();
    ui->label_error->clear();
    ui->lineEdit_op2->setVisible(false);
    ui->label_op2->setVisible(false);
    ui->label_op1->setText("Аргумент");
    ui->pushButton_sum->setText("Результат");
}


void MainWindow::on_pushButton_sum_clicked()
{
    // очищаем от предыдущего результата
    ui->label_error->clear();
    ui->label_answer->clear();

    // устанавливаем значение и проверяем операнды
    bool flag;
    op1 = ui->lineEdit_op1->text().toDouble(&flag);
    if (!checkVar(op1, flag))
    {
        ui->label_error->setText("Операнд 1 - неверный");
        return;
    }

    op2 = ui->lineEdit_op2->text().toDouble(&flag);

    // проверяем активирован ли режим hideOp, если да, то устанавливаем значение 0
    for (int i = 0; i < (sizeof(oneLineOperations) / sizeof(oneLineOperations[0])); ++i) {
        if (oneLineOperations[i] == numOfOperation)
        {
            op2 = 0;
            flag = true;
            break;
        }
    }
    if (!checkVar(op2, flag))
    {
        ui->label_error->setText("Операнд 2 - неверный");
        return;
    }

    // определение операции и вычисление
    double answer;
    switch (numOfOperation) {
    // Сложение
    case 1:
        answer = op1 + op2;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // Вычитание
    case 2:
        answer = op1 - op2;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // Умножение
    case 3:
        answer = op1 * op2;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // Деление
    case 4:
        answer = op1 / op2;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // Корень
    case 5:
        if (op1 < 0)
        {
            ui->label_error->setText("Число меньше 0");
            return;
        }
        answer = sqrt(op1);
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // sin()
    case 6:
        answer = round(sin(op1 / 180 * M_PI) * 10000) / 10000;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // cos()
    case 7:
        answer =  round(cos(op1 / 180 * M_PI) * 10000) / 10000;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // arcsin()
    case 8:
        if (op1 > 1 || op1 < -1)
        {
            ui->label_error->setText("Число должно быть от -1 до 1");
            return;
        }
        answer = asin(op1) * 180 / M_PI;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    // arccos()
    case 9:
        if (op1 > 1 || op1 < -1)
        {
            ui->label_error->setText("Число должно быть от -1 до 1");
            return;
        }
        answer = acos(op1) * 180 / M_PI;
        if (!checkVar(answer))
        {
            ui->label_error->setText("Ошибка при подсчете");
            return;
        }
        ui->label_answer->setNum(answer);
        break;

    }

}

// функция полностью очищает все введенные данные и результат их работы
void MainWindow::on_pushButton_clear_clicked()
{

    ui->lineEdit_op1->clear();
    ui->lineEdit_op2->clear();
    ui->label_error->clear();
    ui->label_answer->clear();
}

// Сложение
void MainWindow::on_radioButton_addition_clicked()
{
    showAll();
    ui->label_op1->setText("Слагаемое 1");
    ui->label_op2->setText("Слагаемое 2");
    ui->pushButton_sum->setText("Сумма");
    numOfOperation = 1;
}


// Вычитание
void MainWindow::on_radioButton_substraction_clicked()
{
    showAll();
    ui->label_op1->setText("Уменьшаемое");
    ui->label_op2->setText("Вычитаемое");
    ui->pushButton_sum->setText("Разность");
    numOfOperation = 2;
}

// Умножение
void MainWindow::on_radioButton_multiplication_clicked()
{
    showAll();
    ui->label_op1->setText("1-ый множитель");
    ui->label_op2->setText("2-ой множитель");
    ui->pushButton_sum->setText("Произвдение");
    numOfOperation = 3;
}

// Деление
void MainWindow::on_radioButton_division_clicked()
{
    showAll();
    ui->label_op1->setText("Делимое");
    ui->label_op2->setText("Делитель");
    ui->pushButton_sum->setText("Частное");
    numOfOperation = 4;
}

// Корень
void MainWindow::on_radioButton_sqrt_clicked()
{
    hideOp();
    numOfOperation = 5;
}

// sin()
void MainWindow::on_radioButton_sin_clicked()
{
    hideOp();
    numOfOperation = 6;
}

// cos()
void MainWindow::on_radioButton_cos_clicked()
{
    hideOp();
    numOfOperation = 7;
}

// arcsin()
void MainWindow::on_radioButton_arcsin_clicked()
{
    hideOp();
    numOfOperation = 8;
}

// arccos()
void MainWindow::on_radioButton_arccos_clicked()
{
    hideOp();
    numOfOperation = 9;
}
