#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory> 

using namespace std;

// Base class gets animal names and ages
class Animal {
protected:
    string name;
    int age;
    string species;

public:
    Animal(string n, int a, string s) : name(n), age(a), species(s) {}
    virtual ~Animal() {}

    virtual string displayInfo() const {
        return name + ", " + to_string(age) + " years old, " + species;
    }
};

// Gives classes for specific types of animals
class Lion : public Animal {
public:
    Lion(string n, int a) : Animal(n, a, "Lion") {}

    string displayInfo() const override {
        return "Lion: " + Animal::displayInfo();
    }
};

class Tiger : public Animal {
public:
    Tiger(string n, int a) : Animal(n, a, "Tiger") {}

    string displayInfo() const override {
        return "Tiger: " + Animal::displayInfo();
    }
};

class Bear : public Animal {
public:
    Bear(string n, int a) : Animal(n, a, "Bear") {}

    string displayInfo() const override {
        return "Bear: " + Animal::displayInfo();
    }
};

class Hyena : public Animal {
public:
    Hyena(string n, int a) : Animal(n, a, "Hyena") {}

    string displayInfo() const override {
        return "Hyena: " + Animal::displayInfo();
    }
};

// Main program
int main() {
    ifstream file("C:\\\\MinGW\\\\CIT-66\\\\Coding C++\\\\Module 4\\\\output\\\\arrivingAnimals.txt");
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    map<string, vector<shared_ptr<Animal>>> zoo;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, species;
        int age;
        ss >> name >> age >> species;

        shared_ptr<Animal> animal;
        if (species == "Lion") {
            animal = make_shared<Lion>(name, age);
        } else if (species == "Tiger") {
            animal = make_shared<Tiger>(name, age);
        } else if (species == "Bear") {
            animal = make_shared<Bear>(name, age);
        } else if (species == "Hyena") {
            animal = make_shared<Hyena>(name, age);
        }

        zoo[species].push_back(animal);
    }

    file.close();

    for (const auto& pair : zoo) {
        cout << pair.first << " Details:" << endl;
        for (const auto& animal : pair.second) {
            cout << animal->displayInfo() << endl;
        }
        cout << endl;
    }

    return 0;
}
