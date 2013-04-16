#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abstractfractalwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void fractalSelectionChanged(const QString& fractalSelection);
    void redrawFractal();

private:
    Ui::MainWindow *ui;
    AbstractFractalWidget* m_fractalWidget;
};

#endif // MAINWINDOW_H
