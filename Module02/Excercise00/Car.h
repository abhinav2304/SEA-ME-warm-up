#pragma once

#include <iostream>
class Car
{
// public access specifier
public:
    // member variable 
    std::string make;
    std::string model;
    int year;
    // Default constructor
    Car();
    Car(std::string make, std::string model, int year);
    // Copy constructor
    Car(const Car& car);
    // Copy Assignment Operator
    Car& operator=(const Car& car);
    // Destructor
    ~Car();

    // member function
    void drive();
};