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
// нопки
private slots:
    void digits_numbers();//Ётот слот будет вызыватьс€ при нажатии на любую кнопку от 0 до 9
    void on_pushButton_dot_clicked();
    void oparations();
    void on_pushButton_AC_clicked();//AC
    void on_pushButton_equals_clicked();
    void math_operations();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
