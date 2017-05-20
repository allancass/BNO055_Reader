#include "IMU.h"

#include "Serial.h"
#include "stdafx.h"

void print_buffer(char name[], uint8_t buff[], uint8_t length)
{
	printf("%s: ", name);
	for (auto i = 0; i < length; i++)
	{
		printf("%02x", buff[i]);
	}
	printf("\n");
}

int BNO055::UART_Response(uint8_t length = 0, uint8_t buffer[] = nullptr)
{
	/*Reads the BNO055 response to a read/write command
	If the chip is returning data the data is read into the buffer.*/

	/*Reads initial 2 byte response to determine the type of response.*/
	/* BST BNO055 pg 93 Section 4-7 UART Protocol*/
	int to_read = 2;
	while (to_read)
	{
		to_read-=(*serial).read((char*)CMD_response, 2, false);
		Sleep(1);
	}
	
	print_buffer("CMD Response: ", CMD_response, 2);

	switch (CMD_response[0])
	{
	case 0xBB:
		to_read = CMD_response[1];
		while (to_read)
		{
			//to_read-=(*serial).read((char*)read_buffer, CMD_response[1], false);
			to_read -= (*serial).read((char*)buffer, CMD_response[1], false);
			Sleep(1);
		}
		//print_buffer("Response: ", read_buffer, CMD_response[1]);
		print_buffer("Response: ", buffer, CMD_response[1]);
		return (length - CMD_response[1]);
		break;
	case 0xEE:
		switch (CMD_response[1])
		{
		case 0x01:
			//printf("Write Success");
			return 0;
			break;
		case 0x02:
			printf("Error: Read Fail\n");
			break;
		case 0x03:
			printf("Error: Write Fail\n");
			break;
		case 0x04:
			printf("Error: REGMAP Invalid Address\n");
			break;
		case 0x05:
			printf("Error: REGMAP Write Disabled\n");
		case 0x06:
			printf("Error: Wrong Start Byte\n");
			break;
		case 0x07:
			printf("Error: Bus Over Run Error\n");
			break;
		case 0x08:
			printf("Error: Max Length Error\n");
			break;
		case 0x09:
			printf("Error: Min Length Error\n");
			break;
		case 0x0A:
			printf("Error: Recieve Character Timeout\n");
			break;					
		default:
			printf("Error: Unknown Error");
			break;
		}
	default:
		printf("Unknown Response Byte\n");
		break;
	}
	return (int) CMD_response[1];
}

int BNO055::register_write(uint8_t reg_addr, uint8_t length, uint8_t buffer[])
{
	reg_write[2] = reg_addr;
	reg_write[3] = length;
	print_buffer("reg write", reg_write, 4);
	(*serial).write((char*)reg_write, 4);
	(*serial).write((char*)buffer, length);
	return UART_Response();
}

int BNO055::register_read(uint8_t reg_addr, uint8_t length, uint8_t buffer[])
{
	reg_read[2] = reg_addr;
	reg_read[3] = length;
	print_buffer("reg read", reg_read, 4);
	(*serial).write((char*)reg_read, 4);
	return UART_Response(length, buffer);
}

int BNO055::Set_Page(uint8_t set_page)
{
	if (page != set_page) { 
		printf("Page = %d\n", set_page);
		page = set_page;
		return register_write(PAGE_ID, 1, &set_page); }
	return 0;
}

int BNO055::Check_ID()
{
	/*Reads BNO055 Chip ID and returns non zero value if the IDs do not match*/
	if (page != 0) { Set_Page(0); }	/* Chip ID is on page 0, sets to page 0 if not there*/
	register_read(CHIP_ID, sizeof(ChipID), (uint8_t*)&ChipID);
	return ((*((uint32_t*)(&ChipID))) - (uint32_t)0x0f32fba0);
}

int BNO055::Check_SW()
{
	/*Reads BNO055 SW Information */
	if (page != 0) { Set_Page(0); }	/* SW Info on page 0, sets to page 0 if not there*/
	return register_read(SW_REV_ID_LSB, sizeof(SW_Version), (uint8_t*)&SW_Version);
}

int BNO055::Get_Motion_Data()
{
	/*Reads the IMU motion data (all of it)*/
	if (page != 0) { Set_Page(0); } /*Motion data is on page 0*/
	return register_read(ACC_DATA_X_LSB, sizeof(Motion_Data), (uint8_t*)&Motion_Data);
}

int BNO055::Get_IMU_System_Status()
{
	/*Reads the System status, Temp, Cal, CLK, Status/Error Codes*/
	if (page != 0) { Set_Page(0); } /*Status data is on page 0*/
	return register_read(TEMP, sizeof(IMU_System_Status), (uint8_t*)&IMU_System_Status);
}

int BNO055::Get_Mode_Configuration()
{
	/*Reads System Modes, and settings*/
	if (page != 0) { Set_Page(0); } /*Data is on page 0*/
	return register_read(UNIT_SEL, sizeof(Modes), (uint8_t*)&Modes);
}

int BNO055::Get_Axis_CFG()
{
	/*Reads the Axis Configuration*/
	if (page != 0) { Set_Page(0); } /*Data is on page 0*/
	return register_read(AXIS_MAP_CONFIG, sizeof(Axis_CFG), (uint8_t*)&Axis_CFG);
}

int BNO055::Get_Offsets()
{
	/*Reads in the IMU Offset/Radius data*/
	if (page != 0) { Set_Page(0); } /*Data is on page 0*/
	return register_read(ACC_OFFSET_X_LSB, sizeof(Offsets), (uint8_t*)&Offsets);
}

int BNO055::Get_Peripheral_CFG()
{
	/*Reads in the ACC/MAG/GYR Configuration Settings*/
	if (page != 1) { Set_Page(1); } /*Data is on page 1*/
	return register_read(ACC_Config, sizeof(Peripheral), (uint8_t*)&Peripheral);
}

int BNO055::Get_Interupt_CFG()
{
	/*Reads in the Interupt Configuration Settings*/
	if (page != 1) { Set_Page(1); } /*Data is on page 1*/
	return register_read(INT_MSK, sizeof(Interupt_CFG), (uint8_t*)&Interupt_CFG);
}

int BNO055::Get_UID()
{
	/*Reads the BNO UID from Bosch*/
	if (page != 1) { Set_Page(1); }	/* SW Info on page 0, sets to page 0 if not there*/
	return register_read(UNIQUE_ID, sizeof(BNO_unique_ID), BNO_unique_ID);
}

BNO055::BNO055(bool primary_address)
{
	if (primary_address) { I2C_Address = I2C_Address_0; }
	else { I2C_Address = I2C_Address_1; }

	tstring commPortName(TEXT("COM9"));
	serial = new Serial(commPortName);
	(*serial).flush();
}

BNO055::~BNO055()
{
	delete serial;
}