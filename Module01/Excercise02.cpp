#include <iostream>
#include <cmath>

// Abstract Class (Cannot be declared this class as objects)
class Car
{
// protected access specifier
protected:
    // member variable 
    std::string make;
    std::string model;
    int year;

// public access specifier
public:
    // Default constructor
    Car()
    : make("Default"), model("Default"), year(0) {std::cout<<"Car Default constructor"<<'\n';};
    Car(std::string make, std::string model, int year) 
    : make(make), model(model), year(year) {{std::cout<<"Car Default constructor"<<'\n';}};

    // Copy constructor
    Car(const Car& car)
    : make(car.make), model(car.model), year(car.year) {std::cout << "Car Copy constructor" << '\n';};

    // Copy Assignment Operator
    Car& operator=(const Car& car) {std::cout << "Car Copy Assignmnet Operator" << '\n'; return *this = car;};

    // Destructor
    ~Car(){std::cout<<"Car Destructor called"<<'\n';};
    
    // Abstraction (virtual member function)
    virtual void Accel(int power)=0;
    
    // member function
    void drive();
};

// Define member function
void Car::drive(){
    std::cout<<make<<'\t'<<model<<'\t'<<year<<'\n';
    std::cout << "Drive function of Car class is called" << '\n';
}

// Child 1 (By Inheritance)
class SportsCar : public Car{
// protected access specifier
protected:
    int topspeed;
    int speed;

// public access specifier
public:
    // Default Constructor
    SportsCar()
    : Car(), topspeed(0), speed(0) {std::cout<<"SportsCar Default constructor"<<'\n';};
    SportsCar(std::string make, std::string model, int year, int topspeed, int speed)
    : Car(make, model, year), topspeed(topspeed), speed(speed) {std::cout<<"SportsCar Default constructor"<<'\n';};

    // Copy constructor
    SportsCar(const SportsCar& sportscar)
    : Car(sportscar), topspeed(sportscar.topspeed), speed(sportscar.speed) {std::cout << "SportsCar Copy constructor" << '\n';};

    // Copy Assignment Operator
    SportsCar& operator=(const SportsCar& sportscar) {std::cout << "SportsCar Copy Assignmnet Operator" << '\n'; return *this = sportscar;};

    // Destructor
    ~SportsCar(){std::cout<<"SportsCar Destructor called"<<'\n';};

    // Abstraction (virtual member function)
    virtual void Accel(int power);

    // member function
    void drive();
};

// re-Define virtual member fuction
void SportsCar::Accel(int power)
{
    speed = power + sin(power);
    std::cout<<"SportsCar is Accelerating"<<'\n';
    if (speed>topspeed){
        speed = topspeed;    
        std::cout<<"Speed Limit"<<speed<<'\n';
    }
    std::cout<<"Speed is now"<<speed<<'\n';
}

// Define member function (by using parent's member function)
void SportsCar::drive(){
    std::cout<<topspeed<<'\t';
    Car::drive();
    std::cout << "SportsCar Drive function\n";
}

// Child 2 (By Inheritance)
class SUV : public Car
{
// protected access specifier
protected:
    int torque;
    int speed;

// public access specifier
public:
    // Default Constructor
    SUV()
    : Car(), torque(0), speed(0) {std::cout<<"SUV Default constructor"<<'\n';};
    SUV(std::string make, std::string model, int year, int torque, int speed)
    : Car(make, model, year), torque(torque), speed(speed) {std::cout<<"SUV Default constructor"<<'\n';};

    // Copy constructor
    SUV(const SUV& suv)
    : Car(suv), torque(suv.torque), speed(suv.speed) {std::cout << "SUV Copy constructor" << '\n';};

    // Copy Assignment Operator
    SUV& operator=(const SUV& suv) {std::cout << "SUV Copy Assignmnet Operator" << '\n'; return *this = suv;};

    // Destructor
    ~SUV(){std::cout<<"SUV Destructor called"<<'\n';};

    // Abstraction (virtual member function)
    virtual void Accel(int power);

    // member function
    void drive();
};

// re-Define virtual member fuction
void SUV::Accel(int power)
{
    speed = 0.5*power + 2*sin(power);
    std::cout<<"SUV is Accelerating"<<'\n';
    std::cout<<"Speed is now "<<speed<<'\n';
}

// Define member function (by using parent's member function)
void SUV::drive(){
    std::cout<<torque<<'\t';
    Car::drive();
    std::cout << "SUV Drive function\n";
}

// Simple Class
class Trailer
{
protected:
    int weight;
    std::string type;

public:
    // Default Constructor
    Trailer()
    : weight(100), type("Default"){std::cout<<"Trailer Default constructor"<<'\n';};
    Trailer(int weight, std::string type)
    : weight(weight), type(type){std::cout<<"Trailer Default constructor"<<'\n';};

    // Copy constructor
    Trailer(const Trailer& trailer)
    : weight(trailer.weight), type(trailer.type){std::cout << "Trailer Copy constructor" << '\n';};

    // Copy Assignment Operator
    Trailer& operator=(const Trailer& trailer) {std::cout << "Trailer Copy Assignmnet Operator" << '\n'; return *this = trailer;};

    // Destructor
    ~Trailer(){std::cout<<"Trailer Destructor called"<<'\n';};
};

class CampingCar : public SUV, public Trailer
{
public:
    // Default Constructor
    CampingCar()
    : SUV(), Trailer() {std::cout<<"CampingCar Default constructor"<<'\n';};
    CampingCar(std::string make, std::string model, int year, int torque, int speed, int weight, std::string type)
    : SUV(make, model, year, torque, speed), Trailer(weight, type) {std::cout<<"CampingCar Default constructor"<<'\n';};

    // Copy constructor
    CampingCar(const CampingCar& campingcar)
    : SUV(campingcar), Trailer(campingcar) {std::cout << "CampingCar Copy constructor" << '\n';};

    // Copy Assignment Operator
    CampingCar& operator=(const CampingCar& campingcar) {std::cout << "CampingCar Copy Assignmnet Operator" << '\n'; return *this = campingcar;};

    // Destructor
    ~CampingCar() {std::cout<<"CampingCar Destructor called"<<'\n';};

};

// Collaborate Two Class (SportsCar, SUV) which is from Same Parent Calss (Car).
class SportsSUV : public Car
{
// protected access specifier
protected:
    // Declare member variables as Object(not Declaring, just Calling)
    SportsCar S_car;
    SUV SUV_car;
// public access specifier
public:
    // Parent (Car) does not have this variables 
    int topspeed;
    int torque;
    int speed;

    // Default Constructor
    // Call Constructor of Car, S_car, SUV_car
    SportsSUV()
    : Car(), S_car(), SUV_car() {std::cout<<"SportsSUV Default constructor"<<'\n';};
    SportsSUV(std::string make, std::string model, int year, int topspeed, int torque, int speed)
    : Car(make, model, year), S_car(make, model, year, topspeed, speed), SUV_car(make, model, year, torque, speed) {std::cout<<"SportsSUV Default constructor"<<'\n';};

    // Copy constructor
    SportsSUV(const SportsSUV& sportssuv)
    : Car(sportssuv), topspeed(topspeed), torque(torque), speed(speed) {std::cout << "SportsSUV Copy constructor" << '\n';};

    // Copy Assignment Operator
    SportsSUV& operator=(const SportsSUV& sportssuv) {std::cout << "SportsSUV Copy Assignmnet Operator" << '\n'; return *this = sportssuv;};

    // Destructor
    ~SportsSUV() {std::cout<<"SportsSUV Destructor called"<<'\n';};

    // For solving encalsulation (member function)
    void getinformation();

    // Abstraction (virtual member function)
    virtual void Accel(int power);
};

// Define member function
void SportsSUV::getinformation(){std::cout<<make<<'\n';}

// re-Define virtual member fuction
void SportsSUV::Accel(int power)
{
    speed = 0.75*power + 1.25*sin(power);
    std::cout<<"SportsSUV is Accelerating\n";
    if (speed>topspeed){
        speed = topspeed;    
    }
    std::cout<<"Speed is now "<<speed<<'\n';
}


int main(){
    SportsCar sportscar;
    SUV suv;
    CampingCar camppingcar;
    SportsSUV sportssuv;
    // sportssuv.name;
    sportssuv.getinformation();
    return 0;
}