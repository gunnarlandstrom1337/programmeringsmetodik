#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);






    //Kartan
    sceneMap = new Scene(this);
    sceneMap->setSceneRect(-960,-544,1920,1088);
    QGraphicsPixmapItem* mapItem = new QGraphicsPixmapItem(QPixmap(":/Images/map1.png"));
    sceneMap->addItem(mapItem);
    mapItem->setPos(QPointF(0,0) - QPointF(mapItem->boundingRect().width()/2,mapItem->boundingRect().height()/2));

    // Camera
    QGraphicsPixmapItem* camera = new QGraphicsPixmapItem(QPixmap(":/Images/Cameralens.png"));
    camera->setPos(0,0);
    //Camera* cameratest = new Camera();


    // Gridline
    //sceneMap->addLine(-400,0,400,0,QPen(Qt::red));
    //sceneMap->addLine(0,-400,0,400,QPen(Qt::red));

    ui->graphicsView->setScene(sceneMap);
    //sceneMap->addItem(camera);



    sceneMap->addPlayer();



    std::cout << "VECTORSIZE: " << sceneMap->getEnemyVec().size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

