#include <arduino.h>

//#define TIMEZONE  8     // Central European Time

//#define BLE_SoftSerial  //软串口模式

#ifndef BLE_SoftSerial  //如果没开启软串口,就开硬串口模式
#if defined(__AVR_ATmega32U4__)
#define BLE_HardSerial Serial1
#else
#define BLE_HardSerial Serial
#endif
#endif

#define DATE_UPDATA 3
#define TIME_UPDATA 12

#define BLE_SPEED 9600  //蓝牙接口速度
