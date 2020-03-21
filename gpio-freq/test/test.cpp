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
    	int count = 4 ;
    	#define MAXS 128
    	
    if (argc>=2)
    count =  atoi(argv[1]) ;
//    else
if (count>=MAXS) count = MAXS;

    Device = DeviceR + "17" ;
    printf("opening %s  \n",Device.c_str());
    
    fp = fopen(Device.c_str(), "w");
    if ( fp == NULL ) {
       printf("[ERROR] %s device not found - kernel driver must be started !!\n",Device.c_str());
       exit(1);
    }

//    char buffer[2048];
//    char * bstart = buffer;
    int bufer[MAXS] ;
    for (int i=0;i<count;i++) bufer[i] = (i+1)*100 ;

    fwrite (bufer,4,count,fp);

    return 0;

}
