#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sierpinskifractalwidget.h"
#include "mandelbrotfractalwidget.h"
#include "juliafractalwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_fractalWidget(0)
{
    ui->setupUi(this);

    connect(ui->saveButton, SIGNAL(clicked()),
            ui->fractalDisplayWidget, SLOT(saveImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fractalSelectionChanged(const QString &fractalSelection)
{
    if (m_fractalWidget != 0)
        delete m_fractalWidget;
    if (fractalSelection == "Sierpinski Triangle") {
        m_fractalWidget = new SierpinskiFractalWidget();
    } else if (fractalSelection == "Mandelbrot Set") {
        m_fractalWidget = new MandelbrotFractalWidget();
    } else if (fractalSelection == "Julia Set") {
        m_fractalWidget = new JuliaFractalWidget();
    }
    ui->fractalWidgetLayout->addWidget(m_fractalWidget);
    ui->fractalDisplayWidget->setFractal(m_fractalWidget->getFractal());
    ui->fractalDisplayWidget->update();
    connect(m_fractalWidget, SIGNAL(needsRedraw()), this, SLOT(redrawFractal()));
}

void MainWindow::redrawFractal()
{
    ui->fractalDisplayWidget->update();
}
