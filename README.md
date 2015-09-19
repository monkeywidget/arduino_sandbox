Get the Arduino Pro Mini working with BAITE 
===========================================

We have
-------

- Pro Mini 168 Mini ATMEGA168 5V/16MHz
     - BTE13-010A
- USB to TTL transfer chip: BTE13-009 (Baite)
- Arduino IDE
- OSX


Connect the USB programmer
--------------------------

The connecting pins are:
- DTR - DTR to board
- RXD - receive - goes to TXO on board
- TXD - transmit - goes to RXI on board
- VC - power to board
- CTS - ??
- GND - ground to board


Driver
------

needs a driver:  
- http://www.wch.cn/download/CH341SER_MAC_ZIP.html
- http://www.arduined.eu/ch340g-converter-windows-7-driver-download/


Uploading program: in Arduino IDE
---------------------------------

- processor: set to ATMEGA168 5V/16MHz
- board: set to Adruino Pro / Pro Mini

Troubleshooting
---------------


      avrdude: ser_open(): can't open device "COM1": No such file or directory
      ioctl("TIOCMGET"): Inappropriate ioctl for device


http://arduino.stackexchange.com/questions/3324/arduino-compatibles-serial-port-not-showing-mac-osx
- check the apple menu "about this mac" to see the USB device
- http://arduino-project.net/driver-ch340g/
- http://www.kupply.com/dccele-dccduino-arduino-uno-clone/
- http://javacolors.blogspot.com/2014/08/dccduino-usb-drivers-ch340-ch341-chipset.html



FTDI drivers?
-------------
could do next: http://forum.arduino.cc/index.php/topic,27266.0.html



