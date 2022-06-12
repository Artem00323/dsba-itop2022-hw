#include "aboutpage.h"
#include "ui_aboutpage.h"
#include <QPixmap>

AboutPage::AboutPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutPage)
{
    ui->setupUi(this);
    QPixmap pix(":/rec/img/logosize.png");  // logo img
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}


AboutPage::~AboutPage()
{
    delete ui;
}
