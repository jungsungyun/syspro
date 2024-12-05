#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define READ 0	
#define WRITE 1

int main(int argc, char* argv[]) {
    char str[1024];
    char *command1, *command2;
    int fd[2];

    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; 

    if (strchr(str, '|') != NULL) {  
        command1 = strtok(str, "|");  
        command2 = strtok(NULL, "|"); 

        
        if (pipe(fd) == -1) {
            perror("pipe");
            exit(1);
        }

        if (fork() == 0) {
            close(fd[READ]);  
            dup2(fd[WRITE], STDOUT_FILENO);  
            close(fd[WRITE]);  

            execlp(command1, command1, (char *)NULL);  
            perror("execlp command1 failed");
            exit(1);
        } else {
            if (fork() == 0) {
                close(fd[WRITE]);  
                dup2(fd[READ], STDIN_FILENO);  
                close(fd[READ]);  

                execlp(command2, command2, (char *)NULL); 
                perror("execlp command2 failed");
                exit(1);
            } else {
                close(fd[READ]);
                close(fd[WRITE]);
                wait(NULL);  
                wait(NULL);  
            }
        }
    } else {
        printf("No pipe symbol (|) found. Exiting.\n");
    }

    return 0;
}

