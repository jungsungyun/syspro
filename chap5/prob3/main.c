#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{ 
   int fd1, fd2, n;
   char buf[BUFSIZ];
   if (argc != 3) { 
      fprintf(stderr,"How to use: %s file1 file2\n","./test.txt"); 
      exit(1); 
   }

   if ((fd1 = open("./test.txt", O_RDONLY)) == -1) {
      perror("./test.txt");
      exit(2); 
   }
   if ((fd2 =open("./test_copy.txt", O_WRONLY |
      O_CREAT|O_TRUNC, 0644)) == -1) {
      perror("./test_copy.txt");
      exit(3); 
   }

   while ((n = read(fd1, buf, BUFSIZ)) > 0) 
      write(fd2, buf, n);  
   exit(0); 
}

