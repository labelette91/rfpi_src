/* ===================================================
C code : test.cpp
* ===================================================
*/

#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

 std::string DeviceR= "/dev/gpiofreq" ;
int main(int argc, char *argv[])
{
    FILE * fp;
    std::string Device ;
    	int dur=0;
    	
//    if (argc>=2)
//    Device =  argv[1] ;
//    else
    if (argc>=2)
    	dur  = atoi( argv[1]) ;

    Device = DeviceR + "17" ;
    printf("opening %s  \n",Device.c_str());
    
    fp = fopen(Device.c_str(), "r");
    if ( fp == NULL ) {
       printf("[ERROR] %s device not found - kernel driver must be started !!\n",Device.c_str());
       exit(1);
    }

//    char buffer[2048];
    long int pulse;
    int mod=0;
//    char * bstart = buffer;
    while (1) {
       int count = fread(&pulse,4,1,fp);

       if ( count > 0 ) {
         /*
         printf("V : [");
         for ( int k = 0 ; k < count ; k ++  ) printf("%d ",buffer[k]);
         printf("\n");
         */
//        buffer[count]=0;
//        printf("count %d \n",count);
        if (pulse>dur){
        	printf("%ld ",pulse);
        	mod++;
        	if ((mod%8)==0)printf("\n");
        	if ( mod >8) 
        		break;
        }

       }else
       	usleep(10000l);
    }
    return 0;

}
