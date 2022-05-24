#ifndef MOVIEINPUT_H
#define MOVIEINPUT_H

#include <QWidget>

namespace Ui {
class MovieInput;
}

class MovieInput : public QWidget
{
    Q_OBJECT

public:
    explicit MovieInput(QWidget *parent = nullptr);
    ~MovieInput();

private slots:
    void on_ChoiceImg_clicked();
    void on_Save_clicked();

private:
    Ui::MovieInput *ui;
};

#endif // MOVIEINPUT_H
