
a.out: main.o GenericRecord.o
	g++ main.o GenericRecord.o -o a.out -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

GenericRecord.o: GenericRecord.cpp GenericRecord.h
	g++ -c GenericRecord.cpp -std=c++11

