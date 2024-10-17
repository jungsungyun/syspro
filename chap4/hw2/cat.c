#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc < 2) {
  
        fp = stdin;
       
    } else {
        
        for (int i = 1; i < argc; i++) {
            fp = fopen(argv[i], "r"); 
            if (fp == NULL) {
                perror("error");
                continue; 
            }

            printf( argv[i]);
            
            while ((c = getc(fp)) != EOF) {
                putc(c, stdout);
            }

            fclose(fp);
        }
    }

    return 0;
}

