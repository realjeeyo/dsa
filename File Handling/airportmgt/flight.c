#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

Flight newFlight(int flightCode, char *aircraft, Schedule flightSched, Destination flightDest){
    Flight newFlight;
    newFlight.flightCode = flightCode;
    strcpy(newFlight.aircraft, aircraft);
    newFlight.flightSched = flightSched;
    newFlight.flightDest = flightDest;
    return newFlight;
}

Schedule newSched(int hour, int minute){
    Schedule newSched = {hour, minute};
    return newSched;
}

Destination newDest(char *destName, int destPriority){
    Destination newDest;
    strcpy(newDest.destName, destName);
    newDest.destPriority = destPriority;
    return newDest;
}

void displayFlight(Flight f){
    printf("Flight Code: %d\t| Aircraft: %s\t| Schedule: %d:%d\t| Destination: %s\n", f.flightCode, f.aircraft, f.flightSched.hour, f.flightSched.minute, f.flightDest);
}