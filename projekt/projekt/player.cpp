#include "player.h"
#include <QTimer>

Player::Player(QPixmap pixmap) : playerPosition(PlayerPosition::Down), playerDirection('S')
{
    setPixmap(pixmap);

    QTimer* playerDirectionTimer = new QTimer(this);
    connect(playerDirectionTimer, &QTimer::timeout,[=]()
            {
                if(updatePic < 7){
                    updatePic++;
                }
                else {
                    updatePic = 1;
                }
                if (playerRunning == false){
                    updatePlayerPixmap();
                    //setUpdateTimer(150);
                    playerDirectionTimer->setInterval(90);
                }
                else {
                    playerDirectionTimer->setInterval(20);
                }
            });

    playerDirectionTimer->start(updateTimer);

    /* ROTATION AND FALLING ANIMATION
    groundPosition = scenePos().y() + 290;
    yAnimation = new QPropertyAnimation(this,"y", this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);

    yAnimation->setDuration(1000);
    yAnimation->start();
    */

}


/* Falling char and rotation
qreal Player::rotation() const
{
    return m_rotation;
}

void Player::setRotation(qreal newRotation)
{
    m_rotation = newRotation;
}
*/


qreal Player::x() const
{

    return m_x;
}

void Player::setX(qreal x)
{
    moveBy(0,x-m_x);
    m_x = x;
}



qreal Player::y() const
{
    return m_y;
}

void Player::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void Player::setUpdateTimer(size_t input)
{
    updateTimer = input;
}

void Player::moveUp()
{
    setPlayerDirection('W');

    if (getYCord() > -410){
        moveBy(0,-5);
        setYCord(-5);

        updatePlayerPixmap();
    }
    updatePlayerPixmap();
}

void Player::moveDown()
{
    setPlayerDirection('S');
    if (getYCord() < 435){
        moveBy(0,5);
        setYCord(5);
    }
    updatePlayerPixmap();
}

void Player::moveLeft()
{
    setPlayerDirection('A');
    if(getXCord() > -945){
        moveBy(-5,0);
        setXCord(-5);
        updatePlayerPixmap();
    }
    updatePlayerPixmap();
}

void Player::moveRight()
{
    setPlayerDirection('D');
    if(getXCord() < 945){
        moveBy(5,0);
        setXCord(5);
        updatePlayerPixmap();
    }
    updatePlayerPixmap();
}

void Player::moveNorthWest()
{
    if(getXCord() > 945 && getYCord() > -410){
        moveBy(-5,-5);
        setXCord(-5);
        setYCord(-5);
        updatePlayerPixmap();
    }
}

void Player::moveNorthEast()
{
    if(getXCord() > -945 && getYCord() > -410){
        moveBy(5,-5);
        setXCord(5);
        setYCord(-5);
        updatePlayerPixmap();
    }
}

void Player::moveSouthWest()
{
    if(getXCord() > -945 && getYCord() < 435){
        moveBy(-5,5);
        setXCord(-5);
        setYCord(5);
        updatePlayerPixmap();
    }
}

void Player::moveSouthEast()
{
    if(getXCord() < 945 && getYCord() > 435){
        moveBy(5,-5);
        setXCord(5);
        setYCord(-5);
        updatePlayerPixmap();
    }

}

void Player::standUp()
{
    playerRunning = false;
}

void Player::standDown()
{
    playerRunning = false;
}

void Player::standLeft()
{
    //playerRunning = false;
}

void Player::standRight()
{
    playerRunning = false;
}

void Player::setPlayerRunning(bool input)
{
    playerRunning = input;
}

void Player::setPlayerDirection(char input)
{
    playerDirection = input;
}


void Player::setXCord(int x)
{
    playerXCord += x;
}

void Player::setYCord(int y)
{
    playerYCord += y;
}

int Player::getXCord()
{
    return playerXCord;
}

int Player::getYCord()
{
    return playerYCord;
}






// Changing charanimations
void Player::updatePlayerPixmap()
{

    if(playerDirection == 'W' && playerRunning == false){
        setPixmap(QPixmap(faceUp()));
        playerPosition = PlayerPosition::Up;

    }
    else if (playerDirection == 'S' && playerRunning == false){
        setPixmap(QPixmap(faceDown()));
        playerPosition = PlayerPosition::Down;
    }
    else if (playerDirection == 'A' && playerRunning == false){
        setPixmap(QPixmap(faceLeft()));
        playerPosition = PlayerPosition::Left;
    }
    else if (playerDirection == 'D' && playerRunning == false){
        setPixmap(QPixmap(faceRight()));
        playerPosition = PlayerPosition::Right;
    }
    else if(playerDirection == 'W' && playerRunning == true){
        setPixmap(QPixmap(runUp()));
        playerPosition = PlayerPosition::Up;
    }
    else if(playerDirection == 'S' && playerRunning == true){
        setPixmap(QPixmap(runDown()));
        playerPosition = PlayerPosition::Down;
    }
    else if(playerDirection == 'A' && playerRunning == true){
        setPixmap(QPixmap(runLeft()));
        playerPosition = PlayerPosition::Left;
    }
    else if(playerDirection == 'D' && playerRunning == true){
        setPixmap(QPixmap(runRight()));
        playerPosition = PlayerPosition::Right;
    }
    else {
        playerRunning = false;
        playerPosition = PlayerPosition::Down;
        setPixmap(QPixmap(faceDown()));
    }

}

QPixmap Player::faceDown()
{
    if (updatePic < 7 && playerRunning == false){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/faceDown1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/faceDown2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/faceDown3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/faceDown4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/faceDown5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/faceDown6.png");
        }
        else {

            return QPixmap(":/Images/faceDown1.png");
        }

    }
    else {

        return QPixmap(":/Images/faceDown1.png");
    }

}
QPixmap Player::faceUp()
{
    if (updatePic < 7 && playerRunning == false){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/faceUp1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/faceUp2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/faceUp3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/faceUp4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/faceUp5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/faceUp6.png");
        }
        else {

            return QPixmap(":/Images/faceUp1.png");
        }

    }
    else {

        return QPixmap(":/Images/faceUp1.png");
    }
}
QPixmap Player::faceLeft()
{
    if (updatePic < 7 && playerRunning == false){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/faceLeft1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/faceLeft2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/faceLeft3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/faceLeft4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/faceLeft5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/faceLeft6.png");
        }
        else {

            return QPixmap(":/Images/faceLeft1.png");
        }

    }
    else {

        return QPixmap(":/Images/faceLeft1.png");
    }
}
QPixmap Player::faceRight()
{
    if (updatePic < 7 && playerRunning == false){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/faceRight1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/faceRight2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/faceRight3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/faceRight4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/faceRight5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/faceRight6.png");
        }
        else {

            return QPixmap(":/Images/faceRight1.png");
        }

    }
    else {

        return QPixmap(":/Images/faceRight1.png");
    }
}

QPixmap Player::runDown(){
    if (updatePic < 7){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/runDown1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/runDown2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/runDown3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/runDown4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/runDown5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/runDown6.png");
        }
        else {

            return QPixmap(":/Images/runDown1.png");
        }

    }
    else {

        return QPixmap(":/Images/runDown1.png");
    }
}
QPixmap Player::runUp(){
    if (updatePic < 7){

        if (updatePic == 1)
        {

            return QPixmap(":/Images/runUp1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/runUp2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/runUp3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/runUp4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/runUp5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/runUp6.png");
        }
        else {

            return QPixmap(":/Images/runUp1.png");
        }

    }
    else {

        return QPixmap(":/Images/runUp1.png");
    }
}
QPixmap Player::runLeft(){
    if (updatePic < 7){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/runLeft1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/runLeft2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/runLeft3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/runLeft4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/runLeft5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/runLeft6.png");
        }
        else {

            return QPixmap(":/Images/runLeft1.png");
        }

    }
    else {

        return QPixmap(":/Images/runLeft1.png");
    }

}
QPixmap Player::runRight(){
    if (updatePic < 7){


        if (updatePic == 1)
        {

            return QPixmap(":/Images/runRight1.png");
        }
        else if (updatePic == 2)
        {

            return QPixmap(":/Images/runRight2.png");
        }
        else if (updatePic == 3)
        {

            return QPixmap(":/Images/runRight3.png");
        }
        else if (updatePic == 4)
        {

            return QPixmap(":/Images/runRight4.png");

        } else if (updatePic == 5)
        {

            return QPixmap(":/Images/runRight5.png");

        } else if (updatePic == 6)
        {

            return QPixmap(":/Images/runRight6.png");
        }
        else {

            return QPixmap(":/Images/runRight1.png");
        }

    }
    else {

        return QPixmap(":/Images/runRight1.png");
    }

}








