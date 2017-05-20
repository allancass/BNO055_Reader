// SerialTest.cpp : Defines the entry point for the console application.
//

//#include <iostream>
//#include <windows.h>
//#include "Serial.h"
//#include "stdafx.h"
#include "IMU.h"
#include <stdio.h>

//using namespace std;

//#define RX_BUFFSIZE 20

//void printUsage(_TCHAR progName[]);


int _tmain(/*int argc, _TCHAR* argv[]*/)
{
	
	BNO055 IMU(true);
	printf("ID Error: %d\n", IMU.Check_ID());
	printf("IMU Data Size: %d\n", sizeof(IMU_Data));
	IMU.Check_SW();
	printf("SW Size: %d\n", sizeof(SW));
	IMU.Get_UID();
	IMU.Check_SW();
	//printf("Address: %x %x %x %x\n", &IMU.ChipID.CHIP_ID, &IMU.ChipID.ACC_ID, &IMU.ChipID.MAG_ID, &IMU.ChipID.GYR_ID);

	Interupt_Configuration test;
	

	/*	try
	{
		cout << "Opening com port"<< endl;
		
		tstring commPortName(TEXT("COM9"));
		
		Serial serial(commPortName);
		cout << "Port opened" << endl;

		cout << "writing something to the serial port" << endl;
		serial.flush();
		
		char hi[] = { 0xAA,0x01,0x00,0x04 };
		//int bytesWritten = serial.write(hi);
		int bytesWritten = serial.write(hi, 4);
		cout << bytesWritten << " bytes were written to the serial port" << endl;
		if(bytesWritten != sizeof(hi) - 1)
		{
			cout << "Writing to the serial port timed out" << endl;
		}

		char buffer[RX_BUFFSIZE];

		cout << "Reading from the serial port: ";
		
		for(int i = 0; i < 10; i++)
		{
			int charsRead = serial.read(buffer, RX_BUFFSIZE);
			if (charsRead > 0)
			{
				for (auto i = 0; i < charsRead; i++)
				{
					printf(" %x", buffer[i]&0xff);
				}
			}
			Sleep(100);
		}
		cout << endl;

	}catch(const char *msg)
	{
		cout << msg << endl;
	}

	cout << "press enter to quit" << endl;/**/
	
	scanf("");

	return 0;
}
/*
void printUsage(_TCHAR progName[])
{
#if defined(UNICODE)
	wcout << progName << " <comm port>" << endl
		 << "e.g., " << progName << " COM1" << endl;
#else
	cout << progName << " <comm port>" << endl
		 << "e.g., " << progName << " COM1" << endl;
#endif
	
}/**/