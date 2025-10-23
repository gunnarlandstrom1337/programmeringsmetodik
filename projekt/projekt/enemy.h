#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    void spawnAnimation();
    std::pair<int,int> spawnPosition();
    void huntPlayer();

    //Setters n Getters
    double getX();
    double getY();
    void setX(double value);
    void setY(double value);
    void setPlayer(Player* player);

    void enemyChasePlayer();

    ~Enemy() = default;

signals:

public slots:

private:
    //Checkers
    void updateEnemyPixmap();
    bool isSpawningLeft;
    bool hasSpawned = false;
    bool isWalkingLeft;
    bool isDead;

    // Cordinate
    double x;
    double y;

    unsigned int health;

    enum EnemyDirection{
        Left,
        Right
    };

    Player* target;

    void updateEnemyPixMap();
    EnemyDirection enemyDirection;
    unsigned short int updateValue = 0;
    QGraphicsPixmapItem* enemyPixmap;
};

#endif // ENEMY_H
