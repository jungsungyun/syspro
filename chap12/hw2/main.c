#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

int main() {
    int pipefd[2]; 
    pid_t pid1, pid2;
    char buffer[128];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid1 == 0) {  
        close(pipefd[PIPE_READ]);

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 

        write(pipefd[PIPE_WRITE], buffer, strlen(buffer) + 1);
        close(pipefd[PIPE_WRITE]); 

        exit(0);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid2 == 0) {  
        close(pipefd[PIPE_WRITE]);

        read(pipefd[PIPE_READ], buffer, sizeof(buffer));

        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper((unsigned char) buffer[i]);
        }
        printf("%s\n", buffer);

        close(pipefd[PIPE_READ]);  
        exit(0);
    }

    close(pipefd[PIPE_READ]);
    close(pipefd[PIPE_WRITE]);

    wait(NULL);  
    wait(NULL);  

    return 0;
}

