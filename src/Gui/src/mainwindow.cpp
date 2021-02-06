#include <ui_mainwindow.h>
#include <mainwindow.hpp>

#include <DrawField.hpp>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  mDrawField.reset(new DrawField(this));
}

MainWindow::~MainWindow()
{
  delete ui;
}
