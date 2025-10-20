#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>


Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{


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
    //Random pos Left and right, up and down
    enemy->setPos(-150,0);
    enemy->setScale(3);
    addItem(enemy);
}

void Scene::keyPressEvent(QKeyEvent *event)
{

    // North,South,Easter, West
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        player->setPlayerRunning(true);
        movingUp = true;
        player->movePlayerUp();
        if (event->isAutoRepeat()){
        }
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        movingDown = true;
        player->setPlayerRunning(true);
        player->movePlayerDown();
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        movingLeft = true;
        player->setPlayerRunning(true);
        player->movePlayerLeft();
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        movingRight = true;
        player->setPlayerRunning(true);
        player->movePlayerRight();
    }


    // **FUNKAR INTE**
    /*
     *
    // NortWest, NorthEast, SouthWest, SouthEast
    if ((event->key() == Qt::Key_Up && event->key() == Qt::Key_Left) || (event->key() == Qt::Key_W && event->key() == Qt::Key_A)){
        player->setPlayerRunning(true);
        //player->moveNorthWest();
    }
    if ((event->key() == Qt::Key_Up && event->key() == Qt::Key_Right) || (event->key() == Qt::Key_W && event->key() == Qt::Key_D)){
        player->setPlayerRunning(true);
        //player->moveNorthEast();
    }
    if ((event->key() == Qt::Key_Down && event->key() == Qt::Key_Left) || (event->key() == Qt::Key_S && event->key() == Qt::Key_A)){
        player->setPlayerRunning(true);
        //player->moveSouthWest();
    }
    if ((event->key() == Qt::Key_Down && event->key() == Qt::Key_Right) || (event->key() == Qt::Key_S && event->key() == Qt::Key_D)){
        player->setPlayerRunning(true);
       // player->moveSouthEast();
    }
    */
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Scene::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        movingUp = false;
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        movingDown = false;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        movingLeft = false;
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        movingRight = false;
    }
    if (!movingDown && !movingLeft && !movingRight && !movingUp){
        player->setPlayerRunning(false);
    }

}

