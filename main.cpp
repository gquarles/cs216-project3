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

    cout << endl;
    int i = 0;
    while (i < numBuildings) {
        GenericRecord <Building> record;
        Building building;
        building.Description = getString("Enter description of building " + to_string(i + 1) + ": ");
        building.Identifier = getString("Enter identifier of building " + to_string(i + 1) + ": ");
        building.Value = getFloat("Enter value of building " + to_string(i + 1) + ": ");
        record.setRecord(building);
        
        cout << endl;
        buildingRecords[i] = record;
        i++;
    }

    i = 0;
    while (i < numComputers) {
        GenericRecord <Computer> record;
        Computer computer;
        computer.Description = getString("Enter description of computer " + to_string(i + 1) + ": ");
        computer.Identifier = getInt("Enter identifier of computer " + to_string(i + 1) + ": ");
        computer.Value = getInt("Enter value of computer " + to_string(i + 1) + ": ");
        record.setRecord(computer);
        
        cout << endl;
        computerRecords[i] = record;
        i++;
    }

    i = 0;
    while (i < numFurniture) {
        cout << i;
        GenericRecord <Furniture> record;
        Furniture furniture;
        furniture.Description = getString("Enter description of furniture " + to_string(i + 1) + ": ");
        furniture.Identifier = getInt("Enter identifier of furniture " + to_string(i + 1) + ": ");
        furniture.Value = getFloat("Enter value of furniture " + to_string(i + 1) + ": ");
        record.setRecord(furniture);
        
        cout << endl;
        furnitureRecords[i] = record;
        i++;
    }
    
    if (numBuildings > 0) {
        cout << "Buildings" << endl;
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        while (i < numBuildings) {
            GenericRecord <Building> record;
            Building building;

            record = buildingRecords[i];
            building = record.getRecord();

            printf("%-20s%-20s%-.5f\n", building.Identifier.c_str(), building.Description.c_str(), building.Value);
            i++;
        }
    }

    if (numComputers > 0) {
        cout << endl << "Computers" << endl;
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        while (i < numComputers) {
            GenericRecord <Computer> record;
            Computer computer;

            record = computerRecords[i];
            computer = record.getRecord();

            printf("%-20ld%-20s%-.5f\n", computer.Identifier, computer.Description.c_str(), computer.Value);
            i++;
        }
    }

    if (numFurniture > 0) {
        cout << endl << "Furniture" << endl;
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        while (i < numFurniture) {
            GenericRecord <Furniture> record;
            Furniture furniture;

            record = furnitureRecords[i];
            furniture = record.getRecord();

            printf("%-20d%-20s%-.5f\n", furniture.Identifier, furniture.Description.c_str(), furniture.Value);
            i++;
        }
    }


    delete [] buildingRecords;
    delete [] computerRecords;
    delete [] furnitureRecords;

    buildingRecords = NULL;
    computerRecords = NULL;
    furnitureRecords = NULL;

    return 0;
}