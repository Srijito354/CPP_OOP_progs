#include <iostream>

using namespace std;

// A Class is the blueprint of an object.
// An object is an instance of a class.

// Below, we define a class.
class Car{
    // Encapsulated data. Hence, private.
private:
    string brand;
    string model;
    int year;

public:
    // Defining the constructor.
    Car(string b, string m, int y) : brand(b), model(m), year(y) {}

    // Method to display car info.
    void displayInfo()
    {
        cout << "Brand: " << brand << ", Model: " << ", Year: " << year << endl;
    }

    // Getter for year (encapsulation)
    int getYear()
    {
        return year;
    }

    // Setter for year (encapsulation)
    void setYear(int newYear)
    {
        year = newYear;
    }
};

int main()
{
    Car myCar("Toyota", "Camry", 2022);
    myCar.displayInfo();

    myCar.setYear(2025);
    cout << "Updated year: " << myCar.getYear() << endl;
    return 0;
}