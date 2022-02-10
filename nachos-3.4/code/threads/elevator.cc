#include "copyright.h"
#include "system.h"


int nextPersonID = 1;


typedef struct Person {
    int id;
    int atFloor;
    int toFloor;
} Person;

void ElevatorThread(int numFloors) {
    printf("Elevator with %d floors was created!\n", numFloors);
}



void Elevator(int numFloors) {
    // Create Elevator Thread
    Thread *t = new Thread("Elevator");
    t->Fork(ElevatorThread, numFloors);

}

void PersonThread(int person) {

    Person *p = (Person *)person;

    printf("Person %d wants to go from floor %d to %d\n", p->id, p->atFloor, p->toFloor);

}

int getNextPersonID() {
    return nextPersonID++;
}


void ArrivingGoingFromTo(int atFloor, int toFloor) {


    // Create Person struct
    Person *p = new Person;
    p->id = getNextPersonID();
    p->atFloor = atFloor;
    p->toFloor = toFloor;

    // Creates Person Thread
    Thread *t = new Thread("Person " + p->id);
    t->Fork(PersonThread, (int)p);

}