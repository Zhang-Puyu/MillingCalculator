#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

private:
    Ui::MainWindowClass* ui;

    const double pie = 3.14159;

    double D()  { return ui->diameter->value(); }
    int    Z()  { return ui->toothNum->value(); }

    double N()  { return ui->rev->value();  }
    double Vf() { return ui->feed->value(); }
    double Fz() { return ui->fz->value();   }
    double Vc() { return ui->vc->value();   }
};
