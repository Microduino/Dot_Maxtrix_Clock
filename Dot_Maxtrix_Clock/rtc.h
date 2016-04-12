#include "Arduino.h"

#include <TimeLib.h>   

#include <Wire.h>
#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;//初始化实时时钟

int sta[6];

unsigned long Time_updata = 0;
void getRtc() {
  Serial.println("GetRtc");
  rtc.getDate();
  rtc.getTime();
  setTime(rtc.getHour(), rtc.getMinute(), rtc.getSecond(),  rtc.getDay(), rtc.getMonth(), rtc.getYear());
#ifdef TIMEZONE
  adjustTime(TIMEZONE * SECS_PER_HOUR);
#endif
}

void setRtc() {
  Serial.println("SetRtc");
  rtc.initClock();  //set a time to start with.
  rtc.setDate(day(), weekday() , month(), 0, year() - 2000); //day, weekday, month, century(1=1900, 0=2000), year(0-99)
  rtc.setTime(hour(), minute() , second()); //hr, min, sec
}

char * getFormatDate(){
  return rtc.formatDate(RTCC_DATE_ASIA);
}

char * getFormatTime(){
  return rtc.formatTime(RTCC_TIME_HMS);
}

