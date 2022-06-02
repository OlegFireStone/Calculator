#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//.............
//Кнопки
private slots:
    void digits_numbers();//123
    void on_pushButton_dot_clicked();//123
    void oparations();
    void on_pushButton_AC_clicked();
    void on_pushButton_equals_clicked();
    void math_operations();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
