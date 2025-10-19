#include "enemy.h"
#include <QTimer>

Enemy::Enemy()
{
    //spawnAnimation();

    QTimer* enemyTimer = new QTimer(this);

    connect(enemyTimer, &QTimer::timeout,[=]()
            {
                updateEnemyPixmap();
                if (hasSpawned){
                    enemyTimer->setInterval(100);
                }
            });


    enemyTimer->start(300);
}

void Enemy::spawnAnimation()
{
    updateEnemyPixmap();
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
}
