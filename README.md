# Kontroller-mk2
Second iteration of the legacy Kontroller , but more than just a controller.


Yeah , so this is the new version i mentioned . Soooo this one is very very 
much different then the previous one i'll quickly point out the differences
in core functionality below:

mk1
=> uses wifi connectivity
=> works on udp (fire and forget) protocol
=> requires a wifi router between device and controller
=> connection details have to be framed in firmware itself

mk2
=> use BLE(Bluetooth Low Energy)
=> can independently connect to device directly
=> connection details could be dynamically allocated in runtime

on the top of these mk2 has much more to it.

MIMIC:
=> infrared reciever and transmitter attached to it.
=> can recieve and hold up to 8 signals.
=> ability to "Mimic" signal it copies.

Dragonfly:
=> the core controller functionality.
=> could be used as a controller or a HID(Human Interface Device)
=> good for simple or retro games.
=> could be used as a controller for another DIY project.

Suite:
\*Underdevelopment
=> aims to achieve Wifi and Bluetooth manipulation such as jamming
=> functionality of espmarauder with additional features mentioned above

my purpose with this project is to build a toolbox capable of tasks 
that normal closed source and monitored devices are not .

ill explain the hardware as well.
=> 8 physical buttons , 2 touch capacitive buttons.
=> 550 mah 3.7v battery
=> tp4056 battery charging module
=> esp32 devkit V1
=> 0.96 inch I2C oled display driven by blazing fast U8G2 library.

on the top of that there are spare GPIO pins which may be used to add funtionality of:
=> NFC 
=> piezo buzzer
=> gps module
=> cellular connectivity 
=> radio connectivity
=> sd card modules etc
=> gpio expander

NOTE: this is going to be in development for a while , because it takes me time to learn about
all this stuff.
            Take Care.
                Mechanisium:D
