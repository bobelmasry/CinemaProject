#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "mainwindow.h"


WelcomeWindow::WelcomeWindow(QWidget *parent, const QString &username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText("Hello " + username + " " + QString::number(age));

    QPixmap pix ("C:/Users/lenovo/Desktop/CinemaProject/welcomeImage");
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->imageLabel->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logoutButton_clicked()
{
    hide();
    WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
    welcomeWindow->show();

}

