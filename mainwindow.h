#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int numOfOperation = 1;
    double op1;
    double op2;
    int oneLineOperations[5] = {5, 6, 7, 8, 9};

private slots:
    bool checkVar(double var, bool flag);

    void showAll();

    void hideOp();

    void on_pushButton_sum_clicked();

    void on_pushButton_clear_clicked();

    void on_radioButton_addition_clicked();

    void on_radioButton_multiplication_clicked();

    void on_radioButton_substraction_clicked();

    void on_radioButton_division_clicked();

    void on_radioButton_sqrt_clicked();

    void on_radioButton_sin_clicked();

    void on_radioButton_cos_clicked();

    void on_radioButton_arcsin_clicked();

    void on_radioButton_arccos_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
