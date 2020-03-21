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
    	
//    if (argc>=2)
//    Device =  argv[1] ;
//    else

    Device = DeviceR + "17" ;
    printf("opening %s  \n",Device.c_str());
    
    fp = fopen(Device.c_str(), "w");
    if ( fp == NULL ) {
       printf("[ERROR] %s device not found - kernel driver must be started !!\n",Device.c_str());
       exit(1);
    }

//    char buffer[2048];
//    char * bstart = buffer;
    int bufer[10] ;
    for (int i=1;i<10;i++) bufer[i] = i*10 ;

    fwrite (bufer,4,4,fp);

    return 0;

}
