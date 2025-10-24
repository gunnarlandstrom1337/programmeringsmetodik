#include "enemy.h"
#include <QTimer>
#include "player.h"
#include <QDebug>

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

    x += value;
}

void Enemy::setY(double value)
{

    y += value;
}

void Enemy::setPlayer(Player *player)
{
    target = player;
}

void Enemy::randomizePushback()
{
    int pushDirection = rand() % 4;
    if (pushDirection == 0){
        setX(4);
        setY(4);
        moveBy(4,4);

    }
    if (pushDirection == 1){
        setX(4);
        setY(-4);
        moveBy(4,-4);

    }
    if (pushDirection == 2){
        setX(-4);
        setY(4);
        moveBy(-4,4);
    }
    if (pushDirection == 3){
        setX(-4);
        setY(-4);
        moveBy(-4,-4);
    }

}

void Enemy::playerHit(double value)
{

    target->setPlayerHealth(value);

}

void Enemy::pushEnemyOut(double xvalue, double yvalue)
{

    if (xvalue < 0){
        setX(20);
        moveBy(20,0);
    }
    else {
        setX(-20);
        moveBy(-20,0);
    }
    if (yvalue < 0){
        setY(20);
        moveBy(0,20);
    }
    if (yvalue > 0){
        setY(-20);
        moveBy(0,-20);
    }

}

void Enemy::spawnLeft()
{
    isSpawningLeft = false;
}


void Enemy::enemyChasePlayer()
{

    if (target->isAlive()){
        double tempY =0;
        double tempX = 0;

        // X axis
        if (x < target->getXCord()){
            isWalkingLeft = false;
            setX(4);
            moveBy(4,0);
            tempX = 4;
        }
        else {
            isWalkingLeft = true;
            setX(-4);
            moveBy(-4,0);
            tempX = -4;
        }

        if (getY() < target->getYCord()){
            setY(3.2);
            moveBy(0,3.2);
            tempY = 3.2;
        }
        else {
            setY(-3.2);
            moveBy(0,-3.2);
            tempY = -3.2;
        }

        if (playerCollision()){
            emit playerCollided();
            qDebug() << "Collision detected on player!\n";
            playerHit(5);
            pushEnemyOut(tempX,tempY);
        }
        if (enemyCollision()){
            emit enemyCollided();
            //qDebug() << "Collision detected on enemie!\n";
            randomizePushback();
        }

    }
    else {

    }
}

bool Enemy::enemyCollision()
{
    //qDebug() << "Checking Collision\n";
    QList<QGraphicsItem*> collidingList = this->collidingItems();

    foreach (QGraphicsItem* item, collidingList){
        Enemy* enemyCollision = dynamic_cast<Enemy*>(item);

        if(enemyCollision){

            return true;
        }
    }
    return false;
}

bool Enemy::playerCollision()
{
    //qDebug() << "Checking Collision\n";
    QList<QGraphicsItem*> collidingList = this->collidingItems();

    foreach (QGraphicsItem* item, collidingList){
        Player* playerCollision = dynamic_cast<Player*>(item);

        if(playerCollision){
            return true;
        }
    }
    return false;
}




// Changing enemyAnimations
void Enemy::updateEnemyPixmap()
{

    if(!hasSpawned && isSpawningLeft){
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
    else if (!hasSpawned && !isSpawningLeft){
        updateValue++;
        if (!hasSpawned && (updateValue == 1)){
            setPixmap(QPixmap(":/Images/enemySpawn1.png"));
        }
        if (!hasSpawned && (updateValue == 2)){
            setPixmap(QPixmap(":/Images/enemySpawnLeft1.png"));

        }
        if (!hasSpawned && (updateValue == 3)){
            setPixmap(QPixmap(":/Images/enemySpawnLeft2.png"));

        }
        if (!hasSpawned && (updateValue == 4)){
            setPixmap(QPixmap(":/Images/enemySpawnLeft3.png"));
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
