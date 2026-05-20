# Kontroller-mk2
Second iteration of the legacy Kontroller , but more than just a controller.

<img width="1600" height="1200" alt="1" src="https://github.com/user-attachments/assets/1e8acda2-c56d-4060-95c7-b7abf8ef9ab8" />



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
<img width="1600" height="1200" alt="2" src="https://github.com/user-attachments/assets/a02e3a0e-1154-4dab-a00a-baecea6ace0c" />



MIMIC:
=> infrared reciever and transmitter attached to it.
=> can recieve and hold up to 8 signals.
=> ability to "Mimic" signal it copies.

Dragonfly:
=> the core controller functionality.
=> could be used as a controller or a HID(Human Interface Device)
=> good for simple or retro games.
=> could be used as a controller for another DIY project.



https://github.com/user-attachments/assets/d67dd8dd-a5d6-4cb3-bafc-7bd56d0bb157



Suite:
\*Underdevelopment
=> aims to achieve Wifi and Bluetooth manipulation such as jamming
=> functionality of espmarauder with additional features mentioned above
<img width="1600" height="1200" alt="3" src="https://github.com/user-attachments/assets/6c7ea716-0500-4057-8d84-b8c99f4d733f" />

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

<img width="727" height="508" alt="4" src="https://github.com/user-attachments/assets/6a74b6ca-e4fa-4a82-b54a-9e6591ee2942" />


NOTE: this is going to be in development for a while , because it takes me time to learn about
all this stuff.
            Take Care.
                Mechanisium:D
