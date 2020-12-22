#ifndef TRIVIATYPE_H
#define TRIVIATYPE_H

#include <QDialog>
#include "trueorfalse.h"

#include "grammarquiz.h"

namespace Ui {
class TriviaType;
}

class TriviaType : public QDialog
{
    Q_OBJECT

public:
    explicit TriviaType(QWidget *parent = nullptr);
    ~TriviaType();
  void makeClickingSounds();
  QString getQuestions(int index);
  QString getChoices(int col,int row);
  char getAnswer(int index);
  void resetbuttonstate();
private slots:


  void on_MultipleChoice_clicked();

  void on_trueOrFalse_clicked();

  void on_pushButton_clicked();

  void on_trueOrFalse_pressed();

  void on_MultipleChoice_pressed();

  void on_pushButton_pressed();

  void on_FillInTheBlanks_clicked();



  void on_bonusQuiz_clicked();

  void on_FillInTheBlanks_pressed();

  void on_bonusQuiz_pressed();

private:
    Ui::TriviaType *ui;
    TrueOrFalse *True_Or_False_Form;

    GrammarQuiz *gq;
};

#endif // TRIVIATYPE_H
