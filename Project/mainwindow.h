#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "aboutpage.h"
#include "animal.h"
#include "animinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_project_triggered();
    void on_pushButton_clicked();
    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    AboutPage *aboutWin;
    Animal *animWin;
    AnimInfo *animInfoWin;
    QStandardItemModel *model;
    void printingTable(QString filePath);
    QString _filePath;

public slots:
    void getSlot(QStringList allAnimals);

signals:
    void signal(QStringList);
};
#endif // MAINWINDOW_H
