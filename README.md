# LED
Beaglebone Black program used to power up my main desktop computer remotely

It can also be used to:
a) force a power down of the desktop computer
b) force a re-boot of the local networking equipment
c) flash the LEDs on the bbb board (used to test the program without doing any of the above)

The baeglebone is connected to two relays: 
The first is normally open and in parallel to the power button on the case of the desktop.
The other is normally closed and in series with the 240V power to the firewall, switch, and modem.

The forced power down and network re-boot function will activate the appropriate relay for 11 seconds.
The boot function simulates a 100 ms press of the desktop's power button.
