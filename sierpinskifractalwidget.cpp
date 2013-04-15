#include "sierpinskifractalwidget.h"
#include "ui_sierpinskifractalwidget.h"

SierpinskiFractalWidget::SierpinskiFractalWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SierpinskiFractalWidget)
{
    ui->setupUi(this);
}

SierpinskiFractalWidget::~SierpinskiFractalWidget()
{
    delete ui;
}
