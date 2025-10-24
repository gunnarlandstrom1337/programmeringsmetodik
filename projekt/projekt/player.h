#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QPixmap playerPixmap);

    // Moving
    void movePlayer();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool isPlayerRunning(){ return playerRunning; }

    //called from Scene
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerNorthWest();
    void movePlayerNorthEast();
    void movePlayerSouthWest();
    void movePlayerSouthEast();

    void moveNorthWest();
    void moveNorthEast();
    void moveSouthWest();
    void moveSouthEast();

    // Setters, Getters

    void setPlayerDirection(wchar_t input);
    void setPlayerRunning(bool input);
    void setXCord(double x);
    void setYCord(double y);
    int getXCord();
    int getYCord();

    void hasDied();
    bool isAlive();

    // Hitbox
    void setPlayerHitbox(QGraphicsRectItem* hitbox);
    std::vector<int> getPlayerHitbox();

    // Animations

    //Standing
    QPixmap faceUp();
    QPixmap faceDown();
    QPixmap faceLeft();
    QPixmap faceRight();

    //Running
    QPixmap runUp();
    QPixmap runDown();
    QPixmap runLeft();
    QPixmap runRight();


    void setPlayerHealth(double value);

signals:

public slots:


private:
    // Direction for Pixmap and movement




    std::vector<int> hitboxVec;
    QTimer *movementTimer;
    //QMap<int, bool> keysPressed;
    void updatePlayerPixmap();
    std::string playerDirection;
    bool playerRunning = false;
    int updatePic = 0;
    double playerXCord = 0;
    double playerYCord = 0;

    double playerHealth;
    bool alive;

    QGraphicsRectItem* playerHitbox;

    // x = 20 width, y = 30 height
    //int hitbox_x = 0;
    //int hitbox_x1 = 0;
    //int hitbox_y = 0;
    //int hitbox_y1 = 0;

};

#endif // PLAYER_H
