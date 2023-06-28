#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    маска #  дозволяє цифри і знаки +, -
//    ui->lineEdit->setInputMask("#");
    QRegularExpression rx("^(-?)[0-9]{1,7}([\.][0-9]{1,2})?$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString temp = ui->lineEdit->text();
    QRegularExpressionMatch obj = regular.match(temp);
    if (obj.hasMatch()) {
        ui->lineEdit_2->setText("Допустимі дані");
//        qDebug("Число");
    }
    else {
        ui->lineEdit_2->setText("Недопустимі дані");
//        qDebug("Не число");
    }
}

void MainWindow::on_pushButton_plus_clicked() {
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input + "+");
    operation = 1;
    operand1 = input.toDouble();
    output = input + "+";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_minus_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input + "-");
    operation = 2;
    operand1 = input.toDouble();
    output = input + "-";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}



void MainWindow::on_pushButton_multiply_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input + "*");
    operation = 3;
    operand1 = input.toDouble();
    output = input + "*";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_divide_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input + "/");
    operation = 4;
    operand1 = input.toDouble();
    output = input + "/";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_modulo_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input + "%");
    operation = 5;
    operand1 = input.toDouble();
    output = input + "%";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

QString MainWindow::decimalToBinary(double decimalNumber)
{
    int integerValue = static_cast<int>(decimalNumber);
    QString binary = QString::number(integerValue, 2);

    double fractionalPart = decimalNumber - integerValue;
    if (fractionalPart > 0) {
        binary += ".";
        const int maxFractionalDigits = 20;
        int numFractionalDigits = 0;

        while (fractionalPart > 0 && numFractionalDigits < maxFractionalDigits) {
            fractionalPart *= 2;
            int bit = static_cast<int>(fractionalPart);
            binary += QString::number(bit);
            fractionalPart -= bit;
            numFractionalDigits++;
        }
    }

    return binary;
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_binary_clicked()
{
    QString resultText = ui->lineEdit_2->text();
    int equalsIndex = resultText.indexOf('=');
    if (equalsIndex != -1) {
        QString resultValue = resultText.mid(equalsIndex + 1).trimmed();
        bool ok;
        double decimalNumber = resultValue.toDouble(&ok);
        if (ok && result > 0) {
            QString binaryNumber = decimalToBinary(decimalNumber);
            ui->lineEdit_2->setText(resultText + " (" + binaryNumber + ")");
        }
    }
}

void MainWindow::on_pushButton_equals_clicked() {
    input = ui->lineEdit->text();
    operand2 = input.toDouble();
    output+=input;
    ui->lineEdit_2->setText(output);
    switch (operation) {
        case 1: {
            result = operand1 + operand2;
            break;
        }
        case 2: {
            result = operand1 - operand2;
            break;
        }
        case 3: {
            result = operand1 * operand2;
            break;
        }
        case 4: {
            result = operand1 / operand2;
            break;
        }
        case 5: {
            result = static_cast<int>(operand1) % static_cast<int>(operand2);
            break;
        }
        default:
            break;
    }
    output+="="+QString::number(result);
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText(QString::number(result));
    output=input="";
}

