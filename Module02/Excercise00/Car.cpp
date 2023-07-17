#include "Car.h"
#include <iostream>

// Default constructor
Car::Car()
: make("Default"), model("Default"), year(0) {std::cout<<"Car Default constructor"<<'\n';};
Car::Car(std::string make, std::string model, int year) 
: make(make), model(model), year(year) {{std::cout<<"Car Default constructor"<<'\n';}};

// Copy constructor
Car::Car(const Car& car)
: make(car.make), model(car.model), year(car.year) {std::cout << "Car Copy constructor" << '\n';};

// Copy Assignment Operator
Car& Car::operator=(const Car& car) {std::cout << "Car Copy Assignmnet Operator" << '\n'; return *this = car;};

// Destructor
Car::~Car(){std::cout<<"Car Destructor called"<<'\n';};

// Define member function
void Car::drive(){
    std::cout<<make<<'\t'<<model<<'\t'<<year<<'\n';
    std::cout << "Drive function of Car class is called" << '\n';
};