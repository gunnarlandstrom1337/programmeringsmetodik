#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy();
    void spawnAnimation();
    std::pair<int,int> spawnPosition();

signals:

public slots:

private:
    void updateEnemyPixmap();
    bool isSpawningLeft;
    bool hasSpawned = false;
    bool isWalkingLeft;
    bool isDead;

    unsigned int health;

    enum EnemyDirection{
        Left,
        Right
    };

    void updateEnemyPixMap();
    EnemyDirection enemyDirection;
    unsigned short int updateValue = 0;
    QGraphicsPixmapItem* enemyPixmap;
};

#endif // ENEMY_H
