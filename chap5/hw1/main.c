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

void printLineFromSavedText(char savedText[MAX_LINES][MAX_CHARS], int lineNumber) {
    printf("%s", savedText[lineNumber]);
}

int main() {
    char savedText[MAX_LINES][MAX_CHARS] = {0};  
    const char *filename = "test.txt";           

    printf("File read success\n");               
    printf("Total Line : 4\n");                  
    readFileToArray(savedText, filename);        

    int lineNumber;
    printf("You can choose 1 ~ 4 Line\n");       
    printf("Pls 'Enter' the line to select: ");  
    scanf("%d", &lineNumber);

    printLineFromSavedText(savedText, lineNumber - 1);  
    return 0;
}

