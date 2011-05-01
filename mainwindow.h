#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:


public slots:

    void on_pushButton_clicked(QPaintEvent *event);

private slots:
    void on_graphicsView_destroyed();

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
