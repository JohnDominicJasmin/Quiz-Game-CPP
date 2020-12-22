#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QDialog>

namespace Ui {
  class optionwindow;
}

class optionwindow : public QDialog
{
  Q_OBJECT

public:
  explicit optionwindow(QWidget *parent = nullptr);
  ~optionwindow();

private:
  Ui::optionwindow *ui;
};

#endif // OPTIONWINDOW_H
