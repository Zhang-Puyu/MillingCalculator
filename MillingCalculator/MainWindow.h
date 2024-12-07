#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

/// @brief ������
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

private:
    Ui::MainWindowClass* ui;

    const double pie = 3.14159;

    /// @brief ���ε�(ţ�ǵ�)�ھ���ײ�H���ĵ�Чֱ��
    double D()  
    { 
        double R = ui->diameter->value() / 2; 
        if (h() >= r())
            return R * 2;
        else
            return (R - r() + sqrt(2 * r() * h() - h() * h())) * 2;
    }
    /// @brief ������
    int    Z()  { return ui->toothNum->value(); }
	/// @brief ���ε�(ţ�ǵ�)�ײ�R�ǰ뾶
	double r()  { return ui->radius->value(); }
	/// @brief ���ߺ�������ײ��ĸ߶�
	double h()  { return ui->height->value(); }
    /// @brief ����ת��
    double N()  { return ui->rev->value();  }
	/// @brief �����ٶ�
    double Vf() { return ui->feed->value(); }
	/// @brief ÿ�ݽ�����
    double Fz() { return ui->fz->value();   }
	/// @brief �����ٶ�
    double Vc() { return ui->vc->value();   }

    /// @brief �������
    bool checkValue();
};
