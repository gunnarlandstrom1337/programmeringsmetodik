#ifndef PLAYER_H
#define PLAYER_H

#include <QPropertyAnimation>
#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    /* RORATIONAL MOVEMENT AND FALLING
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)


*/
    Q_PROPERTY(qreal x READ x WRITE setX)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit Player(QPixmap playerPixmap);

    void setUpdateTimer(size_t input);



    // Moving
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveNorthWest();
    void moveNorthEast();
    void moveSouthWest();
    void moveSouthEast();

    // Standing
    void standUp();
    void standDown();
    void standLeft();
    void standRight();

    // Setters, Getters
    void setPlayerRunning(bool input);
    void setPlayerDirection(char input);
    void setXCord(int x);
    void setYCord(int y);
    int getXCord();
    int getYCord();

    qreal y() const;
    void setY(qreal y);
    qreal x() const;
    void setX(qreal x);
    /* ROTATIONAL MOVEMENT AND FALLING

    ;
    qreal rotation() const;
    void setRotation(qreal newRotation);
    */

    // Animations
    QPixmap faceUp();
    QPixmap faceDown();
    QPixmap faceLeft();
    QPixmap faceRight();
    QPixmap runUp();
    QPixmap runDown();
    QPixmap runLeft();
    QPixmap runRight();




signals:

public slots:


private:
    enum PlayerPosition{
        Up,
        Down,
        Left,
        Right
    };


    void updatePlayerPixmap();
    PlayerPosition playerPosition;
    char playerDirection; // W : UP, S: down, A : left, D : right
    bool playerRunning = false;
    int updatePic = 0;
    int playerXCord = 0;
    int playerYCord = 0;
    size_t updateTimer = 20;


    /* ROTATIONAL MOVEMENT AND FALLING
    qreal m_rotation;


    qreal groundPosition;

    QPropertyAnimation* rotationAnimation;
    */
    qreal m_y;
    qreal m_x;
    QPropertyAnimation* yAnimation;

};

#endif // PLAYER_H
