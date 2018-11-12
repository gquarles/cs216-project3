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

int getInt(string question) {
    int input;

    cout << question;
    cin >> input;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl << "Error please input a number." << endl << question;
        cin >> input;
    }
    cin.ignore();
    return input;
}

string getString(string question) {
    string input;
    cout << question;
    getline(cin, input);

    return input;
}

float getFloat(string question) {
    float input;

    cout << question;
    cin >> input;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl << "Error please input a number." << endl << question;
        cin >> input;
    }
    cin.ignore();
    return input;
}

int main() {
    GenericRecord <Building> * buildingRecords = NULL;
    GenericRecord <Computer> * computerRecords = NULL;
    GenericRecord <Furniture> * furnitureRecords = NULL;

    int numBuildings, numComputers, numFurniture;

    numBuildings = getInt("How many buildings: ");
    numComputers = getInt("How many Computers: ");
    numFurniture = getInt("How many Furniture: ");

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