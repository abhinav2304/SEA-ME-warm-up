#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <vector>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    game test_game;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    int CAR_count = 2;
    QLabel *CAR_ptr[2];
    bool keys[2][4] = {false};

public slots:
    void update();

private:
    QPixmap CAR_img[2];
    QTransform CAR_rot[2];

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
