#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->userNameError->setVisible(false);
    ui->registerError->setVisible(false);
    ui->dateOfBirthError->setVisible(false);
    ui->retypePasswordError->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();
    QString retypedpPassword = ui->retypePassowrdInput->text();

    QString month = ui->comboBox->currentText();
    QString day = ui->Day->text();
    QString year = ui->Year->text();

    int dayInt = day.toInt();
    int yearInt = year.toInt();

    bool isMale = ui->maleRadio->isChecked();
    bool isFemale = ui->femaleRadio->isChecked();
    bool isAdmin = ui->adminRadio->isChecked();
    bool isUser = ui->userRadio->isChecked();

    bool isAction = ui->actionCheck->isChecked();
    bool isDrama = ui->dramaCheck->isChecked();
    bool isComedy = ui->comedyCheck->isChecked();
    bool isRomance = ui->romanceCheck->isChecked();
    bool isHorror = ui->horrorCheck->isChecked();
    bool isOther = ui->otherCheck->isChecked();

    for(int i = 0 ; i<4 ; i++){
        if (username==usernames[i]){
            ui->userNameError->setVisible(true);
        }
    }

    if(password!=retypedpPassword){
        ui->retypePasswordError->setVisible(true);
    }

    if((2024-yearInt)<12){
        ui->dateOfBirthError->setVisible(true);
    }

    if(username.isEmpty() || password.isEmpty() || retypedpPassword.isEmpty() || ( !isMale && !isFemale) || ( !isRomance && !isAction && !isDrama && isComedy && !isHorror && isOther ) ||
        day.isEmpty() || year.isEmpty() || month.isNull()){
        ui->registerError->setVisible(true);
    }
}

