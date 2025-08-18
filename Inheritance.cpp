#include <iostream>
using namespace std;

class Vehicle{
public:
    void start()
    {
        cout << "Car has started!" << endl;
    }
};

class ElectricCar : public Vehicle{
private:
    double batteryLevel;
public:
    ElectricCar(double b) : batteryLevel(b) {}

    void start_EV()
    {
        cout << "Starting!" << endl;
        Vehicle::start();                       // Call using base class method.
        cout << "Vehicle started with battery level: " << batteryLevel << endl;
    }
};

int main()
{
    ElectricCar Tata(80);
    Tata.start_EV();
    return 0;
}