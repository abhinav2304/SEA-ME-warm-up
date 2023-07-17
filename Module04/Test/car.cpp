#include "car.h"
#include <math.h>
#include <QDebug>

const double rad2deg = 3.14159265358979/180;

Car::Car()
{
    angle = 90;
    speed = 0;
    max_speed = 5;
//    angle_factor = 1;
//    speed_factor = 0.1;
}

void Car::update(bool keys[4])
{
    if (keys[0]) change_Speed(0.1);
    if (keys[2]) change_Speed(-0.1);
    if (keys[1])
    {
        change_Angle(2);
        changed_angle_in_this_period = 2;
    }
    else if (keys[3])
    {
        change_Angle(-2);
        changed_angle_in_this_period = -2;
    }
    else
    {
        changed_angle_in_this_period = 0;
    }
}

void Car::run()
{
//    Calculate location(x,y)
    x += speed*cos(angle*rad2deg);
    y -= speed*sin(angle*rad2deg);
}

void Car::change_Angle(float addition_angle)
{
    setAngle(angle + addition_angle);
}

void Car::change_Speed(float addition_speed)
{
    setSpeed(speed + addition_speed);
}

void Car::setAngle(float input_angle)
{
//    Angle Limitation
    while (input_angle<0){input_angle = input_angle+360;};
    while (input_angle>360) {input_angle = input_angle-360;};
    angle = input_angle;
}

void Car::setSpeed(float input_speed)
{
//    Speed Limitation
    if (-max_speed<input_speed && input_speed<max_speed){
        speed = input_speed;
    }
}

void Car::setX(float input_x)
{
    x = input_x;
}

void Car::setY(float input_y)
{
    y = input_y;
}

float Car::getCAITP()
{
    return changed_angle_in_this_period;
}

float Car::getAngle()
{
    return angle;
}

float Car::getSpeed()
{
    return speed;
}

float Car::getX()
{
    return x;
}

float Car::getY()
{
    return y;
}
