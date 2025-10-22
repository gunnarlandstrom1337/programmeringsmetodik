#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void on_startGameButton_clicked();

private:
    Ui::MainWindow *ui;
    Scene* sceneMap;
    Scene* sceneCamera;
    size_t counter = 0;
    size_t amountOfEnemies = 0;




    // QMainWindow interface
public:
};
#endif // WIDGET_H
