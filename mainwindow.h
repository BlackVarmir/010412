#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
//#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_modulo_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_equals_clicked();
    void on_lineEdit_returnPressed();
    void on_pushButton_binary_clicked();
    QString decimalToBinary(double decimalNumber);

private:
    Ui::MainWindow *ui;
    QString input, output;
    double operand1, operand2, result;
    int operation;
    QString r = "^(-?)[1-9][0-9]{1,7}([\.][0-9]{1,2})?$";
//    QString r = "^[^a-zA-Z~!@#$%\^&\*\(\)\+/=:;'\?\[\]\{\}]{1,7}([,\.][0-9]{1,3})?$";
//    QString r = "^-?[0-9]{1,7}([,\.][0-9]{1,3})?[\+\*\-\/%]?$";
    QRegularExpression regular = QRegularExpression(r);
};
#endif // MAINWINDOW_H
