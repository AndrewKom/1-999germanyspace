#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_2->clear();
    count=0;
    final=0;
    QStringList list1=ui->lineEdit->text().split(' ',Qt::SkipEmptyParts);
    list1 = list1.join(' ').split(' ',Qt::SkipEmptyParts);
    QList<int> numbers;
    //Обработка введенного текста
    for (int i=0;i<list1.size();i++){
        if(one.contains(list1[i])){
            numbers.append(one.value(list1[i]));
        }
        if(ten.contains(list1[i])){
            numbers.append(ten.value(list1[i]));
        }
        if(tenhund.contains(list1[i])){
            numbers.append(tenhund.value(list1[i]));
        }
        if(hund.contains(list1[i])){
            numbers.append(hund.value(list1[i]));
        }
        if(und.contains(list1[i])){
            numbers.append(und.value(list1[i]));
        }
        if (!(one.contains(list1[i]) or ten.contains(list1[i]) or tenhund.contains(list1[i]) or hund.contains(list1[i]) or und.contains(list1[i]) ) and (count==0)){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка!");
            msgBox.setText("Слово "+list1[i]+" не является числом на немецком! Повторите попытку ввода!");
            msgBox.exec();
            count=-1;
        }
    }



    //Обработка сотенного формата

    if (count==0){
        for(int i =0;i<numbers.size()-1;i++){
            if (QString::number(numbers.at(i+1)).size() == 3 and QString::number(numbers.at(i)).size() == 1){
                numbers[i+1]=numbers.at((i+1))*numbers.at((i));
                numbers[i]=0;

            }
        }
    }

    if (count==0){
        for(int i =0;i<numbers.size()-1;i++){
            if(numbers.at(i)==0){
                numbers.removeAt(i);
            }
        }
    }








//Аналитика рядом стоящих цифр
   if (count==0){
       qDebug()<<numbers;

       if (numbers.isEmpty()!=true){
       if(numbers.at(0)==1000){
           QMessageBox msgBox;
           msgBox.setWindowTitle("Ошибка!");
           msgBox.setText("und стоит на первой позиции, повторите ввод");
           msgBox.exec();
           count=-1;
       }
       }
       for(int i =0;i<numbers.size()-1;i++){
           if (count==0){


               //und обработка
               if(numbers.at(i)==1000 and numbers.at(i+1)==1000){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("und стоит рядом с другим und, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }

               if(numbers.at(i)==1000 and QString::number(numbers.at(i+1)).size() == 1){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("und стоит перед числом единичного формата, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }
               if(numbers.at(i)==1000 and QString::number(numbers.at(i+1)).size() == 3){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("und стоит перед числом сотенного формата, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }
               if(numbers.at(i)==1000 and QString::number(numbers.at(i+1)).size() == 2 and (numbers.at(i+1)>=10 and numbers.at(i+1)<20)){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("und стоит перед числом формата 10-19, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }

               if(numbers.at(i+1)==1000 and QString::number(numbers.at(i)).size() == 2){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("После числа двоичного формата стоит und, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }

               if(numbers.at(i+1)==1000 and QString::number(numbers.at(i)).size() == 3){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("После числа сотенного формата стоит und, повторите ввод");
                   msgBox.exec();
                   count=-1;
                   break;
               }


            qDebug()<<QString::number(numbers.at(i)).size();
            switch(QString::number(numbers.at(i)).size()){
           case 1:
               if (QString::number(numbers.at(i+1)).size() == 1){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("Числа единичного формата рядом с друг другом");
                   msgBox.exec();
                   count=-1;
                   break;
               }
               if (QString::number(numbers.at(i+1)).size() == 2 and (numbers.at(i+1)>10 and numbers.at(i+1)<20)){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("Числа единичного формата рядом с числом десятичного формата 11-19");
                   msgBox.exec();
                   count=-1;
                   break;
               }
               if (QString::number(numbers.at(i+1)).size() == 2 and (numbers.at(i+1)<=10 or numbers.at(i+1)>=20)){
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Ошибка!");
                   msgBox.setText("Числа единичного формата рядом с числом десятичного формата, используйте und!");
                   msgBox.exec();
                   count=-1;
                   break;
               }


            case 2:
                if (QString::number(numbers.at(i+1)).size() == 1){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Ошибка!");
                    msgBox.setText("Число двоичного формата стоит до числа единичного формата");
                    msgBox.exec();
                    count=-1;
                    break;
                }
                if (QString::number(numbers.at(i+1)).size() == 2){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Ошибка!");
                    msgBox.setText("Число двоичного формата стоит рядом с другим числом двоичного формата");
                    msgBox.exec();
                    count=-1;
                    break;
                }
                if (QString::number(numbers.at(i+1)).size() == 3){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Ошибка!");
                    msgBox.setText("До числа сотенного формата не может стоять число никакого формата");
                    msgBox.exec();
                    count=-1;
                    break;
                }


            case 3:
                if (QString::number(numbers.at(i+1)).size() == 3){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Ошибка!");
                    msgBox.setText("Число сотенного формата стоит рядом с другим числом сотенного формата");
                    msgBox.exec();
                    count=-1;
                    break;
                }



            }

   }
   }

if (numbers.isEmpty()!=true){
       if(numbers.at(numbers.size()-1)==1000 and count==0){
           QMessageBox msgBox;
           msgBox.setWindowTitle("Ошибка!");
           msgBox.setText("und стоит на последней позиции, используйте число двоичного формата");
           msgBox.exec();
           count=-1;
       }
}
   }








//    Подсчет числа
    if (count==0){
        for(int i = 0; i < numbers.size();i++){
            if (numbers.at(i)<1000){
                final += numbers.at(i);
            }
        }
    ui->lineEdit_2->setText(QString::number(final));
    qDebug()<<numbers;
    }
}
