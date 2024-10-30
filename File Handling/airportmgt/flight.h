#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct{
    int hour;
    int minute;
} Schedule;

typedef struct{
    char destName[50];
    int destPriority;
} Destination;

typedef struct{
    int flightCode;
    char aircraft[10];
    Schedule flightSched;
    Destination flightDest;
} Flight;

Flight newFlight(int flightCode, char *aircraft, Schedule flightSched, Destination flightDest);
Schedule newSched(int hour, int minute);
Destination newDest(char *destName, int destPriority);
void displayFlight(Flight f);

#endif