# IOT2019_SASIDHARAN_TEMP&HUMIDITY DATA LOGGING

ACKNOWLEDGEMENT

I would like to express my special thanks of gratitude to my teacher mrs Kayalvizhi  jayavel  who gave me the golden opportunity to do this wonderful project on the topic temperature and humidity data logging  which also helped me in doing a lot of Research and i came to know about so many new things I am really thankful to them.

Secondly i would also like to thank my parents and friends who helped me a lot in finalizing this project within the limited time frame.


ABSTRACT

As Engineers we always rely upon the data collected to design or improve a system. Recording data and analyzing them is a common practice in most of the industries, here we are building  Data  Logger Project where we will learn how we can log data at a specific interval of time. We will use an esp8266  wifi module board to read some data (here temperature, humidity, date and time) and save them on a SD card and the cloud simultaneously.


HARDWARE REQUIRED:
•	Nodemcu ESP8266 module                       -- 380rs [ Amazon]
•	Micro SD card module                         --150rs [ Amazon]
•	Jumper Wires                                              
•	DHT11 Temperature and Humidity sensor         --215rs[ Amazon]
•	DS3231 Real time clock module                --222rs[ Amazon]
•	Micro USB cable

SOFTWARE REQUIRED :
•	Arduino IDE.
•	ESP8266 library.
•	RTC MODULE Library.
•	DHT11 Library.



                TOTAL COST OF COMPONENTS :- RS.1200

SYSTEM OVERVIEW

The main component of the setup is the Nodemcu ESP8266 module. All the other hardware components are connected   to the Nodemcu. The board is programmed in Arduino IDE and uses the ESP8266,RTC ,DHT11 sensor libraries. These libraries have been added to the Arduino IDE.
DS3231 is a RTC (Real Time Clock) module. It is used to maintain the date and time for most of the Electronics projects. This module has its own coin cell power supply using which it maintains the date and time even when the main power is removed or the MCU has gone though a hard reset. So once we set the date and time in this module it will keep track of it always

DHT11 is a Temperature come Humidity sensor. It sends the values of temperature and humidity as an 8-bit data serially through the output pin of the module. The library reads this data by using the software serial function of the Arduino.


