#include "mandelbrotfractalwidget.h"
#include "ui_mandelbrotfractalwidget.h"

MandelbrotFractalWidget::MandelbrotFractalWidget(QWidget *parent) :
    AbstractFractalWidget(parent),
    ui(new Ui::MandelbrotFractalWidget)
{
    ui->setupUi(this);

    updateFractal();
    m_fractal.resetZoom();
    connect(ui->generateButton, SIGNAL(clicked()),
            this, SLOT(generate()));
    connect(ui->resetZoomButton, SIGNAL(clicked()),
            this, SLOT(resetFractalZoom()));
}

MandelbrotFractalWidget::~MandelbrotFractalWidget()
{
    delete ui;
}

void MandelbrotFractalWidget::generate()
{
    updateFractal();
    emit needsRedraw();
}

void MandelbrotFractalWidget::resetFractalZoom()
{
    m_fractal.resetZoom();
    emit needsRedraw();
}

void MandelbrotFractalWidget::updateFractal()
{
    m_fractal.setIterations(ui->iterationsInput->text().toInt());
    m_fractal.setMinReal(ui->minCRealInput->text().toDouble());
    m_fractal.setMaxReal(ui->maxCRealInput->text().toDouble());
    m_fractal.setMinImag(ui->minCImagInput->text().toDouble());
    m_fractal.setMaxImag(ui->maxCImagInput->text().toDouble());
}
