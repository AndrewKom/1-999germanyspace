#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMap>
#include <QList>
#include <QMessageBox>
#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int count=0;
    int count2=0;
    int final=0;
    QMap<QString,int> one = {

        {"eins",1},
        {"ein",1},
        {"zwei", 2},
        {"drei",3},
        {"vier", 4},
        {"fünf",5},
        {"sechs", 6},
        {"sieben",7},
        {"acht", 8},
        {"neun",9}
    };
    QMap<QString,int> ten = {

        {"zehn",10},
        {"zwanzig", 20},
        {"dreißig",30},
        {"vierzig", 40},
        {"fünfzig",50},
        {"sechzig", 60},
        {"siebzig",70},
        {"achtzig", 80},
        {"neunzig",90}
    };
    QMap<QString,int> tenhund = {

        {"elf",11},
        {"zwölf", 12},
        {"dreizehn",13},
        {"vierzehn", 14},
        {"fünfzehn",15},
        {"sechzehn", 16},
        {"siebzehn",17},
        {"achtzehn", 18},
        {"neunzehn",19}
    };
    QMap<QString,int> hund = {

        {"hundert",100}
//        {"einhundert",100},
//        {"zweihundert", 200},
//        {"dreihundert",300},
//        {"vierhundert", 400},
//        {"fünfhundert",500},
//        {"sechshundert", 600},
//        {"siebenhundert",700},
//        {"achthundert", 800},
//        {"neunhundert",900}
    };

    QMap<QString,int> und = {
        {"und",1000}
    };

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
