#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <time.h>
#include <iostream>


Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{


    QTimer* playerMoving = new QTimer(this);
    connect(playerMoving, &QTimer::timeout,[=]()
            {
                movingDirection();



            });
    playerMoving->start(5);

    QTimer* addingEnemies = new QTimer(this);
    connect(addingEnemies, &QTimer::timeout,[=]()
            {
                addEnemy();
            });
    addingEnemies->start(3000);


}

void Scene::addPlayer()
{
    player = new Player(QPixmap(":/Images/faceDown1.png"));
    player->setPos(0,0);
    player->setScale(1);
    addItem(player);
    QGraphicsRectItem* tempHitbox = addRect(player->getXCord()+15,player->getYCord()+10,20,30,QPen(Qt::red));
    player->setPlayerHitbox(tempHitbox);

}

void Scene::addEnemy()
{
    std::srand(time(NULL));
    Enemy* tempEnemy;
    tempEnemy = new Enemy();

    // Needed for x to get randomized for some reason
    int garbagerand = std::rand();

    int spawnXAxis = 0;
    int spawnYAxis = 0;
    spawnXAxis = std::rand() % 1890;
    spawnXAxis += -945;
    spawnYAxis = std::rand() % 845;
    spawnYAxis += -410;
    while (spawnXAxis < player->getXCord()+350 && spawnXAxis > player->getXCord()-350){
        spawnXAxis = std::rand() % 1890;
        spawnXAxis += -945;
    }
    std::cout << "X AXIS: " << spawnXAxis << "Y AXIS: " << spawnYAxis;
    tempEnemy->setPos(spawnXAxis,spawnYAxis);
    tempEnemy->setScale(3);
    tempEnemy->setPlayer(player);




    tempEnemy->setX(spawnXAxis);
    tempEnemy->setY(spawnYAxis);


    addItem(tempEnemy);
    enemyVector.push_back(tempEnemy);


}

std::vector<Enemy*> &Scene::getEnemyVec()
{
    return enemyVector;
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

