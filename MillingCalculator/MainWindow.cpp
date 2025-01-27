#include "MainWindow.h"

#include "qpixmap.h"
#include "qstring.h"
#include "qmessagebox.h"
#include "qdebug.h"

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClass())
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

	QPixmap pixmap(":/MainWindow/formula.png");
    ui->labelFomula->setPixmap(pixmap.scaled(ui->labelFomula->size(), Qt::KeepAspectRatio));

    connect(ui->btnRev, &QToolButton::clicked, [=]() {
		ui->vc->setValue(pie * D() * N() / 1000);
        ui->fz->setValue(Vf() / (Z() * N()));
        });
    connect(ui->btnFeed, &QToolButton::clicked, [=]() {
        ui->vc->setValue(pie * D() * N() / 1000);
        ui->fz->setValue(Vf() / (Z() * N()));
        });
    connect(ui->btnFz, &QToolButton::clicked, [=]() {
        ui->rev->setValue(Vc() / (pie * D()) * 1000);
        ui->feed->setValue(Fz() * Z() * N());
        });
	connect(ui->btnVc, &QToolButton::clicked, [=]() {
        ui->rev->setValue(Vc() / (pie * D()) * 1000);
        ui->feed->setValue(Fz() * Z() * N());
		});

	connect(ui->radius, &QDoubleSpinBox::editingFinished, [=]() {
		if (!checkValue())
		{
            ui->radius->setValue(0);
			QMessageBox::critical(this, tr("错误"), tr("r角必须小于刀具半径"));
		}
        else
            ui->statusBar->showMessage(tr("环形刀/球头刀等效直径：") + QString::number(D(), 'f', 2));
		});
    connect(ui->height, &QDoubleSpinBox::editingFinished, [=]() {
            ui->statusBar->showMessage(tr("环形刀/球头刀等效直径：") + QString::number(D(), 'f', 2));
        });

    emit ui->btnFz->clicked();
	emit ui->btnVc->clicked();

    QLabel* copyright = new QLabel("Copyright(C) 2024 张璞玉  ");
    ui->statusBar->addPermanentWidget(copyright);
    ui->statusBar->showMessage(tr("单位和 UG.NX 一致"));
}

bool MainWindow::checkValue()
{
    double d = ui->diameter->value();
    return d + 0.0001 > r() * 2;
}
