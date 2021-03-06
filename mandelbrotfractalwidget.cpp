#include "mandelbrotfractalwidget.h"
#include "ui_mandelbrotfractalwidget.h"

MandelbrotFractalWidget::MandelbrotFractalWidget(QWidget *parent) :
    AbstractFractalWidget(parent),
    ui(new Ui::MandelbrotFractalWidget)
{
    ui->setupUi(this);

//    m_fractal.resetZoom();
//    updateFractal();

    connect(ui->generateButton, SIGNAL(clicked()),
            this, SLOT(generate()));
    connect(ui->resetZoomButton, SIGNAL(clicked()),
            this, SLOT(resetFractalZoom()));
    connect(&m_fractal, SIGNAL(zoomed()), this, SLOT(zoomed()));
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

void MandelbrotFractalWidget::zoomed()
{
    ui->minCRealInput->setText(QString::number(m_fractal.getMinReal()));
    ui->maxCRealInput->setText(QString::number(m_fractal.getMaxReal()));
    ui->minCImagInput->setText(QString::number(m_fractal.getMinImag()));
    ui->maxCImagInput->setText(QString::number(m_fractal.getMaxImag()));
}

void MandelbrotFractalWidget::updateFractal()
{
    m_fractal.setIterations(ui->iterationsInput->text().toInt());
    m_fractal.setMinReal(ui->minCRealInput->text().toDouble());
    m_fractal.setMaxReal(ui->maxCRealInput->text().toDouble());
    m_fractal.setMinImag(ui->minCImagInput->text().toDouble());
    m_fractal.setMaxImag(ui->maxCImagInput->text().toDouble());
}
