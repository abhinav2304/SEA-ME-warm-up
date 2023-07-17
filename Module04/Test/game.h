#ifndef GAME_H
#define GAME_H

#include "car.h"
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    QTimer* m_timer;
    Car car[2];
};

#endif // GAME_H
