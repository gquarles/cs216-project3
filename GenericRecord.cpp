#include "GenericRecord.h"

template <class Type>
void GenericRecord<Type>::setRecord(Type r) {
    record = r;
}

template <class Type>
Type GenericRecord<Type>::getRecord() {
    return record;
}