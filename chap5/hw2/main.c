#include <stdio.h>

#define MAX_LINES 10    
#define MAX_CHARS 100   

void readFileToArray(char savedText[MAX_LINES][MAX_CHARS], const char *filename) {
    FILE *file = fopen(filename, "r");
    int line = 0;

    while (fgets(savedText[line], MAX_CHARS, file) != NULL && line < MAX_LINES) {
        line++;
    }

    fclose(file);
}

void printAllLinesReversed(char savedText[MAX_LINES][MAX_CHARS], int totalLines) {
    
    for (int i = totalLines - 1; i >= 0; i--) {
        printf("%s", savedText[i]);
    }
}

int main() {
    char savedText[MAX_LINES][MAX_CHARS] = {0};  
    const char *filename = "test.txt";           
              
    readFileToArray(savedText, filename);       

    int totalLines = 4;  

   
    printAllLinesReversed(savedText, totalLines);  

    return 0;
}

