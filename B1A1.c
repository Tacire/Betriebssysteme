#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_if_palindrom(char* word_to_check){
    int word_length = strlen(word_to_check);

    for(int i = 0; i<=(word_length/2); i++){
        //Erweiterbar mit Großbuchstabencheck
        if(word_to_check[i] != word_to_check[word_length-(i+1)]){
            return false;
        }
    }
    return true;
}

int number_of_palindroms(char* argv[]){
    int palindrom_counter = 0; 
    int Iintervall_start = 0;
    int Iintervall_end = 0;

    char * intervall_start = strtok(argv[2],":");
    char * intervall_end = strtok(NULL,":");
    if(intervall_end == NULL){
        printf("Please enter correct intervall as in 3:6");
        exit(1);
    }
    sscanf(intervall_start,"%d", &Iintervall_start);
    sscanf(intervall_end,"%d", &Iintervall_end);
    printf("%d\n", Iintervall_start);
    printf("%d\n", Iintervall_end);

    char * delimiters = ",";
    char * name = strtok(argv[1], delimiters);
    int word_counter = 1;
    while(name != NULL && word_counter <= Iintervall_end){
        if(word_counter >= Iintervall_start && check_if_palindrom(name)){
            palindrom_counter++;
        }
        name = strtok(NULL, delimiters);
        word_counter++;
    }
    return palindrom_counter;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Paramters need to be in format palindrom a,v,c 0:1\n");
        exit(1);
    } 
    //first parramter = list of words
    printf("Anzahl gefundener Palindrome : %d \n", number_of_palindroms(argv));
    return 0;
}
