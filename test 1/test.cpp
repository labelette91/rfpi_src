/* ===================================================
C code : test.cpp
* ===================================================
*/

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "..\RCSwitch.h"
#include "..\RcOok.h"
#include "..\Sensor.h"


typedef struct  {
  char * Name;
  char * FieldName;
  byte addr;
  byte bitStart;
  byte len;
  char * Memo[8];
}TRegister;

TRegister Reg[10]{
  { "R1","F1", 0 , 0 , 7 , {"bit1","bit2"} },
  { "R2", "F2",0 , 0 , 7 ,{ "bit1","bit2" } },

};

TRegister *Regs[] = {
  &Reg[0],
  &Reg[1],

};

typedef std::map<char*, TRegister*> TRegisterMap;

TRegisterMap RegMap;

void initRegMap()
{
  int i = 0;
  while (Reg[i].addr != 0)
    RegMap[Reg[i].FieldName] = &Reg[i];
}
char * printReg(byte adr, byte value)
{
  static char buf[1024];
  int len = 0;
  TRegister *Reg = Regs[adr];
  int val,mask;
  char * Desc = "";
  std::string mes;

  len = sprintf(&buf[len], "%02X %s : %2X ", adr, Reg->Name,value);

  while (Reg->addr == adr)
  {
    Desc = "";
    val = value >> Reg->addr;
    mask = (1 << Reg->len) - 1 ;
    val = val & mask;
    if (Reg->Memo!=0)
      Desc = Reg->Memo[val];

    len+=sprintf(&buf[len], " [%s : %2X %s] ", Reg->FieldName, val,Desc );
  }
  return buf;
}

int main(int argc, char *argv[])
{
	int RXPIN = 5;
	int TXPIN = -1;

	if(wiringPiSetup() == -1)
		return 0;

	RCSwitch *rc = new RCSwitch(RXPIN,TXPIN);

	while (1)
	{
		if (rc->OokAvailable())
		{
			char message[100];

			rc->getOokCode(message);
			printf("%s\n",message);

			Sensor *s = Sensor::getRightSensor(message);
			if (s!= NULL)
			{
				printf("Temp : %f\n",s->getTemperature());
				printf("Humidity : %f\n",s->getHumidity());
				printf("Channel : %d\n",s->getChannel());
			}
			delete s;
		}
		delay(1000);
	}
}
