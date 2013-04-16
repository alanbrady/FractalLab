#include "sierpinskifractalwidget.h"
#include "ui_sierpinskifractalwidget.h"

SierpinskiFractalWidget::SierpinskiFractalWidget(QWidget *parent) :
    AbstractFractalWidget(parent),
    ui(new Ui::SierpinskiFractalWidget),
    m_fractal(0, 0, 0, 0, 0)
{
    ui->setupUi(this);
    m_fractal.setIterations(ui->iterationsInput->text().toInt());

    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(generate()));
}

SierpinskiFractalWidget::~SierpinskiFractalWidget()
{
    delete ui;
}

void SierpinskiFractalWidget::generate()
{
    m_fractal.setIterations(ui->iterationsInput->text().toInt());
    emit needsRedraw();
}
