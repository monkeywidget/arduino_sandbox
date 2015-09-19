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

The problem:


      avrdude: ser_open(): can't open device "COM1": No such file or directory
      ioctl("TIOCMGET"): Inappropriate ioctl for device

- http://arduino.stackexchange.com/questions/3324/arduino-compatibles-serial-port-not-showing-mac-osx


Solution from:
- http://0xcf.com/2015/03/13/chinese-arduinos-with-ch340-ch341-serial-usb-chip-on-os-x-yosemite/


      Turns out that the driver isn’t signed and in Yosemite, driver files must be signed to be used. There’s a command we can issue to bypass this.


1. Install software but don’t restart yet.
1. in Terminal run:
     1. sudo nvram boot-args=”kext-dev-mode=1″
1. Restart your Mac
1. in Terminal:
     1. sudo ln -s /dev/tty.wch\ ch341\ USB\=\>RS232\ 1410 /dev/tty.wch


More notes:

- check the apple menu "about this mac" to see the USB device
- http://arduino-project.net/driver-ch340g/
- http://www.kupply.com/dccele-dccduino-arduino-uno-clone/
- http://javacolors.blogspot.com/2014/08/dccduino-usb-drivers-ch340-ch341-chipset.html



FTDI drivers?
-------------
could do next: http://forum.arduino.cc/index.php/topic,27266.0.html



