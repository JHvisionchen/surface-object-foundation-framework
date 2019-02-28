/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *showLabel;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QLabel *resultLabel;
    QSlider *verticalSlider;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 750);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showLabel = new QLabel(centralWidget);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        showLabel->setGeometry(QRect(0, 0, 955, 540));
        showLabel->setStyleSheet(QStringLiteral("border-image: url(:/background/img/jinghai2.jpg);"));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(430, 730, 80, 20));
        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setGeometry(QRect(520, 730, 80, 20));
        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        resultLabel->setGeometry(QRect(965, 0, 955, 540));
        resultLabel->setStyleSheet(QStringLiteral("border-image: url(:/background/img/jinghai2.jpg);"));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(955, 0, 10, 540));
        verticalSlider->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        showLabel->setText(QString());
        startBtn->setText(QApplication::translate("MainWindow", "start", 0));
        stopBtn->setText(QApplication::translate("MainWindow", "stop", 0));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
