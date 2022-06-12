/********************************************************************************
** Form generated from reading UI file 'animal.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMAL_H
#define UI_ANIMAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Animal
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionInfo;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Animal)
    {
        if (Animal->objectName().isEmpty())
            Animal->setObjectName(QString::fromUtf8("Animal"));
        Animal->resize(600, 500);
        actionOpen = new QAction(Animal);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/open_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave_as = new QAction(Animal);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/saveas_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon1);
        actionInfo = new QAction(Animal);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/about_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon2);
        centralwidget = new QWidget(Animal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Animal->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Animal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Animal->setStatusBar(statusbar);

        retranslateUi(Animal);

        QMetaObject::connectSlotsByName(Animal);
    } // setupUi

    void retranslateUi(QMainWindow *Animal)
    {
        Animal->setWindowTitle(QCoreApplication::translate("Animal", "Animals", nullptr));
        actionOpen->setText(QCoreApplication::translate("Animal", "Open", nullptr));
        actionSave_as->setText(QCoreApplication::translate("Animal", "Save as", nullptr));
        actionInfo->setText(QCoreApplication::translate("Animal", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Animal: public Ui_Animal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMAL_H
