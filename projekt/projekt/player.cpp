#include "player.h"
#include <QTimer>
#include <QPainter>

Player::Player(QPixmap pixmap) : hitboxVec(4), playerDirection("S"), playerRunning(false)
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
                updatePlayerPixmap();
            });
    playerGraphicTimer->start(80);

}

void Player::movePlayer()
{
    if (playerRunning){


        if (playerDirection == "N"){
            moveUp();
        }
        if (playerDirection == "S"){
            moveDown();
        }
        if (playerDirection == "W"){
            moveLeft();
        }
        if (playerDirection == "E"){
            moveRight();
        }
        if (playerDirection == "NW"){
            moveNorthWest();
        }
        if (playerDirection == "NE"){
            moveNorthEast();
        }
        if (playerDirection == "SW"){
            moveSouthWest();
        }
        if (playerDirection == "SE"){
            moveSouthEast();
        }
    }
}


void Player::movePlayerUp()
{
    playerRunning = true;
    playerDirection = "N";
    movePlayer();
}
void Player::movePlayerDown()
{
    playerRunning = true;
    playerDirection = "S";
    movePlayer();
}

void Player::movePlayerLeft()
{
    playerRunning = true;
    playerDirection = "W";
    movePlayer();
}

void Player::movePlayerRight()
{
    playerRunning = true;
    playerDirection = "E";
    movePlayer();
}

void Player::movePlayerNorthWest()
{
    playerRunning = true;
    playerDirection = "NW";
    movePlayer();

}

void Player::movePlayerNorthEast()
{
    playerRunning = true;
    playerDirection = "NE";
    movePlayer();
}

void Player::movePlayerSouthWest()
{
    playerRunning = true;
    playerDirection = "SW";
    movePlayer();

}

void Player::movePlayerSouthEast()
{
    playerRunning = true;
    playerDirection = "SE";
    movePlayer();
}

void Player::moveUp()
{
    if (getYCord() > -410){
        moveBy(0,-1);
        setYCord(-1);
        playerHitbox->moveBy(0,-1);
        updatePlayerPixmap();
    }
}

void Player::moveDown()
{
    if (getYCord() < 435){
        moveBy(0,1);
        setYCord(1);
        playerHitbox->moveBy(0,1);
        updatePlayerPixmap();
    }
}

void Player::moveLeft()
{
    if(getXCord() > -945){
        moveBy(-1,0);
        setXCord(-1);
        playerHitbox->moveBy(-1,0);
        updatePlayerPixmap();
    }
}

void Player::moveRight()
{
    if(getXCord() < 945){
        moveBy(1,0);
        setXCord(1);
        playerHitbox->moveBy(1,0);
        updatePlayerPixmap();
    }
}

void Player::moveNorthWest()
{
    if(getXCord() > -945 && getYCord() > -410){
        moveBy(-0.8,-0.8);
        setXCord(-0.8);
        setYCord(-0.8);
        playerHitbox->moveBy(-0.8,-0.8);
        updatePlayerPixmap();
    }
}

void Player::moveNorthEast()
{
    if(getXCord() < 945 && getYCord() > -410){
        moveBy(0.8,-0.8);
        setXCord(0.8);
        setYCord(-0.8);
        playerHitbox->moveBy(0.8,-0.8);
        updatePlayerPixmap();
    }
}

void Player::moveSouthWest()
{
    if(getXCord() > -945 && getYCord() < 435){
        moveBy(-0.8,0.8);
        setXCord(-0.8);
        setYCord(0.8);
        playerHitbox->moveBy(-0.8,0.8);
        updatePlayerPixmap();
    }
}

void Player::moveSouthEast()
{
    if(getXCord() < 945 && getYCord() < 435){
        moveBy(0.8,0.8);
        setXCord(0.8);
        setYCord(0.8);
        playerHitbox->moveBy(0.8,0.8);
        updatePlayerPixmap();
    }

}

void Player::setPlayerDirection(wchar_t input)
{
    playerDirection = input;
}


void Player::setPlayerRunning(bool input)
{
    playerRunning = input;
}

void Player::setXCord(double x)
{
    playerXCord += x;
}

void Player::setYCord(double y)
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

void Player::setPlayerHitbox(QGraphicsRectItem* hitbox)
{
    playerHitbox = hitbox;
}

std::vector<int> Player::getPlayerHitbox()
{
    return hitboxVec;
}

// Changing charanimations
void Player::updatePlayerPixmap()
{

    if (!playerRunning){


        if(playerDirection == "N"){
            setPixmap(QPixmap(faceUp()));
        }
        else if (playerDirection == "S"){
            setPixmap(QPixmap(faceDown()));
        }
        else if (playerDirection == "W"){
            setPixmap(QPixmap(faceLeft()));
        }
        else if (playerDirection == "E"){
            setPixmap(QPixmap(faceRight()));
        }
    }
    if (playerRunning){

        if(playerDirection == "N"){
            setPixmap(QPixmap(runUp()));
        }
        if(playerDirection == "S"){
            setPixmap(QPixmap(runDown()));
        }
        else if(playerDirection == "W"  || playerDirection == "NW" || playerDirection == "SW"){
            setPixmap(QPixmap(runLeft()));
        }
        else if(playerDirection == "E"  || playerDirection == "NE" || playerDirection == "SE"){
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
    else {
        return QPixmap(":/Images/faceDown1.png");
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
    else {
        return QPixmap(":/Images/faceUp1.png");
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
    else {
        return QPixmap(":/Images/faceLeft1.png");
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
    else {
        return QPixmap(":/Images/faceRight1.png");
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
    else {
        return QPixmap(":/Images/runDown1.png");
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
    else {

        return QPixmap(":/Images/runUp1.png");
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
    else {
        return QPixmap(":/Images/runLeft1.png");
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
    else {
        return QPixmap(":/Images/runRight1.png");
    }
}








