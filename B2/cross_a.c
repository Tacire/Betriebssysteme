#include "cross_a.h"
#include "set_up.h"

direction read_direction(char* arg){
    if(strcmp(arg, north) == 0){
        return NORTH;
    }else if(strcmp(arg,south) == 0){
        return SOUTH;
    }else if(strcmp(arg,west) == 0){
        return WEST;
    }else if(strcmp(arg,east) == 0){
        return EAST;
    }else{
        return NONE;
    }
}

int main(int argc, char *argv[]){
    if(argc != 3){
        perror("Falsche Anzahl an Argumenten");
        exit(-1);
    }
    direction ursprung = read_direction(argv[1]);
    direction ziel = read_direction(argv[2]);
    set_up();
}