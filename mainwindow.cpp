#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->errorLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString usernameEntered = ui->userNameInput->text();
    QString passwordEntered = ui->passwordInput->text();
    bool usernameFound = false;
    bool passwordFound = false;

    for (int i = 0; i < 4; i++){
        if (usernames[i] == usernameEntered)
            usernameFound = true;
    }
    for (int i = 0; i < 4; i++){
        if (passwords[i] == passwordEntered)
            passwordFound = true;
    }
    if (!usernameFound && passwordFound){
        ui->errorLabel->setText("username not found");
    }
    else if (!passwordFound && usernameFound){
        ui->errorLabel->setText("password not found");
    }
    else if (!passwordFound && !usernameFound) {
        ui->errorLabel->setText("both username and password not found");
    }
    else {
        hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
        welcomeWindow->show();
    }
}


void MainWindow::on_regissterButton_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();

}

