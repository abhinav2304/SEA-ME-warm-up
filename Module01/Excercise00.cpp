// Orthodox Canonical Form
#include <iostream>

class Car
{
public:
    std::string name;
    int speed;
    void display(std::string number);

    // Default Constructor
    Car(){
        this->name = "Default";
        speed = 0;
    }
    Car(std::string name, int speed){
        this->name = name;
        this->speed = speed;
    }

    // Copy Constructor
    Car(const Car& car)
    {
        this->name = car.name;
        this->speed = car.speed;
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // Copy Assignment Operator
    Car& operator=(const Car& car)
    {
        this->name = car.name;
        this->speed = car.speed;
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    // Destructor
    ~Car(){
        std::cout << "Destructor called" << std::endl;
    };
};

void Car::display(std::string number){
    std::cout<<number<<'\t'<<this->name<<'\t'<<this->speed<<std::endl;
}

int main(){
    // Default constructor - 1
    Car car0;
    car0.display("car0");

    // Default constructor - 2
    Car car1("BMW", 5);
    car1.display("car1");

    // Copy constructor
    Car car2 = car1;
    car2.display("car2");

    car2.name = "BENZ";
    car2.speed = 15;
    car2.display("car2");

    // Copy assignment operator
    Car car3;
    car3.display("car3");
    car3 = car2;
    car3.display("car3");

    // Destructor
    return 0;
}