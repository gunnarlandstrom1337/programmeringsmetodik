#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>


Scene::Scene(QObject *parent) :QGraphicsScene(parent)
{


    //player->setPos(QPointF(-25,-25));
}

void Scene::addPlayer()
{
    player = new Player(QPixmap(":/Images/faceDown1.png"));
    player->setPos(-25,-25);
    addItem(player);
}

void Scene::addEnemy()
{
    enemy = new Enemy();
    enemy->setPos(-150,0);
    enemy->setScale(3);
    addItem(enemy);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    // North,South,Easter, West
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        player->setPlayerRunning(true);
        player->moveUp();
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        player->setPlayerRunning(true);
        player->moveDown();

    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        player->setPlayerRunning(true);
        player->moveRight();
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        player->setPlayerRunning(true);
        player->moveLeft();
    }
    // Northeast, Northwest, Southeast, SouthWest
    if ((event->key() == Qt::Key_Up && event->key() == Qt::Key_Left) || (event->key() == Qt::Key_W && event->key() == Qt::Key_A)){
        player->setPlayerRunning(true);
        player->moveNorthWest();
    }
    if ((event->key() == Qt::Key_Up && event->key() == Qt::Key_Right) || (event->key() == Qt::Key_W && event->key() == Qt::Key_D)){
        player->setPlayerRunning(true);
        player->moveNorthEast();
    }
    if ((event->key() == Qt::Key_Down && event->key() == Qt::Key_Left) || (event->key() == Qt::Key_S && event->key() == Qt::Key_A)){
        player->setPlayerRunning(true);
        player->moveSouthWest();
    }
    if ((event->key() == Qt::Key_Down && event->key() == Qt::Key_Right) || (event->key() == Qt::Key_S && event->key() == Qt::Key_D)){
        player->setPlayerRunning(true);
        player->moveSouthEast();
    }
}



void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Scene::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {

        player->standUp();

    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {

        player->standDown();
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {

        player->standRight();
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        player->setPlayerRunning(false);
        player->standLeft();
    }
}

