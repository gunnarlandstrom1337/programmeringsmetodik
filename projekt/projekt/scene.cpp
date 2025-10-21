#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <time.h>
#include <iostream>


Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{

    std::srand(time(NULL));

    QTimer* playerMoving = new QTimer(this);
    connect(playerMoving, &QTimer::timeout,[=]()
            {
                movingDirection();
            });
    playerMoving->start(5);

}

void Scene::addPlayer()
{
    player = new Player(QPixmap(":/Images/faceDown1.png"));
    player->setPos(-25,-25);
    player->setScale(1);
    addItem(player);
}

void Scene::addEnemy()
{
    enemy = new Enemy();
    int spawnXAxis = std::rand() % 1890;
    //spawnXAxis += -945;
    int spawnYAxis = std::rand() % 845;
    //spawnYAxis += -410;
    std::cout << "Xaxis: " << spawnXAxis << "YAxis: " << spawnYAxis;
    enemy->setPos(spawnXAxis,spawnYAxis);
    enemy->setScale(3);
    addItem(enemy);
}

void Scene::movingDirection()
{


    if (movingUp && !(movingLeft || movingRight || movingDown || movingNorthWest || movingNorthEast || movingSouthEast || movingSouthWest)){
        player->movePlayerUp();
    }
    if (movingDown && !(movingUp || movingLeft || movingRight || movingSouthWest || movingSouthEast || movingNorthEast || movingNorthWest)){
        player->movePlayerDown();
    }
    if (movingLeft && !(movingRight || movingUp || movingDown || movingNorthWest || movingSouthWest || movingNorthEast || movingSouthEast)){
        player->movePlayerLeft();
    }
    if (movingRight && !(movingLeft || movingUp || movingDown || movingNorthEast || movingSouthEast || movingSouthWest || movingNorthWest)){
        player->movePlayerRight();
    }
    if (movingNorthWest && movingUp && movingLeft && !(movingSouthWest || movingNorthEast || movingSouthEast || movingDown || movingRight)){
        player->movePlayerNorthWest();
    }
    if (movingNorthEast && movingUp && movingRight && !(movingSouthWest || movingNorthWest || movingSouthEast ||movingDown || movingLeft)){
        player->movePlayerNorthEast();
    }
    if (movingSouthWest && movingDown && movingLeft && !(movingNorthWest || movingNorthEast || movingSouthEast || movingUp || movingRight)){
        player->movePlayerSouthWest();
    }
    if (movingSouthEast && movingDown && movingRight && !(movingSouthWest || movingNorthEast || movingNorthWest || movingUp || movingLeft)){
        player->movePlayerSouthEast();
    }
    if (!(movingLeft && movingRight && movingUp && movingDown && movingNorthEast && movingNorthWest && movingSouthEast && movingSouthWest)){
        player->setPlayerRunning(false);
    }
}

void Scene::keyPressEvent(QKeyEvent *event)
{

    // North,South,Easter, West
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        movingUp = true;
        //player->movePlayerUp();
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        movingDown = true;
        //player->movePlayerDown();
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        movingLeft = true;
       // player->movePlayerLeft();
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        movingRight = true;
       // player->movePlayerRight();
    }
    if (movingUp && movingRight){ movingNorthEast = true; }
    if (movingUp && movingLeft){ movingNorthWest = true; }
    if (movingDown && movingLeft){ movingSouthWest = true; }
    if (movingDown && movingRight){ movingSouthEast = true; }
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Scene::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        movingUp = false;
        movingNorthEast = false;
        movingNorthWest = false;
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        movingDown = false;
        movingSouthEast = false;
        movingSouthWest = false;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        movingLeft = false;
        movingNorthWest = false;
        movingSouthWest = false;
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        movingRight = false;
        movingNorthEast = false;
        movingSouthEast = false;
    }



}

