#ifndef ANIMINFO_H
#define ANIMINFO_H

#include <QMainWindow>
#include <QTextStream>

namespace Ui {
class AnimInfo;
}

class AnimInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnimInfo(QWidget *parent = nullptr);
    ~AnimInfo();

private:
    Ui::AnimInfo *ui;

public slots:
    void infoSlot(QString name);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // ANIMINFO_H
