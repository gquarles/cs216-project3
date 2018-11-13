/*
CS 216 Project 03
By Griffin Quarles
*/

#pragma once
#include <iostream>
#include <string>

//Create template class to store multiple types
template <class Type>
class GenericRecord {
    private:
    Type record;

    public:
    //Accessor and mutator functions
    Type getRecord();
    void setRecord(Type r);
};
