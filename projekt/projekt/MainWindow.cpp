#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Kartan
    scene = new Scene(this);

    scene->setSceneRect(-320,-200,720,480);
    QGraphicsPixmapItem* mapItem = new QGraphicsPixmapItem(QPixmap(":/Images/map1.png"));
    scene->addItem(mapItem);
    mapItem->setPos(QPointF(0,0) - QPointF(mapItem->boundingRect().width()/2,mapItem->boundingRect().height()/2));

    // Gridline
    //scene->addLine(-400,0,400,0,QPen(Qt::red));
    //scene->addLine(0,-400,0,400,QPen(Qt::red));



    ui->graphicsView->setScene(scene);
    scene->addPlayer();

}

MainWindow::~MainWindow()
{
    delete ui;
}
