#include "welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, const QString &username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText("Hello " + username + " " + QString::number(age));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
