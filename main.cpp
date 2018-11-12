#include <iostream>
#include <string>
#include "GenericRecord.h"
#include "GenericRecord.cpp"

using namespace std;

struct Furniture {
    int Identifier;
    string Description;
    float Value;
};

struct Computer {
    long int Identifier;
    string Description;
    float Value;
};

struct Building {
    string Identifier;
    string Description;
    double Value;
};

int main() {
    cout << "Hello, World!" << endl;

    GenericRecord <Computer> test;

    Computer comp;
    Computer comp2;
    comp.Description = "Hello";
    comp.Identifier = 15;
    comp.Value = 23.2;

    test.setRecord(comp);
    comp2 = test.getRecord();
    cout << comp2.Description;


    return 0;
}