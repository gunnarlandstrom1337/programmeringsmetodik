#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <QDebug>


Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{


    QTimer* playerMoving = new QTimer(this);
    connect(playerMoving, &QTimer::timeout,[=]()
            {
                if (player->isAlive()){

                    movingDirection();
                }
                else {
                    movingDirection();
                    playerMoving->stop();
                }
            });
    playerMoving->start(5);

    QTimer* addingEnemies = new QTimer(this);
    connect(addingEnemies, &QTimer::timeout,[=]()
            {
                if (!player->isAlive()){
                    addingEnemies->stop();
                }
                addEnemy();

            });

    addingEnemies->start(400);


}

void Scene::dmgTaken()
{
    QGraphicsPixmapItem* dmgTaken = new QGraphicsPixmapItem(QPixmap(":/Images/Blood_Blur_1.png"));

    dmgTaken->setPos(QPointF(0,0) - QPointF(dmgTaken->boundingRect().width()/2,dmgTaken->boundingRect().height()/2+6));
    dmgTaken->setScale(1.01);

    QTimer* dmgVisual = new QTimer(this);
    if (damageTaken && player->isAlive()){

        connect(dmgVisual, &QTimer::timeout,[=]()
                {

                    delete dmgTaken;
                    damageTaken = false;
                    dmgVisual->stop();
                });

        dmgVisual->start(3000);
        addItem(dmgTaken);
    }
}

void Scene::playerDied()
{
    QGraphicsPixmapItem* deadVisual= new QGraphicsPixmapItem(QPixmap(":/Images/Deathscreen.png"));
    deadVisual->setPos(QPointF(0,0) - QPointF(deadVisual->boundingRect().width()/2,deadVisual->boundingRect().height()/2+6));
    deadVisual->setScale(1.01);
    addItem(deadVisual);


    for(size_t i = 0; i != enemyVector.size()/2; i++){
        delete enemyVector[i];
    }
    dead = true;
}


void Scene::addPlayer()
{
    player = new Player(QPixmap(":/Images/faceDown1.png"));
    player->setPos(0,0);
    player->setScale(1);
    addItem(player);
}

void Scene::addEnemy()
{



    Enemy* tempEnemy = new Enemy();


    connect(tempEnemy,&Enemy::playerCollided,[=](){

        qDebug() << "DMGTAKEN Called\n";
        damageTaken = true;
        dmgTaken();
    });



    // Needed for x to get randomized for some reason

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
    tempEnemy->setPos(spawnXAxis,spawnYAxis);
    tempEnemy->setScale(2.2);
    tempEnemy->setPlayer(player);

    tempEnemy->setX(spawnXAxis);
    tempEnemy->setY(spawnYAxis);

    if(tempEnemy->getX() > player->getXCord()){
        tempEnemy->spawnLeft();
    }
    addItem(tempEnemy);
    enemyVector.push_back(tempEnemy);


}


std::vector<Enemy*> &Scene::getEnemyVec()
{
    return enemyVector;
}

void Scene::movingDirection()
{

    if (!player->isAlive()){
        playerDied();
    }

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
    if (player->isAlive()){



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

