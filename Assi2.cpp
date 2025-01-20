#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual string sound() const {
        return "Some sound";
    }
};

class Dog : public Animal {
public:
    string sound() const override {
        return "Bark";
    }
};

class Cat : public Animal {
public:
    string sound() const override {
        return "Meow";
    }
};

int main() {
    Animal* animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    cout << "Dog: " << animal->sound() << endl;

    animal = &cat;
    cout << "Cat: " << animal->sound() << endl;

    return 0;
}
