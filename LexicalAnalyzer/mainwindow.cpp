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

    text = ui->textTE->toPlainText().toStdString();
    aux = automatum.automata(text);
    if(!aux.empty()){
       for(std::list<Analyzer>::iterator ite = aux.begin(); ite != aux.end(); ite++){
           cout << "ID: " << ite->getNum() << endl;
           cout << "Lexema: " << ite->getLexeme() << endl;
           cout << "Token: " << ite->getToken() << endl;

        }
        cout << " S I Z E : " << aux.size() << endl;

    }
    else{
        popUp.setText("Ingrese datos para analizar! ");
        popUp.exec();
    }
}
