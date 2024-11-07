 #include <stdio.h>
 #include <unistd.h>

 
 int main()
 {    
     printf("My process number : [%d] \n", getpid());
     printf("My parents process number : [%d] \n", getppid());
 }

