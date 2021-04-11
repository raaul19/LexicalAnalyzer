#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_analyzeBT_clicked(){
    Automatum automatum;
    std::list<Analyzer> aux;
    std::string text;
    QMessageBox popUp;
    int row = 0;

    text = ui->textTE->toPlainText().toStdString();
    aux = automatum.automata(text);
    if(!aux.empty()){
       for(std::list<Analyzer>::iterator ite = aux.begin(); ite != aux.end(); ite++){
            ui->tokensTableTG->insertRow(ui->tokensTableTG->rowCount());
            ui->tokensTableTG->setItem(row,0,new QTableWidgetItem(QString(ite->getToken().c_str())));
            ui->tokensTableTG->setItem(row,1,new QTableWidgetItem(QString(ite->getNum().c_str())));
            ui->tokensTableTG->setItem(row,2,new QTableWidgetItem(QString(ite->getLexeme().c_str())));
            row++;
        }
        cout << " S I Z E : " << aux.size() << endl;
    }
    else{
        popUp.setText("Ingrese datos para analizar! ");
        popUp.exec();
    }
}
