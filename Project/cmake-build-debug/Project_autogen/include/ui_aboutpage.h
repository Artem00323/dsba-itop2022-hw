/********************************************************************************
** Form generated from reading UI file 'aboutpage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPAGE_H
#define UI_ABOUTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutPage
{
public:
    QLabel *label_pic;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AboutPage)
    {
        if (AboutPage->objectName().isEmpty())
            AboutPage->setObjectName(QString::fromUtf8("AboutPage"));
        AboutPage->resize(400, 300);
        label_pic = new QLabel(AboutPage);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(40, 10, 311, 161));
        label_2 = new QLabel(AboutPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 180, 171, 41));
        label_3 = new QLabel(AboutPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 210, 191, 31));

        retranslateUi(AboutPage);

        QMetaObject::connectSlotsByName(AboutPage);
    } // setupUi

    void retranslateUi(QDialog *AboutPage)
    {
        AboutPage->setWindowTitle(QCoreApplication::translate("AboutPage", "About", nullptr));
        label_pic->setText(QString());
        label_2->setText(QCoreApplication::translate("AboutPage", "<html><head/><body><p><span style=\" font-size:18pt;\">Project: Zoo register</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("AboutPage", "<html><head/><body><p><span style=\" font-size:18pt;\">Author: Artem Zakharov</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutPage: public Ui_AboutPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPAGE_H
