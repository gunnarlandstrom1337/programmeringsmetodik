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
    addItem(player);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        player->moveUp();
        player->setYCord(-10);
        player->setPos(player->getXCord(),player->getYCord());
    }
    if (event->key() == Qt::Key_Down) {

        player->moveDown();
        player->setYCord(10);
        player->setPos(player->getXCord(),player->getYCord());
    }
    if (event->key() == Qt::Key_Right) {

        player->moveRight();
        player->setXCord(10);
        player->setPos(player->getXCord(),player->getYCord());
    }
    if (event->key() == Qt::Key_Left) {

        player->moveLeft();
        player->setXCord(-10);
        player->setPos(player->getXCord(),player->getYCord());
    }
}



void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Scene::keyReleaseEvent(QKeyEvent *event)
{

    if (event->KeyRelease) {
        player->faceUp();
    }
    if (event->KeyRelease) {

        player->faceDown();
    }
    if (event->KeyRelease) {

        player->faceRight();
    }
    if (event->KeyRelease) {

        player->faceLeft();
    }
}

