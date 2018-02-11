# LoRaWAN IoT Shield

The LoRaWAN IoT Shield is an sensor board for the mbed platform. It should also be compatible with Arduino, but is not tested.

Schematics can be downloaded [here](schematics.pdf)

## Sensors

The LoRaWAN IoT Shield supports the RFM95 and RN2483 LoRaWAN transceivers.

Other sensors available are:

* Temperature
* Humidity
* Air pressure
* GPS
* PIR motion detection
* ToF distance sensor
* Accelerometer
* Gyroscope
* Compass
* Ambient Light
* Microphone
* 5x Capacitive buttons
* 5x RGB leds
* Graphical display
* EEPROM
* Speaker

## Datasheets

To provide the listed sensors, the following hardware is used:

* [Bosh BME280](https://www.mouser.be/ds/2/621/BST-BME280_DS001-09-521021.pdf): temperature, humidity and air pressure
* [VL6180x](http://www.st.com/content/ccc/resource/technical/document/datasheet/c4/11/28/86/e6/26/44/b3/DM00112632.pdf/files/DM00112632.pdf/jcr:content/translations/en.DM00112632.pdf): ToF distance and ambient light
* [AMN31111](https://www.mouser.com/ds/2/315/bltn_eng_pir-1075997.pdf): PIR motion sensor
* [MPU9250](https://www.invensense.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf): Accelerometer, gyroscope and compass
* [24AA64T](http://ww1.microchip.com/downloads/en/DeviceDoc/21189T.pdf): EEPROM
* [AT42QT1070](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9596-AT42-QTouch-BSW-AT42QT1070_Datasheet.pdf): 5 Capacitive buttons
* [TLC59116](http://www.ti.com/lit/ds/symlink/tlc59116.pdf): 5 RGB Leds
* [MAX44009](https://datasheets.maximintegrated.com/en/ds/MAX44009.pdf): Ambient light sensor
* [C12832A](https://www.newhavendisplay.com/specs/NHD-C12832A1Z-FSW-FBW-3V3.pdf): Graphical LCD 128 x 32
* [MTK3339](https://cdn-shop.adafruit.com/datasheets/PMTK_A11.pdf): Adafruit Ultimate GPS 
* [Speaker](https://www.murata.com/~/media/webrenewal/support/library/catalog/products/sound/p37e.ashx): PKLCS1212E4001-R1
* [Microphone](https://www.mouser.com/ds/2/218/-531228.pdf): SPW2430HR5H-B

## Hardware

The hardware pcb design is available on Circuitmaker: 

https://circuitmaker.com/Projects/Details/Sille-Van-Landschoot-2/LoRaWAN-IoT-Shield
