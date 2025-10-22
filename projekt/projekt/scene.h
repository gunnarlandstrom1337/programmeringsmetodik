#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMap>
#include "player.h"
#include "enemy.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void addPlayer();
    void addEnemy();
    std::vector<Enemy*>& getEnemyVec();

signals:

public slots:
private:
    Player* player;
    Enemy* enemy;

    std::vector<Enemy*> enemyVector;

    void movingDirection();
    bool movingUp = false;
    bool movingDown = false;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingNorthEast = false;
    bool movingNorthWest = false;
    bool movingSouthEast = false;
    bool movingSouthWest = false;




    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // SCENE_H
