/*
CS 216 Project 03
By Griffin Quarles
*/

#include "GenericRecord.h"

//setRecord returns nothing and takes 1 arguement
template <class Type>
void GenericRecord<Type>::setRecord(Type r) {
    //Set record to given arguement
    record = r;
}

//getRecord returns Type from template and takes no arguements
template <class Type>
Type GenericRecord<Type>::getRecord() {
    return record;
}