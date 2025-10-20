#include "player.h"
#include <QTimer>

Player::Player(QPixmap pixmap) : playerDirection(PlayerDirection::Down)
{
    setPixmap(pixmap);

    QTimer* playerGraphicTimer = new QTimer(this);
    connect(playerGraphicTimer, &QTimer::timeout,[=]()
            {
                if(updatePic < 7){
                    updatePic++;
                }
                else {
                    updatePic = 1;
                }
                if (playerRunning == false){

                    playerGraphicTimer->setInterval(90);
                }
                else {
                    updatePlayerPixmap();
                    playerGraphicTimer->setInterval(60);
                }
                 updatePlayerPixmap();
            });

    QTimer* playerMoveTimer = new QTimer(this);
    connect(playerMoveTimer, &QTimer::timeout,[=]()
            {
                movePlayer();
            });

    playerGraphicTimer->start(90);
    playerMoveTimer->start(5);
}

void Player::setUpdateTimer(size_t input)
{
    updateTimer = input;
}

void Player::movePlayer()
{
    if (playerRunning){
        if (playerDirection == Up){
            moveUp();
        }
        if (playerDirection == Down){
            moveDown();
        }
        if (playerDirection == Left){
            moveLeft();
        }
        if (playerDirection == Right){
            moveRight();
        }
    }
}


void Player::movePlayerUp()
{
    playerRunning = true;
    playerDirection = Up;
    movePlayer();
}
void Player::movePlayerDown()
{
    playerRunning = true;
    playerDirection = Down;
    movePlayer();
}

void Player::movePlayerLeft()
{
    playerRunning = true;
    playerDirection = Left;
    movePlayer();
}

void Player::movePlayerRight()
{
    playerRunning = true;
    playerDirection = Right;
    movePlayer();
}

void Player::moveUp()
{
    if (getYCord() > -410){
        moveBy(0,-1);
        setYCord(-1);
        updatePlayerPixmap();
    }
}

void Player::moveDown()
{
    if (getYCord() < 435){
        moveBy(0,1);
        setYCord(1);
        updatePlayerPixmap();
    }
}

void Player::moveLeft()
{
    if(getXCord() > -945){
        moveBy(-1,0);
        setXCord(-1);
        updatePlayerPixmap();
    }
}

void Player::moveRight()
{
    if(getXCord() < 945){
        moveBy(1,0);
        setXCord(1);
        updatePlayerPixmap();
    }
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


void Player::setPlayerRunning(bool input)
{
    playerRunning = input;
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

    if (!playerRunning){


        if(playerDirection == Up){
            setPixmap(QPixmap(faceUp()));
        }
        else if (playerDirection == Down){
            setPixmap(QPixmap(faceDown()));
        }
        else if (playerDirection == Left){
            setPixmap(QPixmap(faceLeft()));
        }
        else if (playerDirection == Right){
            setPixmap(QPixmap(faceRight()));
        }
    }
    if (playerRunning){

        if(playerDirection == Up){
            setPixmap(QPixmap(runUp()));
        }
        if(playerDirection == Down){
            setPixmap(QPixmap(runDown()));
        }
        else if(playerDirection == Left){
            setPixmap(QPixmap(runLeft()));
        }
        else if(playerDirection == Right){
            setPixmap(QPixmap(runRight()));
        }
    }
}

QPixmap Player::faceDown()
{
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
        updatePic = 1;
        return QPixmap(":/Images/faceDown6.png");
    }
}
QPixmap Player::faceUp()
{
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
        updatePic = 1;
        return QPixmap(":/Images/faceUp6.png");
    }
}
QPixmap Player::faceLeft()
{
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
        updatePic = 1;
        return QPixmap(":/Images/faceLeft6.png");
    }
}
QPixmap Player::faceRight()
{
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
        updatePic = 1;
        return QPixmap(":/Images/faceRight6.png");
    }

}

QPixmap Player::runDown(){
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
        updatePic = 1;
        return QPixmap(":/Images/runDown6.png");
    }

}
QPixmap Player::runUp(){


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
        updatePic = 1;
        return QPixmap(":/Images/runUp6.png");
    }

}
QPixmap Player::runLeft(){

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
        updatePic = 1;
        return QPixmap(":/Images/runLeft6.png");
    }
}

QPixmap Player::runRight(){

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
        updatePic = 1;
        return QPixmap(":/Images/runRight6.png");
    }
}








