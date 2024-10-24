#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat"
int main(int argc, char *argv[])
{
   int fd, num;
	char c; 
   struct db record;
   if (argc < 2) {
      fprintf(stderr, "How to use : %s file\n", argv[0]);
      exit(1);
   }
   if ((fd = open(argv[1], O_RDONLY)) == -1) {
      perror(argv[1]);
      exit(2);
   }
   do {
      
      if (scanf("%d", &num == 0))
	  {
         printf("0: list of all goods, 1: list of available goods\n");
		 while(fread(&record, sizeof(record), l,fp) > 0)
			 	if(record.id != 0)
		  			 printf("%d      %s          %s          %d              %d", record.id,record.name, record.category, record.expired_date, record.stoc    k);


      } 
	  if scanf("%d", &num == 1)
	  {
		if(record.stock == 0 or record.expired_date <=2023)
		{
			if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.num != 0))
       				printf("0: list of all goods, 1: list of available goods\n");
					printf("id		name		category	expired date	stock\n");
					printf("%d		%s			%s			%d				%d", record.id,record.name, record.category, record.expired_date, record.stock);

		}
	  }


		
	 
	  
   }
   close(fd);
   exit(0);
}

