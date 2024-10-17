#include <stdio.h>
int main(int argc, char *argv[])
{
   char c;
   FILE *fp1, *fp2;
   if (argc !=3) {
      fprintf(stderr,  "How to use: %s File1 File2\n", argv[0]);
      return 1;
   }
   fp1 = fopen(argv[1], "r");
   if (fp1 == NULL) {
      fprintf(stderr, "File %s Open Error", "file1.txt");
      return 2;
   }

   fp2 = fopen("file2.txt", "a");
   while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp2);

   fclose(fp1);
   fclose(fp2);
   return 0;
}

