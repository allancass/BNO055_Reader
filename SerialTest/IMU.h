#pragma once
/*If you think this looks easy, consider I basically had to copy and paste a 
105 page PDF into this header file.  You try manually retyping that some time.
If you still think that's easy, I hate you.*/

#include <iostream>
#include <windows.h>
#include "Serial.h"
#include "stdafx.h"

typedef enum PWR_MODE {
	NORMAL = 0x00,
	Low_Power = 0x01,
	Suspend = 0x02
};

/* BST BNO055 Table 3-5*/
typedef enum Operating_Mode {
	CONFIGMODE = 0x00,
	ACCONLY = 0x01,
	MAGONLY = 0x02,
	GYRONLY = 0x03,
	ACCMAG = 0x04,
	ACCGYRO = 0x05,
	MAGGYRO = 0x06,
	AMG = 0x07,
	IMU = 0x08,
	COMPASS = 0x09,
	M4G = 0x0A,
	NDOF_FMC_OFF = 0x0B,
	NDOF = 0x0C
};

/* BST BNO055 pg 50 Table 4-2 Register Map Page 0*/
typedef enum REGISTER_Page_0 {
	CHIP_ID = 0x00,
	ACC_ID = 0x01,
	MAG_ID = 0x02,
	GYR_ID = 0x03,
	SW_REV_ID_LSB = 0x04,
	SW_REV_ID_MSB = 0x05,
	BL_Rev_ID = 0x06,
	PAGE_ID = 0x07,
	ACC_DATA_X_LSB = 0x08,
	ACC_DATA_X_MSB = 0x09,
	ACC_DATA_Y_LSB = 0x0A,
	ACC_DATA_Y_MSB = 0x0B,
	ACC_DATA_Z_LSB = 0x0C,
	ACC_DATA_Z_MSB = 0x0D,
	MAG_DATA_X_LSB = 0x0E,
	MAG_DATA_X_MSB = 0x0F,
	MAG_DATA_Y_LSB = 0x10,
	MAG_DATA_Y_MSB = 0x11,
	MAG_DATA_Z_LSB = 0x12,
	MAG_DATA_Z_MSB = 0x13,
	GYR_DATA_X_LSB = 0x14,
	GYR_DATA_X_MSB = 0x15,
	GYR_DATA_Y_LSB = 0x16,
	GYR_DATA_Y_MSB = 0x17,
	GYR_DATA_Z_LSB = 0x18,
	GYR_DATA_Z_MSB = 0x19,
	EUL_Heading_LSB = 0x1A,
	EUL_Heading_MSB = 0x1B,
	EUL_Roll_LSB = 0x1C,
	EUL_Roll_MSB = 0x1D,
	EUL_Pitch_LSB = 0x1E,
	EUL_Pitch_MSB = 0x1F,
	QAU_Data_w_LSB = 0x20,
	QAU_Data_w_MSB = 0x21,
	QAU_Data_x_LSB = 0x22,
	QAU_Data_x_MSB = 0x23,
	QAU_Data_y_LSB = 0x24,
	QAU_Data_y_MSB = 0x25,
	QAU_Data_z_LSB = 0x26,
	QAU_Data_z_MSB = 0x27,
	LIA_DATA_X_LSB = 0x28,
	LIA_DATA_X_MSB = 0x29,
	LIA_DATA_Y_LSB = 0x2A,
	LIA_DATA_Y_MSB = 0x2B,
	LIA_DATA_Z_LSB = 0x2C,
	LIA_DATA_Z_MSB = 0x2D,
	GRV_DATA_X_LSB = 0x2E,
	GRV_DATA_X_MSB = 0x2F,
	GRV_DATA_Y_LSB = 0x30,
	GRV_DATA_Y_MSB = 0x31,
	GRV_DATA_Z_LSB = 0x32,
	GRV_DATA_Z_MSB = 0x33,
	TEMP = 0x34,
	CALIB_STAT = 0x35,
	ST_RESULT = 0x36,
	INT_STA = 0x37,
	SYS_CLK_STATS = 0x38,
	SYS_STATUS = 0x39,
	SYS_ERR = 0x3A,
	UNIT_SEL = 0x3B,
	//Reserved = 0x3C,
	OPR_MODE = 0x3D,
	PWR_MODE = 0x3E,
	SYS_TRIGGER = 0x3F,
	TEMP_SOURCE = 0x40,
	AXIS_MAP_CONFIG = 0x41,
	AXIS_MAP_SIGN = 0x42,
	//Reserved = 0x43 to 0x54,
	ACC_OFFSET_X_LSB = 0x55,
	ACC_OFFSET_X_MSB = 0x56,
	ACC_OFFSET_Y_LSB = 0x57,
	ACC_OFFSET_Y_MSB = 0x58,
	ACC_OFFSET_Z_LSB = 0x59,
	ACC_OFFSET_Z_MSB = 0x5A,
	MAG_OFFSET_X_LSB = 0x5B,
	MAG_OFFSET_X_MSB = 0x5C,
	MAG_OFFSET_Y_LSB = 0x5D,
	MAG_OFFSET_Y_MSB = 0x5E,
	MAG_OFFSET_Z_LSB = 0x5F,
	MAG_OFFSET_Z_MSB = 0x60,
	GYR_OFFSET_X_LSB = 0x61,
	GYR_OFFSET_X_MSB = 0x62,
	GYR_OFFSET_Y_LSB = 0x63,
	GYR_OFFSET_Y_MSB = 0x64,
	GYR_OFFSET_Z_LSB = 0x65,
	GYR_OFFSET_Z_MSB = 0x66,
	ACC_RADIUS_LSB = 0x67,
	ACC_RADIUS_MSB = 0x68,
	MAG_RADIUS_LSB = 0x69,
	MAG_RADIUS_MSB = 0x6A
};

/* BST BNO055 pg 53 Table 4-3 Register Map Page 1*/
typedef enum REGSITER_Page_1 {
	//Reserved 0x00 - 0x06
	//PAGE_ID = 0x07,
	ACC_Config = 0x08,
	MAG_Config = 0x09,
	GYR_Config_0 = 0x0A,
	GYR_Config_1 = 0x0B,
	ACC_Sleep_Config = 0x0C,
	GYR_Sleep_Config = 0x0D,
	//Reserved 0x0E,
	INT_MSK = 0x0F,
	INT_EN = 0x10,
	ACC_AM_THRES = 0x11,
	ACC_INT_Settings = 0x12,
	ACC_HG_Duration = 0x13,
	ACC_HG_Thres = 0x14,
	ACC_NM_THRE = 0x15,
	ACC_NM_SET = 0x16,
	GYR_INT_SETING = 0x17,
	GYR_HR_X_SET = 0x18,
	GYR_DUR_X = 0x19,
	GYR_HR_Y_SET = 0x1A,
	GYR_DUR_Y = 0x1B,
	GYR_HR_Z_SET = 0x1C,
	GYR_DUR_Z = 0x1D,
	GYR_AM_THRES = 0x1E,
	GYR_AM_SET = 0x1F,
	//Reserved 0x20-4F,
	UNIQUE_ID = 0x50 //0x50 to 0x5F
	//Reserved 0x60 - 0x7F
};

/* BST BNO055 pg 90 Table 4-7 I2C Address Selection*/
typedef enum I2C_Address {
	I2C_Address_0 = 0x28,
	I2C_Address_1 = 0x29,
	I2C_Address_HID = 0x40
};

#pragma pack(push,1)
/*Begin Page 0 Registers*/
/* Top Level Page 0 Struct Registers 0x00-0x03*/
struct ChipIDs
{
	/*Registers 0x00-0x03*/
	uint8_t CHIP_ID;
	uint8_t ACC_ID;
	uint8_t MAG_ID;
	uint8_t GYR_ID;
};

/* Top Level Page 0 Struct Registers 0x04-0x06*/
struct SW
{
	/*Registers 0x04-0x06*/
	uint16_t SW_Version;
	uint8_t Bootloader;
};

/*Template for tripple axis values, type uint16_t */
struct uint16_Tri_Axis
{
	uint16_t X;
	uint16_t Y;
	uint16_t Z;
};

struct Principle_Axes
{
	/*Registers 0x1A-0x1F*/
	uint16_t Yaw;
	uint16_t Roll;
	uint16_t Pitch;
};

struct Quaternion
{
	/*Registers 0x20-0x27*/
	uint16_t W;
	uint16_t X;
	uint16_t Y;
	uint16_t Z;
};

/* Top Level Page 0 Struct Registers 0x08-0x33*/
struct IMU_Data
{
	/*Contains all IMU Data Registers 0x08 to 0x33 */
	uint16_Tri_Axis ACC;					/*Registers 0x08-0x0D*/
	uint16_Tri_Axis MAG;					/*Registers 0x0E-0x13*/
	uint16_Tri_Axis GYR;					/*Registers 0x14-0x19*/
	Principle_Axes Principle_Axes;			/*Registers 0x1A-0x1F*/
	Quaternion Quaternion;					/*Registers 0x20-0x27*/
	uint16_Tri_Axis Linear_Acceleration;	/*Registers 0x28-0x2D*/
	uint16_Tri_Axis Gravity_Vector;			/*Registers 0x2E-0x33*/
	
};

struct Temperature
{
	/*Register 0x34*/
	uint8_t Degrees;
};

struct Calibration_Status
{
	/*Register 0x35*/
	/*Calibration Status is a series of four 2-Bit fields.
	The :2 here specifies each of these requires 2 bits.
	The total size of this struct is 1 byte (8 bits)*/

	/* Value ranges from 0 to 3
	0: Not Calibrated
	3: Fully Calibrated*/
	uint8_t MAG : 2;
	uint8_t ACC : 2;
	uint8_t GYR : 2;
	uint8_t SYS : 2;
};

struct Self_Test_Result
{
	/*Register 0x36*/
	/*Self Test Results is a series of 1-Bit fields.
	This :1 here specifies each of these requires 1 bit.
	The total size of this struct is 1 byte (8 bits) with
	four of the bits unused*/

	/*Self Test Status
	0: Failed
	1: Passed*/
	uint8_t ACC : 1;
	uint8_t MAG : 1;
	uint8_t GYR : 1;
	uint8_t MCU : 1;
};

struct Interupt_Status
{
	/*Register 0x37*/
	/*Interupt Status of the varius sensors.
	This is a series of 1-Bit fields with some unused (reserved)
	0: Not Triggered
	1: Interup Triggered*/
	uint8_t Reserved0 : 2;		//Unused
	uint8_t GYRO_AM : 1;		//Gyroscope Any Motion Interupt
	uint8_t GYRO_High_Rate : 1;	//Gyroscope High Rate Interup
	uint8_t Reserved1 : 1;		//Unused
	uint8_t ACC_High_G : 1;		//Accelerometer High-G Interupt
	uint8_t ACC_AM : 1;			//Accelerometer Any Motion Interupt
	uint8_t ACC_NM : 1;			//Acclerometer No Motion or Slow Motion Interupt
};

struct IMU_SYS_Status
{
	/*Registers 0x38-0x3A*/
	uint8_t Clock_Status;
	/*Clock Status BIT Register 0x38
	0: Free to configure CLK SRC
	1: In Configuration State*/
	uint8_t System_Status_Code;
	/*System Status Register 0x39
	Value of Register (Not value of bits)
	0: System Idle
	1: System Error
	2: Initializing Peripherals
	3: System Initialization
	4: Executing Self-Test
	5: Sensor Fusion Algorithm Running
	6: System running without Fusion Algorithm*/
	uint8_t System_Error_Code;
	/*System Error Register 0x3A
	Value of Register (Not value of bits)
	0: No Error
	1: Peripheral Initializatio Error
	2: System Initialization Error
	3: Self Test result failed
	4: Register map value out of range
	5: Register map address out of range
	6: Register map write error
	7: BNO low power mode not availbable for selected operation mode
	8: Accelerometer power mode not available
	9: Fusional algorithm conifguruation error
	A: Sensor configuration error*/
};

/* Top Level Page 0 Struct Registers 0x34-0x3A*/
struct IMU_Status
{
	/*Registers 0x34-0x3A*/
	/*Contains IMU Status from various flags*/
	Temperature Temperature;				/*Register 0x34*/
	Calibration_Status Calibration_Status;	/*Register 0x35*/
	Self_Test_Result Self_Test_Result;		/*Register 0x36*/
	Interupt_Status Interupt_Status;		/*Register 0x37*/
	IMU_SYS_Status SYS_Status;					/*Registers 0x38-0x3A*/
};

struct Unit_Selection
{
	/*Register 0x3B*/
	/*Register allows configuration of various units.
	This is a series of 1-Bit fields with some unused (reserved)*/
	uint8_t ACC_Unit : 1;
	/* 0: m/s^2
	1: mg */
	uint8_t GYR_Unit : 1;
	/* 0: dps (Degrees Per Second?)
	1: rps (Radians Per Second?) */
	uint8_t EUL_Unit : 1;
	/* 0: Degrees
	1: Radians */
	uint8_t Reserved0 : 1;
	uint8_t TEMP_Unit : 1;
	/* 0: Celsius
	1: Farenheit */
	uint8_t Reserved1 : 2;
	uint8_t ORI_Android_Windows : 1;
	/* 0: Windows Orientation
	1: Android Orientation */
};

struct System_Triggers
{
	/*Register 3F*/
	uint8_t Self_Test : 1;
	/*Set to trigger self test*/
	uint8_t Reserved : 4;
	uint8_t Reset_System : 1;
	/*Set to reset system*/
	uint8_t Reset_Interupts : 1;
	/*Set to reset all interupt status bigs, and INT Output*/
	uint8_t CLK_SEL : 1;
	/* 0: Use internal oscilator
	   1: Use external oscilator. */
};

/* Top Level Page 0 Struct Registers 0x3B-0x40*/
struct IMU_Modes
{
	/*Register 0x3B-0x40*/
	Unit_Selection Unit_Selection;
	uint8_t Reserved;
	uint8_t Operation_Mode;
	uint8_t Power_Mode;
	uint8_t Temperature_Source;
};

struct Axis_Map
{
	/*Register 0x41*/
	uint8_t X_Axis : 2;
	uint8_t Y_Axis : 2;
	uint8_t Z_Axis : 2;
};

struct Axis_Sign
{
	/*Register 0x42*/
	uint8_t X : 1;
	uint8_t Y : 1;
	uint8_t Z : 1;
};

/* Top Level Page 0 Struct Registers 0x41-0x42*/
struct Axis_Configuration
{
	/*Registers 0x41-0x42*/
	Axis_Map Axis_Map;
	Axis_Sign Axis_Sign;
};

/* Top Level Page 0 Struct Registers 0x55-0x6A*/
struct IMU_Offsets
{
	/*Registers 0x55-0x6A*/
	uint16_Tri_Axis Accelerometer_Offset;	/*Registers 0x55-0x5A*/
	uint16_Tri_Axis Magnetometer_Offset;	/*Registers 0x5B-0x60*/
	uint16_Tri_Axis Gyroscope_Offset;		/*Registers 0x61-0x66*/
	uint16_t Accelerometer_Radius;
	uint16_t Magnetometer_Radius;
};

/*End Page 0 Registers*/
/*Being Page 1 Registers*/

struct ACC_Configuration
{
	/*Register 0x08*/
	uint8_t Range : 2;
	uint8_t BW : 3;
	uint8_t Power_Mode : 3;
};

struct MAG_Configuration
{
	/*Regster 0x09*/
	uint8_t Data_output_rate : 3;
	uint8_t Operating_mode : 2;
	uint8_t Power_mode : 2;
};

struct GYR_Configuration
{
	/*Registers 0x0A-0x0B*/
	uint16_t Range : 3;
	uint16_t Bandwidth : 3;
	uint16_t Reserved : 2;
	uint16_t Power_Mode : 3;
};

struct ACC_Sleep_Configuration
{
	/*Register 0x0C*/
	uint8_t Mode : 1;
	/* 0: Use event driven time based mode
	   1: Use equidistant sampling time-based mode*/
	uint8_t Duration : 4;
	/* 0-5:   0.5ms
	     6:   1ms
		 7:   2ms
		 8:   4ms
		 9:   6ms
		 A:  10ms
		 B:  25ms
		 C:  50ms
		 D: 100ms
		 E: 500ms
		 F: 1ms - suspect may be error and sould be just 's'
		 */
};

struct GYR_Sleep_Configuration
{
	/*Register 0x0D*/
	uint8_t Duration : 3;
	/*	0: Not Allowed
		1:  4ms
		2:  5ms
		3:  8ms
		4: 10ms
		5: 15ms
		6: 20ms
		7: 40ms*/
	uint8_t Auto_Duration : 3;
	/*	0:  2ms
		1:  4ms
		2:  5ms
		3:  8ms
		4: 10ms
		5: 15ms
		6: 18ms
		7: 20ms*/
	/*Gyroscope bandwidth(Hz) | Minimum Autosleep Duration (ms)
			 32							20	
			 64							10
			 12							20
			 23							10
			 47							 5
			116							 4
			230							 4
			Ufiltered (523)				 4 */
};

/* Top Level Page 1 Struct Registers 0x08-0x0D*/
struct Peripheral_Configuration
{
	/*Registers 0x08-0x0D*/
	ACC_Configuration ACC;
	MAG_Configuration MAG;
	GYR_Configuration GYR;
	ACC_Sleep_Configuration ACC_Sleep;
	GYR_Sleep_Configuration GYR_Sleep;
};

struct Interupt
{
	/*Teplate for Registers 0x0F-0x10*/
	/* 0: Disabled
	   1: Enabled */
	uint8_t Reserved0 : 2;
	uint8_t GYR_Any_Motion : 1;
	uint8_t GYR_High_Rate : 1;
	uint8_t Reserved1 : 1;
	uint8_t ACC_High_G : 1;
	uint8_t ACC_Any_Motion : 1;
	uint8_t ACC_No_Motion : 1;
};

struct ACC_Interupt_Settings
{
	/*Register 0x12*/
	uint8_t Any_Motion_Duration : 2;
	/* Any motion interupt triggers if Any_Motion_Duration+1
	consecuitive data points are above the any motion interupt
	threashold defined in ACC_AM_THRES Register.*/

	/*Select which axis of the accelerometer is sued to triger
	an any motion or no motion interupt
	0: Disabled
	1: Enabled */
	uint8_t AMNM_X_Axis : 1;
	uint8_t AMNM_Y_Axis : 1;
	uint8_t AMNM_Z_Axis : 1;
	/*Select which axis of the accelerometer is sued to triger
	a high-G interupt
	0: Disabled
	1: Enabled */
	uint8_t High_G_X_Axis : 1;
	uint8_t High_G_Y_Axis : 1;
	uint8_t High_G_Z_Axis : 1;
};

struct ACC_No_Motion_SET
{
	/*Register 0x16*/
	uint8_t SMNM : 1;
	/* Select slow motion or no motion interupt
	   0: No Motion
	   1: Slow Motion */
	uint8_t Duration : 6;
	/* Function depends on SMNM Setting
	If Slow moition (SMNM=0) then [Duration<1:0>+1]
	consecuitive slope data poiints must be able the slow/
	no motion threshold (ACC_NM_THRES) for the slow/no motion
	interupt to trigger.
	
	If no-motion interpt function has been enabled (SMNM=1) then
	Duration<5:0> efnes the time for which no slope data points
	must exceed the slow/no-motion threschold (ACC_NM_THRES) for 
	the slow/no motion interupt to trigger. The delay time in 
	seconds may be calculated as follows:
	Duration<5:4> = 00 -> [Duration<3:0>*1 + 1]
	Duration<5:4> = 01 -> [Duration<3:0>*4 +20]
	Duration<5:4> = 1X -> [Duration<3:0>*8 +88] */
};

struct ACC_Interupt_Configuration {
	/*Registers 0x11-0x16*/
	uint8_t Any_Motion_Threshold;
	/* Threshold dependent on ACC Range set in ACC_Config Register
	1 LSB =  3.91mg  (2-g range)
	1 LSB =  7.81mg  (4-g range)
	1 LSB = 15.63mg  (8-g range)
	1 LSB = 31.25mg (16-g range) */
	ACC_Interupt_Settings Interupt_Settings;
	uint8_t High_G_Duration;
	/* The high-G Interupt trigger delay according to
	[ACC_High_G_Duration+1]*2ms in range from 2ms to 512ms.*/
	uint8_t High_G_Threshold;
	/* Threshold dependent on ACC Range set in ACC_Config Register
	1 LSB =  7.81mg  (2-g range)
	1 LSB = 15.63mg  (4-g range)
	1 LSB = 31.25mg  (8-g range)
	1 LSB = 62.5mg  (16-g range) */
	uint8_t NM_Threshold;
	/* Threshold dependent on ACC Range set in ACC_Config Register
	1 LSB =  3.91mg  (2-g range)
	1 LSB =  7.81mg  (4-g range)
	1 LSB = 15.63mg  (8-g range)
	1 LSB = 31.25mg (16-g range) */
	ACC_No_Motion_SET NM_SET;
};

struct GYR_Interupt_Settings
{
	/*Register 0x17*/
	/* 1: Enabled
	   0: Disabled */
	uint8_t AM_X_Axis : 1;
	uint8_t AM_Y_Axis : 1;
	uint8_t AM_Z_Axis : 1;
	uint8_t HR_X_Axis : 1;
	uint8_t HR_Y_Axis : 1;
	uint8_t HR_Z_Axis : 1;
	/* 1: Unfiltered
	   0: Filtered */
	uint8_t AM_Filter : 1;
	uint8_t HR_Filter : 1;
};

struct GYR_HR
{
	/*Template for Registers 0x18-0x1D*/
	uint8_t Threshold : 5;
	/*Threshold value dependent on Gyroscop range
	selected in GYR_Config_0 register.
	1 LSB = 62.5   Deg/s in 2000 Deg/s range 
	1 LSB = 31.25  Deg/s in 1000 Deg/s range 
	1 LSB = 15.625 Deg/s in  500 Deg/s range */
	uint8_t Hysterisis : 2;
	/* High rate hystersis for axis = (255+256*Hysterisis)*4 LSB
	Value dependent on Gyroscop range selected in GYR_Config_0 
	register.
	1 LSB = 62.26 Deg/s in 2000 Deg/s range
	1 LSB = 31.13 Deg/s in 1000 Deg/s range
	1 LSB = 15.56 Deg/s in  500 Deg/s range */
	uint8_t Duration;
	/* High Rate Duration = (1+Duration)*2.5ms */
};

struct GYR_AM {
	/*Registers 0x1E-0x1F*/
	uint8_t Threshold;
	/* Any motion threshold is for the gyro any motion interupt.
	Threshold value dependent on Gyroscop range selected
	in GYR_Config_0 register.
	1 LSB = 1    Deg/s in 2000 Deg/s range
	1 LSB = 0.5  Deg/s in 1000 Deg/s range
	1 LSB = 0.25 Deg/s in  500 Deg/s range */
	uint8_t Slope_Samples : 2;
	/*Any motion triggers if [Slope_Samples+1]*4 consecuitive
	data points are above the any motion interupt threshold
	defined in GYRO_AM_THRES Register*/
	uint8_t Awake_Duration : 2;
	/* 8*(2^Awake_Duration) samples */
};

struct GYR_Interupt_Configuration
{
	/*Registers 0x17-0x1F*/
	GYR_Interupt_Settings Interupt_Settings;
	GYR_HR X_HR;
	GYR_HR Y_HR;
	GYR_HR Z_HR;
	GYR_AM AM;
};

/* Top Level Page 1 Struct Registers 0x0F-0x1F*/
struct Interupt_Configuration
{
	/*Registers 0x0F-0x1F*/
	Interupt Mask;
	/* (Mask) When Enabled, Interupt will update the INT_STA Regster 
	and trigger a change on the INT Pin. When Disabled only 
	the INT_STA Register will be upated.*/
	Interupt Enable;
	ACC_Interupt_Configuration ACC;
	GYR_Interupt_Configuration GYR;
};

/* End Page 1 Regsiters*/
#pragma pack(pop)

class BNO055
{
public:
	BNO055(bool primary_address);
	~BNO055();

	int register_write(uint8_t reg_addr, uint8_t length, uint8_t* buffer);
	int register_read(uint8_t reg_addr, uint8_t length, uint8_t* buffer);
	
	/*Background Utilities*/
	int Set_Page(uint8_t set_page);	/* Changes the register page */

	/* Information Set/Get Functions */
	int Check_ID(); /*Checks ChipIDs and verifies correct*/
	int Check_SW(); /*Reads in SW_Version*/
	int Get_Motion_Data(); /*Reads in IMU Data*/
	int Get_IMU_System_Status(); /*Reads in System Status Information*/
	int Set_Mode_Configuration(); /*Set/Get Modes*/
	int Get_Mode_Configuration();
	int Set_Axis_CFG(); /*Sets/Gets the Axis Configuration*/
	int Get_Axis_CFG();
	int Set_Offsets(); /*Sets/Gets Offsets for Calibration*/
	int Get_Offsets();
	int Get_Peripheral_CFG();	/*Configures the ACC/MAG/GRY detailed modes of operation*/
	int Set_Peripheral_CFG();
	int Get_Interupt_CFG();		/*Configures the IMU Interupt Settings*/
	int Set_Interupt_CFG();
	int Get_UID();				/*Reads 128-Bit UID*/

	//UART CMD Buffers
	uint8_t reg_write[4] = { 0xAA,0x00,0x00,0x00 };
	uint8_t reg_read[4] = { 0xAA,0x01,0x00,0x00 };
	uint8_t CMD_response[2] = { 0x00,0x00 };
	uint8_t read_buffer[128];
	
private:
	int UART_Response(uint8_t length, uint8_t buffer[]);
	Serial* serial;
	uint8_t I2C_Address = 0x00;
	uint8_t page = 0x00;
	
	/* Top Level Page 0 Struct Registers 0x00-0x03*/
	struct ChipIDs ChipID;
	/* Top Level Page 0 Struct Registers 0x04-0x06*/
	struct SW SW_Version;
	/* Top Level Page 0 Struct Registers 0x08-0x33*/
	struct IMU_Data Motion_Data;
	/* Top Level Page 0 Struct Registers 0x34-0x3A*/
	struct IMU_Status IMU_System_Status;
	/* Top Level Page 0 Struct Registers 0x3B-0x40*/
	struct IMU_Modes Modes;
	/* Top Level Page 0 Struct Registers 0x41-0x42*/
	struct Axis_Configuration Axis_CFG;
	/* Top Level Page 0 Struct Registers 0x55-0x6A*/
	struct IMU_Offsets Offsets;
	/* Top Level Page 1 Struct Registers 0x08-0x0D*/
	struct Peripheral_Configuration Peripheral;
	/* Top Level Page 1 Struct Registers 0x0F-0x1F*/
	struct Interupt_Configuration Interupt_CFG;
	/*Top Level Page 1 Struct Registers 0x50-0x5F*/
	uint8_t BNO_unique_ID[16];
};