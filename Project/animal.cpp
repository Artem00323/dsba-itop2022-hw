#include "animal.h"
#include "ui_animal.h"
#include "mainwindow.h"

Animal::Animal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Animal)
{
    ui->setupUi(this);
}


Animal::~Animal()
{
    delete ui;
}


void Animal::slot(QStringList allAnimals) // slot getting signal from mainwindow with the column of all animals in the table
{
    // sending data back to mainWindow if it has changed ('@' element was added)
    if (allAnimals[allAnimals.size()-1] == "@") {
        allAnimals.removeAll(allAnimals[allAnimals.size()-1]);
        emit backSignal(allAnimals);
    }
    else {
        ui->listWidget->clear();
        // else sending data to a listWidget
        for (int i = 1; i < allAnimals.size(); ++i) {
            ui->listWidget->addItem(allAnimals[i]);
        }
        QString answer = "Total number of animals: " + QString::number(allAnimals.size()-1);
        ui->statusbar->showMessage(answer); // shows the number of animals in the status bar
    }
}


void Animal::on_pushButton_3_clicked() // choose button
{
    if (!ui->listWidget->selectedItems().empty()) {

        animInfoWin = new AnimInfo(this);
        animInfoWin->show();

        connect(this, &Animal::infoSignal, animInfoWin, &AnimInfo::infoSlot);

        emit infoSignal(ui->listWidget->currentItem()->text());
    }
}


void Animal::on_pushButton_2_clicked() // add button
{
    //changing the list
    QString newAnimal = ui->lineEdit->text();
    if (newAnimal != ""){
        ui->listWidget->addItem(newAnimal);
        QString curStatus = QString::number(ui->statusbar->currentMessage().split(' ')[ui->statusbar->currentMessage().split(' ').size()-1].toInt() + 1);
        ui->statusbar->showMessage("Total number of animals: " + curStatus); // changing the total number of animals to +1
    }

    // sending the edited version of the table to "mainwindow" table
    QList<QListWidgetItem*> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); // getting all items from the list of animals
    QStringList allAnimals;
    for (QListWidgetItem* i : items) {
        allAnimals += i->text();
    }
    allAnimals += "@";
    Animal::slot(allAnimals);
}


void Animal::on_pushButton_4_clicked() // delete button
{
    if (ui->listWidget->takeItem(ui->listWidget->currentRow())) {
        QString curStatus = QString::number(ui->statusbar->currentMessage().split(' ')[ui->statusbar->currentMessage().split(' ').size()-1].toInt() - 1);
        ui->statusbar->showMessage("Total number of animals: " + curStatus); // changing the total number of animals to -1
    }

    // sending the edited version of the table
    QList<QListWidgetItem*> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); // getting all items from the list of animals
    QStringList allAnimals;
    for (QListWidgetItem* i : items) {
        allAnimals += i->text();
    }
    allAnimals += "@";
    Animal::slot(allAnimals);
}


void Animal::on_pushButton_clicked() // sort button (sorting in ascending order with first click and descending with double click)
{
    ui->listWidget->sortItems(Qt::AscendingOrder);
    if (!ui->listWidget->isSortingEnabled()) {
        ui->listWidget->sortItems(Qt::DescendingOrder);
        ui->listWidget->setSortingEnabled(1);
    }
    else {
        ui->listWidget->setSortingEnabled(0);
    }

    // sending the edited version of the table
    QList<QListWidgetItem*> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); // getting all items from the list of animals
    QStringList allAnimals;
    for (QListWidgetItem* i : items) {
        allAnimals += i->text();
    }
    allAnimals += "@";
    Animal::slot(allAnimals);
}


