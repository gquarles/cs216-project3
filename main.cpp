/*
CS 216 Project 03
By Griffin Quarles

The purpose of this program is to take input from the user
and process it by placing it in a object from a template class
and insert that into an array. Then output all of the data the user
inputted in a formatted table.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "GenericRecord.h"
#include "GenericRecord.cpp"

using namespace std;

//Structs to hold 3 different types the template class will use
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

/*
The getInt function takes 1 arguement and returns an integer.
It will output the string question and try to get an integer as
input and repeat until a working integer is given.
*/
int getInt(string question) {
    //Declare a variable to hold user input
    int input;

    //Ask the user to input and attempt to read input
    cout << question;
    cin >> input;

    //If the input is not valid enter loop
    while (cin.fail()) {
        //Reset the cin object
        cin.clear();
        cin.ignore(256,'\n');
        //Ask for new input
        cout << endl << "Error please input a number." << endl << question;
        cin >> input;
    }
    cin.ignore();
    //Return the integer
    return input;
}

/*
The getInt function takes 1 arguement and returns an string.
It will output the string question and try to get an string as
input and repeat until a working string is given.
*/
string getString(string question) {
    //Ask user for input
    string input;
    cout << question;
    //Read input into the input var
    getline(cin, input);

    //Return user input
    return input;
}

/*
The getInt function takes 1 arguement and returns an float.
It will output the string question and try to get an float as
input and repeat until a working float is given.
*/
float getFloat(string question) {
    //Declare float to hold input
    float input;

    //Ask for input and attempt to read input
    cout << question;
    cin >> input;

    //If input given is not a float
    while (cin.fail()) {
        //Reset cin object
        cin.clear();
        cin.ignore(256,'\n');
        //Prompt for input again
        cout << endl << "Error please input a number." << endl << question;
        cin >> input;
    }
    //Reset cin object and return user inputs
    cin.ignore();
    return input;
}

/*
The main function sets up the program and controls
all of the functioning. It has no parameters and 
returns an int which is always 0. The main function
has no preconditions and no post conditions. 
The main function will create 3 dynamic arrays to hold
our template class objects of type struct Building, Computer, and
Furniture. After inputting all data it will format and output the data.
Then free up memory and exit.
*/
int main() {
    //Declare 3 pointers to later be used as dynamic arrays
    GenericRecord <Building> * buildingRecords = NULL;
    GenericRecord <Computer> * computerRecords = NULL;
    GenericRecord <Furniture> * furnitureRecords = NULL;

    //Declare int to hold how big arrays will be
    int numBuildings, numComputers, numFurniture;

    //Ask user to input amount of data they want to input
    numBuildings = getInt("How many buildings: ");
    numComputers = getInt("How many Computers: ");
    numFurniture = getInt("How many Furniture: ");

    //Create 3 arrays with the size user specified
    buildingRecords = new GenericRecord <Building> [numBuildings];
    computerRecords = new GenericRecord <Computer> [numComputers];
    furnitureRecords = new GenericRecord <Furniture> [numFurniture];

    cout << endl;
    //Loop the number of times the user wanted to input buildings
    int i = 0;
    while (i < numBuildings) {
        //Delcare a record to hold data before inserting it into the array
        GenericRecord <Building> record;
        //Declare a building object to hold data
        Building building;
        //Insert data from the user into the Building object
        building.Description = getString("Enter description of building " + to_string(i + 1) + ": ");
        building.Identifier = getString("Enter identifier of building " + to_string(i + 1) + ": ");
        building.Value = getFloat("Enter value of building " + to_string(i + 1) + ": ");
        //Insert object into the record class
        record.setRecord(building);
        
        cout << endl;
        //Insert record into the buildingRecords array
        buildingRecords[i] = record;
        i++;
    }

    //Loop the number of times the user wanted to input computers
    i = 0;
    while (i < numComputers) {
        //Delcare a record to hold data before inserting it into the array
        GenericRecord <Computer> record;
        //Declare a computer object to hold data
        Computer computer;
        computer.Description = getString("Enter description of computer " + to_string(i + 1) + ": ");
        computer.Identifier = getInt("Enter identifier of computer " + to_string(i + 1) + ": ");
        computer.Value = getInt("Enter value of computer " + to_string(i + 1) + ": ");
        //Insert object into the record class
        record.setRecord(computer);
        
        cout << endl;
        //Insert record into the computerRecords array
        computerRecords[i] = record;
        i++;
    }

    //Loop the number of times the user wanted to input furniture
    i = 0;
    while (i < numFurniture) {
        //Delcare a record to hold data before inserting it into the array
        GenericRecord <Furniture> record;
        //Declare a furniture object to hold data
        Furniture furniture;
        furniture.Description = getString("Enter description of furniture " + to_string(i + 1) + ": ");
        furniture.Identifier = getInt("Enter identifier of furniture " + to_string(i + 1) + ": ");
        furniture.Value = getFloat("Enter value of furniture " + to_string(i + 1) + ": ");
        //Insert object into the record class
        record.setRecord(furniture);
        
        cout << endl;
        //Insert record into the computerRecords array
        furnitureRecords[i] = record;
        i++;
    }
    
    //If the user inputted buildings
    if (numBuildings > 0) {
        //Start the output of the table
        cout << "Buildings" << endl;
        //Tell the user what each collom means
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        //Loop over each building
        while (i < numBuildings) {
            //Declare a record object and building object to hold data 
            GenericRecord <Building> record;
            Building building;

            //Set record to next record in array
            record = buildingRecords[i];
            //Retrive struct object from record object
            building = record.getRecord();

            //Print each attribute from struct object in formatted table
            printf("%-20s%-20s%-.5f\n", building.Identifier.c_str(), building.Description.c_str(), building.Value);
            i++;
        }
    }

    //If the user inputted computers
    if (numComputers > 0) {
        //Start the output of the table
        cout << endl << "Computers" << endl;
        //Tell the user what each collom means
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        //Loop over each computer
        while (i < numComputers) {
            //Declare a record object and computer object to hold data 
            GenericRecord <Computer> record;
            Computer computer;

            //Set record to next record in array
            record = computerRecords[i];
            //Retrive struct object from record object
            computer = record.getRecord();

            //Print each attribute from struct object in formatted table
            printf("%-20ld%-20s%-.5f\n", computer.Identifier, computer.Description.c_str(), computer.Value);
            i++;
        }
    }

    //If the user inputted furniture
    if (numFurniture > 0) {
        //Start the output of the table
        cout << endl << "Furniture" << endl;
        //Tell the user what each collom means
        printf("%-20s%-20s%-20s\n", "Identifier", "Description", "Value");
        i = 0;
        //Loop over each furniture item
        while (i < numFurniture) {
            //Declare a record object and furniture object to hold data 
            GenericRecord <Furniture> record;
            Furniture furniture;

            //Set record to next record in array
            record = furnitureRecords[i];
            //Retrive struct object from record object
            furniture = record.getRecord();

            //Print each attribute from struct object in formatted table
            printf("%-20d%-20s%-.5f\n", furniture.Identifier, furniture.Description.c_str(), furniture.Value);
            i++;
        }
    }


    //Free up memory from dynamic arrays
    delete [] buildingRecords;
    delete [] computerRecords;
    delete [] furnitureRecords;

    buildingRecords = NULL;
    computerRecords = NULL;
    furnitureRecords = NULL;

    //Exit program
    return 0;
}