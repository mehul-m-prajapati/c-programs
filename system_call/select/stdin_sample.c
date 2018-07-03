       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/time.h>
       #include <sys/types.h>
       #include <unistd.h>
	#include <errno.h>

       int main(void)
       {
           fd_set rfds;
           struct timeval tv;
           int retval;

     	   /* Watch stdin (fd 0) to see when it has input. */
   	   FD_ZERO(&rfds);
	   FD_SET(0, &rfds);
           /* Wait up to five seconds. */
           tv.tv_sec = 5;
           tv.tv_usec = 0;

           retval = select(1, NULL, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */
           if (retval == -1)
	   {
                 //perror("select()");
		 printf("Err no = %d", errno);
	   }
	   else if (retval)
	   {
		   printf("Data is available now.\n");
           	   FD_ISSET(0, &rfds);
	   } 
	  else
	       printf("No data within five seconds.\n");


	  return 0;
	 //exit(EXIT_SUCCESS);
	}
