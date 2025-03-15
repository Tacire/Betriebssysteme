#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <string.h>

char * terminal(){
    char cwd[PATH_MAX] = "";
    getcwd(cwd,PATH_MAX);
    uid_t uid = getuid();
    struct passwd *pws;
    pws = getpwuid(uid);
    char hostname[HOST_NAME_MAX]; 
    gethostname(hostname,HOST_NAME_MAX);
    int max_size = HOST_NAME_MAX + PATH_MAX + 512;
    char * terminal = malloc(max_size * sizeof(char));
    if(terminal == NULL) return NULL;
    snprintf(terminal, max_size,"%s@%s %s$",pws->pw_name,hostname,cwd);
    return terminal;
}

int main(void){
    char * term = terminal();


    while(true){
        printf("%s ",term);
        char input[512] = "";
        fgets(input,512,stdin);
        char * befehl_abschnitt = strtok(input,"&");
        while(befehl_abschnitt != NULL){
            char befehl[32] = "";
            char argument[108] = "";
            sscanf(befehl_abschnitt,"%32s %512s",befehl,argument);
            printf("Befehl %s\n", befehl);
            printf("Argument %s\n", argument);
            //Fork einbauen
            pid_t p = fork();
            if(p<0){
                perror("fork fail");
                exit(1);
            }else if(p == 0){
                // Child Process
                char * arr[] = {befehl,argument,NULL};
                execvp(befehl, arr);
                exit(-1);
            }else{
                //Parent Process
                sleep(1);
                int status;
                if(wait(&status) == p && WIFEXITED(status)){
                    if(WEXITSTATUS(status) != 0){
                        printf("%s %s did not work and returned %i. Ending programm\n",befehl,argument,WEXITSTATUS(status));
                        exit(0);
                    }
                }
            }
            befehl_abschnitt = strtok(NULL,"&");
        }
    } 
}