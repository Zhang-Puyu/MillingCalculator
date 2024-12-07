#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

/// @brief 主窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

private:
    Ui::MainWindowClass* ui;

    const double pie = 3.14159;

    /// @brief 环形刀(牛鼻刀)在距离底部H处的等效直径
    double D()  
    { 
        double R = ui->diameter->value() / 2; 
        if (h() >= r())
            return R * 2;
        else
            return (R - r() + sqrt(2 * r() * h() - h() * h())) * 2;
    }
    /// @brief 刀齿数
    int    Z()  { return ui->toothNum->value(); }
	/// @brief 环形刀(牛鼻刀)底部R角半径
	double r()  { return ui->radius->value(); }
	/// @brief 刀具横截面距离底部的高度
	double h()  { return ui->height->value(); }
    /// @brief 主轴转速
    double N()  { return ui->rev->value();  }
	/// @brief 进给速度
    double Vf() { return ui->feed->value(); }
	/// @brief 每齿进给量
    double Fz() { return ui->fz->value();   }
	/// @brief 表面速度
    double Vc() { return ui->vc->value();   }

    /// @brief 检查数据
    bool checkValue();
};
