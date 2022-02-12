
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "copyright.h"

void Elevator(int numFloors);
void ArrivingGoingFromTo(int atFloor, int toFloor);


class Elevator {

public:
    Elevator(int numFloors);
    ~Elevator();

private:
    int currentFloor;

};

typedef struct Person {
    int id;
    int atFloor;
    int toFloor;
} Person;

#endif