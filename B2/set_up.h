#ifndef SETUP
#define SETUP

#include <fcntl.h>
#include <semaphore.h>
#include <stdbool.h>



private bool initialized = false;
public sem_t * ns;
public sem_t * sn;
public sem_t * we;
public sem_t * ew;

void setup();
void cleanup();

#endif