#include "MainWindow.h"

#include "qpixmap.h"
#include "qstring.h"

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

    emit ui->btnFz->clicked();
	emit ui->btnVc->clicked();

    QLabel* copyright = new QLabel("(C) 2024 张璞玉  ");
    ui->statusBar->addPermanentWidget(copyright);
    ui->statusBar->showMessage(tr("单位和UG.NX一致"));
}
