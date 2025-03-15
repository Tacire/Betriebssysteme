#include "set_up.h"

void setup(){
    if(!initialized){
        cleanup();
        ns = sem_open("NS",O_CREAT,berechtigung,1);
        sn = sem_open("SN",O_CREAT,berechtigung,1);
        we = sem_open("WE",O_CREAT,berechtigung,1);
        ew = sem_open("EW",O_CREAT,berechtigung,1);
        initialized = true;
    }
}

void cleanup(){
    sem_unlink("NS");
    sem_unlink("SN");
    sem_unlink("WE");
    sem_unlink("EW");
    initialized = false;
}