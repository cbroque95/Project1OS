#include "copyright.h"
#include "system.h"
#include "synch.h"
#include "elevator.h"


int nextPersonID = 1;
Lock *personIDLock = new Lock("PersonIDLock");


// Elevator *e = new Elevator(numFloors);


void ElevatorThread(int numFloors) {

    printf("Elevator with %d floors was created!\n", numFloors);

    // DO the following  steps A and B forever ...

    // A. Wait until hailed

    // B. While there are active persons, loop doing the following
    //      1. Signal persons inside elevator to get off
    //      2. Signal persons atFloor to get in
    //      3. Go to next floor
    //  printf("Elevator arrives on floor %d", )

}



void Elevator(int numFloors) {
    // Create Elevator Thread
    Thread *t = new Thread("Elevator");
    t->Fork(ElevatorThread, numFloors);

}

void PersonThread(int person) {

    Person *p = (Person *)person;

    printf("Person %d wants to go from floor %d to %d\n", p->id, p->atFloor, p->toFloor);

    // Increment waiting persons atFloor
    // Hail Elevator
    // Wait for elevator to arrive atFloor
    // Get into elevator
    printf("Person %d got into the elevator.\n", p->id);
    // Wait for elevator to reach toFloor
    // Get out of the elevator
    printf("Person %d got out of the elevator.\n", p->id);

}

int getNextPersonID() {
    int personID = nextPersonID;
    personIDLock->Acquire();
    nextPersonID = nextPersonID + 1;
    personIDLock->Release();
    return personID;
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