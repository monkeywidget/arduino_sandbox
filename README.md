Get Arduino working with BAITE 
==============================

I'm using
- OSX Yosemite (10.10.x)
- Arduino IDE

BAITE Arduino Nano - BTE14-01
=============================

This chip includes a USB port!

- Arduino IDE settings
     - board: set to Adruino Nano
     - processor: set to ATMEGA328 5V/16MHz
     - programmer: AVR ISP

BAITE Arduino Pro Mini - BTE13-010A
===================================

This chip does not include a USB port and so requires a transfer chip - see below for wiring

- Pro Mini 168 Mini ATMEGA168 5V/16MHz
     - BTE13-010A
- USB to TTL transfer chip
     - BTE13-009
- Arduino IDE settings
     - board: set to Adruino Pro / Pro Mini
     - processor: set to ATMEGA168 5V/16MHz
     - programmer: AVR ISP

Connect the USB programmer
--------------------------

The connecting pins are:

     USB:340 connector   |   Pro Mini
     BTE13-009           |   BTE13-010A
     -----------------   |   -------------------
                   DTR   |   DTR
                   RXD   |   TXO
                   TXD   |   RXI
                   VC    |   VCC
          unused:  CTS   |   other GND - unused (do not connect)
                   GND   |   GND


Driver
======

These chips need a driver: see below in "Troubleshooting the upload"
- http://www.wch.cn/download/CH341SER_MAC_ZIP.html
- http://www.arduined.eu/ch340g-converter-windows-7-driver-download/


Troubleshooting the upload
==========================

The problem
-----------

- Arduino IDE is trying to upload to "COM1" which is obviously not a OSX USB port (it's a Windows/DOS name)
- the Arduino is not showing up as a serial port

When trying to upload, you may see:

      avrdude: ser_open(): can't open device "COM1": No such file or directory
      ioctl("TIOCMGET"): Inappropriate ioctl for device

- http://arduino.stackexchange.com/questions/3324/arduino-compatibles-serial-port-not-showing-mac-osx

The Solution
------------

In summary, all of:
- you need a CH340 / CH341 driver 
- the driver isn't signed and therefore you need to run a special command in terminal
- you need to restart a bunch of times

From:
- http://0xcf.com/2015/03/13/chinese-arduinos-with-ch340-ch341-serial-usb-chip-on-os-x-yosemite/
- http://kiguino.moos.io/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html
- video tutorial: https://www.youtube.com/watch?v=RTmjy3uDhPg

Turns out that the driver isn’t signed and in Yosemite, driver files must be signed to be used. There’s a command we can issue to bypass this.


1. Install software but don’t restart yet.
     1. ch34x - https://drive.google.com/file/d/0B8sZKxW3s0j-QU52N1ZCbFduYUE/view
1. in Terminal run:
     1. sudo nvram boot-args=”kext-dev-mode=1″
1. Restart your Mac
1. try again.  If the port isn't showing up, restart AGAIN (it took 3 times for me)
1. OPTIONAL in Terminal:
     1. sudo ln -s /dev/tty.wch\ ch341\ USB\=\>RS232\ 1410 /dev/tty.wch


More notes:

- check the apple menu "about this mac" to see the USB device
- http://arduino-project.net/driver-ch340g/
- http://www.kupply.com/dccele-dccduino-arduino-uno-clone/
- http://javacolors.blogspot.com/2014/08/dccduino-usb-drivers-ch340-ch341-chipset.html


FTDI drivers?
-------------

1. FTDI  - https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/mac
1. could do next: http://forum.arduino.cc/index.php/topic,27266.0.html

