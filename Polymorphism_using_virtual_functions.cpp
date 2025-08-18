// Run-time polymorphism iplemented using virtual functions.

#include <iostream>

using namespace std;

class Animal{
public:
    virtual void speak(){
        cout << "Animal sound!" << endl;
    }
};

class Dog : public Animal {
public:

    void speak1(){
        Animal::speak();
    }
    void speak() override { // Override base-class method.
        cout << "Woof!" << endl;
    }
};

int main()
{
    Dog dog;
    Animal* animal = new Dog();
    dog.speak1();
    animal->speak();
    delete animal;
    return 0;
}