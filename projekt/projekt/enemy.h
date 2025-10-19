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

signals:

public slots:

private:
    void updateEnemyPixmap();
    bool hasSpawned = false;
    bool isWalkingLeft;
    unsigned short int updateValue = 0;
    QGraphicsPixmapItem* enemyPixmap;
};

#endif // ENEMY_H
