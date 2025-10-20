#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QPixmap playerPixmap);

    void setUpdateTimer(size_t input);



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

    // Unused
    void moveNorthWest();
    void moveNorthEast();
    void moveSouthWest();
    void moveSouthEast();

    // Setters, Getters
    void setPlayerRunning(bool input);
    void setXCord(int x);
    void setYCord(int y);
    int getXCord();
    int getYCord();

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



signals:

public slots:


private:
    // Direction for Pixmap and movement
    enum PlayerDirection{
        Up,
        Down,
        Left,
        Right
    };




    QTimer *movementTimer;
    //QMap<int, bool> keysPressed;
    void updatePlayerPixmap();
    PlayerDirection playerDirection;
    bool playerRunning = false;
    int updatePic = 0;
    int playerXCord = 0;
    int playerYCord = 0;
    size_t updateTimer = 20;

};

#endif // PLAYER_H
