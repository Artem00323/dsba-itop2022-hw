#ifndef ANIMAL_H
#define ANIMAL_H

#include <QMainWindow>
#include "animinfo.h"

namespace Ui {
class Animal;
}

class Animal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Animal(QWidget *parent = nullptr);
    ~Animal();

private:
    Ui::Animal *ui;
    AnimInfo *animInfoWin;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

public slots:
    void slot(QStringList allAnimals);

signals:
    void infoSignal(QString); // for sending name of animal to AnimInfo window
    void backSignal(QStringList); // for sending allAnimals list to mainwindow
};

#endif // ANIMAL_H
