#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Generator.h"
#include <QMessageBox>
#include <string>
using std::string;

static Generator gen;
static int sys_type;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm("background3.jpeg"); // <- path to image file
    ui->background->setPixmap(pm);
    ui->background->setScaledContents(true);
    ui->chkBoxCD->setChecked(true);
    sys_type = 1;
    //ui->chkBoxRat->setStyleSheet("QCheckBox { color: orange }");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnGen_clicked()
{
    bool w_rat, w_cruz, w_dist,all_fine;
    string solution;
    w_rat = ui->chkBoxRat->checkState();
    w_cruz = ui->chkBoxCruz->checkState();
    w_dist = ui->chkBoxDist->checkState();
    all_fine = true;
    if (ui->chkBoxCD->checkState())
        solution = ui->txtSol->toPlainText().toUtf8().constData();
    else
        solution = "1";

    size_t match = solution.find("/");

    if (!(ui->chkBoxCD->checkState()) && !(ui->chkBoxCI->checkState()) && !(ui->chkBoxInc->checkState())){
        all_fine = false;
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Seleccione el tipo de ecuacion deseada: compatible determinada, indeterminada o incompatible");
        msgBox.exec();
    }

    if (!w_rat && (match != string::npos)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("La solucion no puede ser racional, porque no esta seleccionada la opcion 'Con racionales' ");
        msgBox.exec();
        all_fine = false;
    }


    if (all_fine){
        std::string equ_str = gen.generate(solution,w_rat,w_dist,w_cruz, sys_type);
        QString equation = QString::fromUtf8(equ_str.c_str());
        ui->txtEqu->setText(equation);
    }
}



void MainWindow::on_chkBoxCD_clicked()
{
    ui->chkBoxCI->setChecked(false);
    ui->chkBoxInc->setChecked(false);
    ui->txtSol->setDisabled(false);
    sys_type = 1;
}


void MainWindow::on_chkBoxCI_clicked()
{
    ui->chkBoxCD->setChecked(false);
    ui->chkBoxInc->setChecked(false);
    ui->txtSol->setDisabled(true);
    ui->txtSol->clear();
    sys_type = 2;
}

void MainWindow::on_chkBoxInc_clicked()
{
    ui->chkBoxCD->setChecked(false);
    ui->chkBoxCI->setChecked(false);
    ui->txtSol->setDisabled(true);
    ui->txtSol->clear();
    sys_type = 3;
}



void MainWindow::on_BtnExit_clicked()
{
    close();
}
