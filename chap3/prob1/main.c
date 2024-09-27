#include "copy.h"
#include <stdio.h>
#include <string.h>

char line[MAXLINE];
char sentences[5][MAXLINE];
int len[5];

void copy(char from[], char to[]);

int main() {
    int i, j;
    char temp[MAXLINE];


    for (i = 0; i < 5; i++) {

        fgets(line, MAXLINE, stdin);
        line[strcspn(line, "\n")] = '\0';
        copy(line, sentences[i]); 
        len[i] = strlen(sentences[i]);
    }


    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (len[i] < len[j]) {

                copy(sentences[i], temp);
                copy(sentences[j], sentences[i]);
                copy(temp, sentences[j]);


                int temp_len = len[i];
                len[i] = len[j];
                len[j] = temp_len;
            }
        }
    }



    for (i = 0; i < 5; i++) {
        printf("%s  %d\n", sentences[i], len[i]);
    }

    return 0;
}
