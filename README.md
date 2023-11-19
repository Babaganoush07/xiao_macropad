# Xiao Macropad
> A 3 key macropad, mostly just to Copy and Paste. But you do whatever you want to do.


## Table of Contents
* [Materials Needed](#materials-needed)
* [Software Needed](#software-needed)
* [Features](#features)
* [Setup](#setup)
* [Print Case](#case)
* [Progression](#old-designs)


## Materials needed
> Soldering Required

| Item | Link | Quantity | Price |
|:----:|:----:|:--------:| -----:|
| Seeduino Xiao | [Amazon](https://ringerkeys.com/products/peel-a-way-sockets) | 1 | $9.50 |
| Peel-A-Way Sockets | [ringerkeys.com](https://ringerkeys.com/products/peel-a-way-sockets) | 2 (Strips of 12) | $4.00 |
| Mechanical Switches | [Amazon](https://www.amazon.com/dp/B09J3FWGVQ?psc=1&ref=ppx_yo2ov_dt_b_product_details) | 1 (pack of 10) | $12.99 |
| Key Caps | [Amazon](https://www.amazon.com/dp/B0BM8N2ZFX?psc=1&ref=ppx_yo2ov_dt_b_product_details) | 1 (pack of 10) | $7.01 |
| OLED Screen (128x32) | [Amazon](https://www.amazon.com/gp/product/B0761LV1SD/ref=ox_sc_saved_image_3?smid=A1N6DLY3NQK2VM&psc=1) | 1 (pack of 2) | $7.99 |
| PCB | [JLCPCB](https://jlcpcb.com/) | 5 minimum | $5.00 |


## Software Needed
* Arduino
* Seeed SAMD Boards
  * `https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json`
  * Select the board: Tools -> Boards Manager and search `seeeduino xiao`. Select the `Seeed SAMD Boards`.
  * [Xiao Setup help](https://dronebotworkshop.com/seeeduino-xiao-intro/)
* #include
  * Arduino.h
  * HID-Project.h
  * ezButton.h
  * UG82lib.h


## Features
> Using HID-Project you can have whatever macros you want set to any of the keys. I used CTL-A, CTL-C, CTL-V.

> The screen displays what each button does (Because it's hard to remember 3 things).


## Setup
1. Order the PCBs using the [gerber file](https://github.com/Babaganoush07/xiao_macropad/blob/main/Gerber_PCB_xiao%20macropad_2023-02-11.zip).
     * It's a .zip file that you upload to JLCPCB and choose your parameters. Here's their [How to Order video](https://youtu.be/SGsfiHOE9Fk).
     * <img src="/photos/PCBorder.png" width="850" height="200" />
3. Solder the sockets to the PCB
     *  CannonKeys has [instructions](https://docs.cannonkeys.com/sockets/) for soldering the Peel-A-Way sockets. 
4. Solder pins to the Xiao
     * Instead of square headers on the Xiao use legs from resistors or diodes to fit into the sockets.
     * <img src="/photos/Seeeduino-XIAO-pinout-1.jpg" width="200" height="150" />
5. (Optional) Solder the OLED screen
     * The screen is optional if you want to avoid the headache of OLED burn in.
6. Solder on the switches
     * I didn't see a need to make them hot swapable, it's only 3 of them. And I don't have a way to design a plate mounted setup right now.
7. Add the key caps
8. Program the Xiao
     * macro_pad_V1.ino - **Doesn't** have the OLED programmed
     * macro_pad_V2.ino - **Has** the OLED programmed

## Case
*img
* Printer: Ender 3 pro
* Material: PLA
* Layer hight: 0.28
* Rafts: No
* Supports: No
* Infill: N/A

## Old Designs
| Version 1.1 | Version 1.2 |
| :---------: | :---------: |
| <img src="/photos/v1.1.jpg" width="250" height="200" /> | <img src="/photos/v1.2.jpg" width="200" height="200" /> |
| Version 2.1 | Version 2.2 |
| <img src="/photos/v2.1.jpg" width="200" height="250" /> | <img src="/photos/v2.2.jpg" width="200" height="200" /> |
