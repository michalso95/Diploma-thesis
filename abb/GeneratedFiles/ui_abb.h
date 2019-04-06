/********************************************************************************
** Form generated from reading UI file 'abb.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABB_H
#define UI_ABB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abbClass
{
public:
    QWidget *centralWidget;
    QTabWidget *author;
    QWidget *Chessboard;
    QWidget *VisionSystem;
    QPushButton *btnPauseOrResume;
    QLabel *lblProcessed;
    QLabel *lblOriginal;
    QPlainTextEdit *txtXYRadius;
    QPlainTextEdit *zmienne;
    QWidget *tab;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *abbClass)
    {
        if (abbClass->objectName().isEmpty())
            abbClass->setObjectName(QStringLiteral("abbClass"));
        abbClass->resize(1307, 641);
        centralWidget = new QWidget(abbClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        author = new QTabWidget(centralWidget);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(0, 0, 1301, 631));
        Chessboard = new QWidget();
        Chessboard->setObjectName(QStringLiteral("Chessboard"));
        author->addTab(Chessboard, QString());
        VisionSystem = new QWidget();
        VisionSystem->setObjectName(QStringLiteral("VisionSystem"));
        btnPauseOrResume = new QPushButton(VisionSystem);
        btnPauseOrResume->setObjectName(QStringLiteral("btnPauseOrResume"));
        btnPauseOrResume->setGeometry(QRect(110, 480, 161, 91));
        lblProcessed = new QLabel(VisionSystem);
        lblProcessed->setObjectName(QStringLiteral("lblProcessed"));
        lblProcessed->setGeometry(QRect(590, 10, 450, 450));
        lblOriginal = new QLabel(VisionSystem);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setGeometry(QRect(0, 10, 450, 450));
        txtXYRadius = new QPlainTextEdit(VisionSystem);
        txtXYRadius->setObjectName(QStringLiteral("txtXYRadius"));
        txtXYRadius->setGeometry(QRect(490, 460, 551, 131));
        zmienne = new QPlainTextEdit(VisionSystem);
        zmienne->setObjectName(QStringLiteral("zmienne"));
        zmienne->setGeometry(QRect(1070, 40, 121, 411));
        author->addTab(VisionSystem, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 321, 141));
        author->addTab(tab, QString());
        abbClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(abbClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        abbClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(abbClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        abbClass->setStatusBar(statusBar);

        retranslateUi(abbClass);

        author->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(abbClass);
    } // setupUi

    void retranslateUi(QMainWindow *abbClass)
    {
        abbClass->setWindowTitle(QApplication::translate("abbClass", "abb", 0));
        author->setTabText(author->indexOf(Chessboard), QApplication::translate("abbClass", "Chessboard", 0));
        btnPauseOrResume->setText(QApplication::translate("abbClass", "PushButton", 0));
        lblProcessed->setText(QString());
        lblOriginal->setText(QString());
        author->setTabText(author->indexOf(VisionSystem), QApplication::translate("abbClass", "Vision System", 0));
        label->setText(QApplication::translate("abbClass", "<html><head/><body><p>Author:<br/>Micha\305\202 Soko\305\202owski</p><p>Praca na in\305\274ynierk\304\231</p><p><br/></p><p>Kielce University of Technology, 2019</p></body></html>", 0));
        author->setTabText(author->indexOf(tab), QApplication::translate("abbClass", "Author", 0));
    } // retranslateUi

};

namespace Ui {
    class abbClass: public Ui_abbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABB_H
