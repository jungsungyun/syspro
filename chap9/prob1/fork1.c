   #include <stdio.h>
   #include <unistd.h>
   int main()
   {
      int pid;
      printf("[%d] process start \n", getpid());
      pid = fork();
      printf("[%d] return value 0 %d\n", getpid(), pid);
   }
 

