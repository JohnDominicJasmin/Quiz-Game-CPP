#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QDialog>
#include "mainwindoww.h"
#include "multiplechoice.h"
#include "soundsettings.h"

namespace Ui {
class categories;
}

class categories : public QDialog
{
    Q_OBJECT

public:
    explicit categories(QWidget *parent = nullptr);
    ~categories();

 void showMultiplechoiceForm();
  void resetButtonState();


QString getQuestion(int indexnumber);
QString getChoices(int column, int row);
char getAnswer(int indexnumber);
private slots:

    void on_pushButton_History_clicked();
    void on_pushButton_Back_clicked();
    void on_pushButton_Geography_2_clicked();
    void on_pushButton_Animals_clicked();
    void on_pushButton_World_clicked();
    void on_pushButton_Humanities_clicked();
    void on_pushButton_Technology_clicked();
    void on_push_Button_Sports_clicked();
    void on_pushButton_Music_clicked();
    void on_pushButton_Science_clicked();
    void on_push_Button_Random_clicked();


    void on_pushButton_History_pressed();
    void on_pushButton_Back_pressed();
    void on_pushButton_Animals_pressed();
    void on_pushButton_Geography_2_pressed();
    void on_pushButton_World_pressed();
    void on_push_Button_Sports_pressed();
    void on_pushButton_Humanities_pressed();
    void on_pushButton_Technology_pressed();
    void on_pushButton_Music_pressed();
    void on_pushButton_Science_pressed();
    void on_push_Button_Random_pressed();

public slots:

     

private:
    Ui::categories *ui;
mainwindoww *mw;
multiplechoice *mc;
soundSettings makeSound;
};


#endif // CATEGORIES_H

