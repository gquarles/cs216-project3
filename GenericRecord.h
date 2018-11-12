#pragma once
#include <iostream>
#include <string>

template <class Type>
class GenericRecord {
    private:
    Type record;

    public:
    Type getRecord();
    void setRecord(Type r);
};
