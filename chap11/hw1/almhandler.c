#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

void *my_signal(int signo, void (*handler)(int)) {
    struct sigaction sa, old_sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);  
    sa.sa_flags = 0;  

    if (sigaction(signo, &sa, &old_sa) == -1) {
        perror("failed");
        return NULL;
    }
    return old_sa.sa_handler; 
}

int main() {
    my_signal(SIGALRM, alarmHandler);

    alarm(5);

    int i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    return 0;
}

