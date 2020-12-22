#ifndef MULTIPLECHOICES_H
#define MULTIPLECHOICES_H

#include <QDialog>

namespace Ui {
  class Multiplechoices;
}

class Multiplechoices : public QDialog
{
  Q_OBJECT

public:
  explicit Multiplechoices(QWidget *parent = nullptr);
  ~Multiplechoices();

private:
  Ui::Multiplechoices *ui;
};

#endif // MULTIPLECHOICES_H
