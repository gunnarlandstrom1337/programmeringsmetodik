#include "enemy.h"
#include <QTimer>
#include "player.h"

Enemy::Enemy()
{
    //spawnAnimation();

    QTimer* enemyTimer = new QTimer(this);

    connect(enemyTimer, &QTimer::timeout,[=]()
            {
                updateEnemyPixmap();
                if (hasSpawned){
                    enemyTimer->setInterval(60);
                    enemyChasePlayer();
                }
            });


    enemyTimer->start(300);
}

void Enemy::spawnAnimation()
{
    updateEnemyPixmap();
}

double Enemy::getX()
{
    return x;
}

double Enemy::getY()
{
    return y;
}

void Enemy::setX(double value)
{
    x = value;
}

void Enemy::setY(double value)
{
    y = value;
}

void Enemy::setPlayer(Player *player)
{
    target = player;
}

void Enemy::enemyChasePlayer()
{
    //checkCollision();

    // X axis
    if (x < target->getXCord()){
        setX(getX()+5);
        moveBy(5,0);
        isWalkingLeft = false;
    }
    else {
        isWalkingLeft = true;
        setX(getX()-5);
        moveBy(-5,0);
    }
    /*
    if (enemy->getX() > player->getXCord()){
        enemy->setX(enemy->getX()-1);
    }
    */
    // Y axis
    if (getY() < target->getYCord()){
        setY(getY()+5);
        moveBy(0,5);
    }
    else {
        setY(getY()-5);
        moveBy(0,-5);
    }
}



// Changing enemyAnimations
void Enemy::updateEnemyPixmap()
{

    if(!hasSpawned){
        updateValue++;
        if (!hasSpawned && (updateValue == 1)){
            setPixmap(QPixmap(":/Images/enemySpawn1.png"));
        }
        if (!hasSpawned && (updateValue == 2)){
            setPixmap(QPixmap(":/Images/enemySpawn2.png"));

        }
        if (!hasSpawned && (updateValue == 3)){
            setPixmap(QPixmap(":/Images/enemySpawn3.png"));

        }
        if (!hasSpawned && (updateValue == 4)){
            setPixmap(QPixmap(":/Images/enemySpawn4.png"));
            hasSpawned = true;
            updateValue = 0;
        }
    }
    if (hasSpawned){
        updateValue++;
        if (isWalkingLeft == false){


            if (updateValue == 1){
                setPixmap(QPixmap(":/Images/enemyWalk1.png"));
            }
            if (updateValue == 2){
                setPixmap(QPixmap(":/Images/enemyWalk2.png"));
            }
            if (updateValue == 3){
                setPixmap(QPixmap(":/Images/enemyWalk3.png"));
            }
            if (updateValue == 4){
                setPixmap(QPixmap(":/Images/enemyWalk4.png"));
            }
            if (updateValue == 5){
                setPixmap(QPixmap(":/Images/enemyWalk5.png"));
            }
            if (updateValue == 6){
                setPixmap(QPixmap(":/Images/enemyWalk6.png"));
                updateValue = 0;
            }
        }
        else {

            if (updateValue == 1){
                setPixmap(QPixmap(":/Images/enemyWalkLeft1.png"));
            }
            if (updateValue == 2){
                setPixmap(QPixmap(":/Images/enemyWalkLeft2.png"));
            }
            if (updateValue == 3){
                setPixmap(QPixmap(":/Images/enemyWalkLeft3.png"));
            }
            if (updateValue == 4){
                setPixmap(QPixmap(":/Images/enemyWalkLeft4.png"));
            }
            if (updateValue == 5){
                setPixmap(QPixmap(":/Images/enemyWalkLeft5.png"));
            }
            if (updateValue == 6){
                setPixmap(QPixmap(":/Images/enemyWalkLeft6.png"));
                updateValue = 0;
            }
        }



    }
}
