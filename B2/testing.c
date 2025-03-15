//#include "cross_a.h"
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

sem_t * lock;
mode_t berechtigung = 0600;

int main(void){
    printf("Starting\n");
    //sem_init(&lock,0,1);
    sem_unlink("Lock");
    lock = sem_open("Lock",O_CREAT,berechtigung,1);
    while(true){
        printf("Hallo\n");
        sem_wait(lock);
        printf("Bin drinn\n");
        sleep(3);
        sem_post(lock);
    }
    return 0;
}