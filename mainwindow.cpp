#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;//глобальна€ переменна€ дл€ хранени€ первого числа до операции.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//connect
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));//—оедин€ем кнопку(ui->pushButton_0) со слотом при нажатии на неЄ(SIGNAL(clicked())). –аботаем с this объектом
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(oparations()));//теперь символы
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(oparations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiplication, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(false);//setCheckable устанавливает true(false) дл€ объекта. ѕросто хранит bool как поле у объекта
    ui->pushButton_minus->setCheckable(false);
    ui->pushButton_division->setCheckable(false);
    ui->pushButton_multiplication->setCheckable(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//.........
// нопки
void MainWindow::digits_numbers()//от 0 до 9
{
   QPushButton *button = (QPushButton*) sender();//метод sender позвол€ет получить ту кнопку, на которую мы нажали
   QString new_label;
   double all_numbers;

   all_numbers = (ui->label_Result_Show->text() + button->text()).toDouble();// анкатенаци€ строк и преобразование в Double
   new_label = QString::number(all_numbers,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.
   ui->label_Result_Show->setText(new_label);

}


void MainWindow::on_pushButton_dot_clicked()//точка
{
    if(!ui->label_Result_Show->text().contains(".")){//contains провер€ет есть ли символ "." в label_Result_Show
        ui->label_Result_Show->setText(ui->label_Result_Show->text() + ".");
    }
}

void MainWindow::oparations()//знак плюс/минус и проценты
{
    QPushButton *button = (QPushButton*) sender();//метод sender позвол€ет получить ту кнопку, на которую мы нажали
    QString new_label;
    double all_numbers;

    if (button->text() == "+/-"){

      all_numbers = ui->label_Result_Show->text().toDouble();//преобразование в Double
      all_numbers = all_numbers * (-1);

      new_label = QString::number(all_numbers,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

      ui->label_Result_Show->setText(new_label);
    }

    else if (button->text() == "%"){

      all_numbers = ui->label_Result_Show->text().toDouble();//преобразование в Double
      all_numbers = all_numbers * 0.01;

      new_label = QString::number(all_numbers,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

      ui->label_Result_Show->setText(new_label);
    }
}

void MainWindow::math_operations()//ѕлюс, минус, умножить, деление
{
    if(!ui->label_Result_Show->text().contains(" ")){
      QPushButton *button = (QPushButton*) sender();

      num_first = ui->label_Result_Show->text().toDouble();
      ui->label_Result_Show->setText(" ");
      qDebug()<<num_first;//??????

      button->setCheckable(true);
    }
}

void MainWindow::on_pushButton_AC_clicked()//AC
{

    ui->label_Result_Show->setText("0");
    num_first = 0;

}

void MainWindow::on_pushButton_equals_clicked()//равно
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label_Result_Show->text().toDouble();

    if(ui->pushButton_plus->isCheckable()){

        labelNumber = num_first + num_second;
        qDebug()<< labelNumber;//??????
        new_label = QString::number(labelNumber,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

        ui->label_Result_Show->setText(new_label);
        ui->pushButton_plus->setCheckable(false);
    }

    else if(ui->pushButton_minus->isCheckable()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

        ui->label_Result_Show->setText(new_label);
        ui->pushButton_minus->setCheckable(false);
    }

    else if(ui->pushButton_multiplication->isCheckable()){
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

        ui->label_Result_Show->setText(new_label);
        ui->pushButton_multiplication->setCheckable(false);
    }

    else if(ui->pushButton_division->isCheckable()){
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber,'g',15);//преобразуем число в строку, где число записываетс€ вплоть до 10 в 15 степени.

        ui->label_Result_Show->setText(new_label);
        ui->pushButton_division->setCheckable(false);
    }
}




