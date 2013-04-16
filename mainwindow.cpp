#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sierpinskifractalwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_fractalWidget(0)
{
    ui->setupUi(this);
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
