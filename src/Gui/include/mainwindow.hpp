#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <Figure.hpp>
#include <DrawField.hpp>

#include <QMainWindow>

#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<DrawField> mDrawField;

};

#endif // MAINWINDOW_HPP
