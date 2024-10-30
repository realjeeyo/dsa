#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

int main(){
    Flight list[5];

    list[0] = newFlight(1, "B737", newSched(12,30), newDest("NAIA", 1));
    list[1] = newFlight(2, "A737", newSched(11,30), newDest("NAIA", 1));
    list[2] = newFlight(3, "A707", newSched(1,30), newDest("NAIA", 1));
    list[3] = newFlight(4, "B707", newSched(1,00), newDest("NAIA", 1));
    list[4] = newFlight(5, "A10", newSched(9,45), newDest("NAIA", 1));

    FILE *fp;
    fp = fopen("flight_file.dat", "wb");

    if (fp != NULL){
        fwrite(list, sizeof(Flight), 5, fp);
    }

    fclose(fp);

    return 0;
}