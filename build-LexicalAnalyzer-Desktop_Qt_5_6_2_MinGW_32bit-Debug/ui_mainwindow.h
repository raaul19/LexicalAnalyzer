/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *Title;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textTE;
    QPushButton *analyzeBT;
    QTableWidget *tokensTableTG;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 762);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Title, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textTE = new QTextEdit(centralWidget);
        textTE->setObjectName(QStringLiteral("textTE"));

        horizontalLayout->addWidget(textTE);

        analyzeBT = new QPushButton(centralWidget);
        analyzeBT->setObjectName(QStringLiteral("analyzeBT"));

        horizontalLayout->addWidget(analyzeBT);


        verticalLayout->addLayout(horizontalLayout);

        tokensTableTG = new QTableWidget(centralWidget);
        if (tokensTableTG->columnCount() < 3)
            tokensTableTG->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tokensTableTG->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tokensTableTG->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tokensTableTG->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tokensTableTG->setObjectName(QStringLiteral("tokensTableTG"));

        verticalLayout->addWidget(tokensTableTG);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        Title->raise();
        textTE->raise();
        analyzeBT->raise();
        tokensTableTG->raise();
        textTE->raise();
        textTE->raise();
        textTE->raise();
        textTE->raise();
        label->raise();
        Title->raise();
        Title->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LexicalAnalyzer", 0));
        Title->setText(QApplication::translate("MainWindow", "Analizador L\303\251xico", 0));
        label->setText(QString());
        analyzeBT->setText(QApplication::translate("MainWindow", "Analizar", 0));
        QTableWidgetItem *___qtablewidgetitem = tokensTableTG->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Token", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tokensTableTG->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "N\303\272mero", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tokensTableTG->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Lexema", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
