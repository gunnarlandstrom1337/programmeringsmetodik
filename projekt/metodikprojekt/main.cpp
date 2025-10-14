#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>


/*
-QGraphicsScene *Container for all game objects* Example: Player, map, world
-QGraphicsItem (QGraphicsRectIem) *Any object you want to put in the scene, needs to be derived from QGraphicsItem*
-QGraphicsView *Used to visualize the scene* -- *If you want to print your items onto the scene*

*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    // Add item to the scene
    scene->addItem(rect);

    // Visualizer for the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
