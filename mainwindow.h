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
//Êíîïêè
private slots
    void digits_numbers();//Ýòîò ñëîò áóäåò âûçûâàòüñÿ ïðè íàæàòèè íà ëþáóþ êíîïêó îò 0 äî 9
    void on_pushButton_dot_clicked();//òî÷êà
    void oparations();//îïåðàöèè
    void on_pushButton_AC_clicked();//AC(0)
    void on_pushButton_equals_clicked();//Ðàâíî
    void math_operations();//ìàòåìàòè÷åñêèå îïåðàöèè


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
