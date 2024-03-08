#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->userNameError->setVisible(false);
    ui->passwordError->setVisible(false);
    ui->dateOfBirthError->setVisible(false);
    ui->retypePasswordError->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
