#include <stdio.h> 
#include "student.h"
#incldue <stdlib.h>
int main(int argc, char* argv[])  
{ 
   struct student rec;
   FILE *fp;

   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n","./test.txt");
      exit(1); 
   }

   fp = fopen("./test.txt", "wb");
   fprintf("%-9s %-7s %-4s\n", "StudentID", "Name", "Score"); 
   while (scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3)
   {
      fwrite(&rec, sizeof(rec), 1, fp);
   }
   fclose(fp);
   exit(0);
} 

