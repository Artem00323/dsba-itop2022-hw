#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutpage.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    animWin = new Animal(this);
    animInfoWin = new AnimInfo(this);
    connect(animWin, &Animal::backSignal, this, &MainWindow::getSlot); // for recieving edited table from allAnimals window

    //TODO: creating table when the window is first opened (must be easier way)
    QString filePath = ":/rec/datasets/zoo.csv";
    MainWindow::printingTable(filePath);
    _filePath = filePath;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printingTable(QString filePath) { // function which prints table
    if (filePath.isEmpty()) {
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"), file.errorString());
        qCritical() << file.errorString();
        return;
    }
    QModelIndex index;
    QTextStream table(&file);
    QString line = table.readLine();
    QStringList values = line.split(',');
    model->setRowCount(1);
    model->setColumnCount(values.size());
    for (int i = 0; i < values.size(); ++i) { // Header
        index = model->index(0, i);
        model->setData(index, values[i]);
    }
//     The rest table
    int rowCount = 2;
    while (!table.atEnd()) {
        model->setRowCount(rowCount);
        QString line = table.readLine();
        QStringList values = line.split(',');
        int colCount = values.size();
        model->setColumnCount(colCount);
        for (int i = 0; i < values.size(); ++i) {
            index = model->index(rowCount-1, i);
            model->setData(index, values[i]);
        }
        ++rowCount;
    }
    file.close();
    QString answer = "Total number of elements: " + QString::number(rowCount-2);
    ui->statusbar->showMessage(answer); // shows the number of animals in the status bar
}



void MainWindow::getSlot(QStringList allAnimals)
{
    if (_filePath.isEmpty()) {
        return;
    }
    QFile file(_filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"), file.errorString());
        qCritical() << file.errorString();
        return;
    }
    QModelIndex index;
    QTextStream table(&file);
    QString line = table.readLine();
    QStringList values = line.split(',');
    model->setRowCount(1);
    model->setColumnCount(values.size());
    for (int i = 0; i < values.size(); ++i) { // Header
        index = model->index(0, i);
        model->setData(index, values[i]);
    }
    file.close();

    //     The rest table
    if (allAnimals.size() >= 1) {
        int rowCount = 2;
        for (int i = 0; i < allAnimals.size(); ++i) {
            QFile file(_filePath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::critical(this, tr("Unable to open file"), file.errorString());
                qCritical() << file.errorString();
                return;
            }
            QModelIndex index;
            QTextStream table(&file);
            QString line = table.readLine(); // skipping header for the first time
            QStringList values = line.split(',');
            model->setRowCount(rowCount);
            int colCount = values.size();
            model->setColumnCount(colCount);
            index = model->index(rowCount-1, 0);
            int ifDone = 0;
            while (!table.atEnd()) {
                QString line = table.readLine();
                QStringList values = line.split(',');
    //            qDebug() << values[0] << allAnimals[i];
                if (values[0] == allAnimals[i]) {
                    model->setData(index, allAnimals[i]);
                    for (int j = 1; j < values.size(); ++j) {
                        index = model->index(rowCount-1, j);
                        model->setData(index, values[j]);
                    }
                    ifDone = 1;
                    break;
                }
            }
            if (ifDone == 0) {
                model->setData(index, allAnimals[i]);
                for (int j = 1; j < values.size(); ++j) {
                    index = model->index(rowCount-1, j);
                    model->setData(index, 0);
                }
            }
            ++rowCount;
            file.close();
        }
    }
    QString answer = "Total number of elements: " + QString::number(model->rowCount()-1);
    ui->statusbar->showMessage(answer); // shows the number of animals in the status bar
}


void MainWindow::on_actionAbout_project_triggered() // opens window with "about project" info
{
//    aboutpage window is in priority, so we cannot deal with the main window until aboutpage is closed.
    AboutPage aboutWin;
    aboutWin.setModal(true);
    aboutWin.exec();
}


void MainWindow::on_pushButton_clicked() // opens window with "all animals" list
{

    animWin->show();
    connect(this, &MainWindow::signal, animWin, &Animal::slot);

    QStringList allAnimals;
    for (int i = 0; i < model->rowCount(); ++i) // getting all the animals names
    {
        allAnimals += model->data(model->index(i, 0)).toString();
    }

    emit signal(allAnimals); // sending signal to animal window slot with all the animals' names
}


void MainWindow::on_actionOpen_triggered() // "open file" button to open and extract info from the given csv table
{
    QString filePath;
    filePath = QFileDialog::getOpenFileName(this, "choose file", "", "CSV files (*.csv)"); // third parameter takes path to the folder

    MainWindow::printingTable(filePath);
}

void MainWindow::on_actionSave_as_triggered() // "save as" button
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("save file"), "",
            tr("CSV files (*.csv);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Unable to open file"), file.errorString());
            qCritical() << file.errorString();
            return;
        } else {
            QTextStream out(&file);
            QModelIndex index;
            QString oneItem;
            for (int i = 0; i < model->rowCount(); ++i) {
                for (int j = 0; j < model->columnCount(); ++j) {
                    oneItem = model->data(model->index(i, j)).toString();
                    out << oneItem;
                    if (j != model->columnCount() - 1)
                        out << ",";
                }
                out << "\n";
            }
            file.close();
        }
    }
}

