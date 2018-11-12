#include <iostream>
#include <string>
#include <iomanip>
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
    GenericRecord <Building> * buildingRecords = NULL;
    GenericRecord <Computer> * computerRecords = NULL;
    GenericRecord <Furniture> * furnitureRecords = NULL;

    int numBuildings, numComputers, numFurniture;

    cout << "How many buildings: ";
    cin >> numBuildings;

    cout << endl << "How many Computers: ";
    cin >> numComputers;

    cout << endl << "How many Furniture: ";
    cin >> numFurniture;

    buildingRecords = new GenericRecord <Building> [numBuildings];
    computerRecords = new GenericRecord <Computer> [numComputers];
    furnitureRecords = new GenericRecord <Furniture> [numFurniture];

    GenericRecord <Computer> test;
    computerRecords[0] = test;

    Computer comp;
    Computer comp2;
    comp.Description = "Hello";
    comp.Identifier = 15;
    comp.Value = 23.2;

    computerRecords[0].setRecord(comp);
    comp2 = computerRecords[0].getRecord();
    cout << comp2.Description;

    delete [] buildingRecords;
    delete [] computerRecords;
    delete [] furnitureRecords;

    buildingRecords = NULL;
    computerRecords = NULL;
    furnitureRecords = NULL;

    return 0;
}