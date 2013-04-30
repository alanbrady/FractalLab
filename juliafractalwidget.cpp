#include "juliafractalwidget.h"
#include "ui_juliafractalwidget.h"

JuliaFractalWidget::JuliaFractalWidget(QWidget *parent) :
    AbstractFractalWidget(parent),
    ui(new Ui::JuliaFractalWidget)
{
    ui->setupUi(this);

    connect(ui->generateButton, SIGNAL(clicked()),
            this, SLOT(generate()));
    connect(ui->resetZoomButton, SIGNAL(clicked()),
            this, SLOT(resetFractalZoom()));
    connect(&m_fractal, SIGNAL(zoomed()), this, SLOT(zoomed()));
    connect(ui->setIterationsButton, SIGNAL(clicked()),
            this, SLOT(setIterations()));
}

JuliaFractalWidget::~JuliaFractalWidget()
{
    delete ui;
}

void JuliaFractalWidget::generate()
{
    updateFractal();
    emit needsRedraw();
}

void JuliaFractalWidget::resetFractalZoom()
{
    m_fractal.resetZoom();
    emit needsRedraw();
}

void JuliaFractalWidget::zoomed()
{
    ui->minCRealInput->setText(QString::number(m_fractal.getMinReal()));
//    ui->maxCRealInput->setText(QString::number(m_fractal.getMaxReal()));
    ui->maxCRealInput->setText(QString("%1").arg(m_fractal.getMaxReal()));
    ui->minCImagInput->setText(QString::number(m_fractal.getMinImag()));
    ui->maxCImagInput->setText(QString::number(m_fractal.getMaxImag()));
}

void JuliaFractalWidget::setIterations()
{
    m_fractal.setIterations(ui->iterationsInput->text().toInt());
    emit needsRedraw();
}

void JuliaFractalWidget::updateFractal()
{
    m_fractal.setIterations(ui->iterationsInput->text().toInt());
    m_fractal.setMinReal(ui->minCRealInput->text().toDouble());
    m_fractal.setMaxReal(ui->maxCRealInput->text().toDouble());
    m_fractal.setMinImag(ui->minCImagInput->text().toDouble());
    m_fractal.setMaxImag(ui->maxCImagInput->text().toDouble());
    m_fractal.setKReal(ui->kRealInput->text().toDouble());
    m_fractal.setKImag(ui->kImagInput->text().toDouble());
}
