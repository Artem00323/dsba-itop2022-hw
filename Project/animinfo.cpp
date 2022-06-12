#include "animinfo.h"
#include "ui_animinfo.h"
#include "mainwindow.h"
#include <QFile>


AnimInfo::AnimInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnimInfo)
{
    ui->setupUi(this);
}


AnimInfo::~AnimInfo()
{
    delete ui;
}


void AnimInfo::infoSlot(QString name) // slot getting signal from animalWindow with the name of the chosen animal
{
    setWindowTitle(name);

    // class
    QString filePath = ":/rec/datasets/class.csv";
    if (filePath.isEmpty()) {
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream table(&file);
    QString line = table.readLine(); // do not need header line
    while (!table.atEnd()) {
        line = table.readLine();
        QStringList values = line.split('"');
        QString nameOfClass = values[0].split(',')[2];
        for (int i = 0; i < values[1].split(", ").size(); ++i) {
            if (values[1].split(", ")[i] == name) {
                ui->listWidget->addItem(nameOfClass);
            }
        }
    }

    // all other info
    QString filePath1 = ":/rec/datasets/zoo.csv";
    if (filePath1.isEmpty()) {
        return;
    }
    QFile file1(filePath1);
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream table1(&file1);
    QString line1 = table1.readLine(); // header line
    QString line2;
    while (!table1.atEnd()) {
        line2 = table1.readLine();
        if (line2.split(',')[0] == name) {
            for (int i = 1; i < line2.split(',').size() - 1; ++i) { // -1 because last column is about classes
                if (line2.split(',')[i] == '1') {
                    ui->listWidget->addItem(line1.split(',')[i]);
                }
            }
        }
    }

    QString answer = "Total number of features: " + QString::number(ui->listWidget->count());
    ui->statusBar->showMessage(answer); // shows the number of animals in the status bar

}


void AnimInfo::on_pushButton_clicked() // add button
{
    QString newClass = ui->lineEdit->text();
    if (newClass != ""){
        ui->listWidget->addItem(newClass);
        QString curStatus = QString::number(ui->statusBar->currentMessage().split(' ')[ui->statusBar->currentMessage().split(' ').size()-1].toInt() + 1);
        ui->statusBar->showMessage("Total number of features: " + curStatus);
    }
}


void AnimInfo::on_pushButton_2_clicked()
{
    if (ui->listWidget->takeItem(ui->listWidget->currentRow())) {
        QString curStatus = QString::number(ui->statusBar->currentMessage().split(' ')[ui->statusBar->currentMessage().split(' ').size()-1].toInt() - 1);
        ui->statusBar->showMessage("Total number of features: " + curStatus);
    }
}

