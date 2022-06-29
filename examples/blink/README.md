# Blinky 74HC595 (Pi Pico)

## Build

```shell
$ git clone https://github.com/mucahitkurtlar/Pico-74HC595.git
$ mkdir -p Pico-74HC595/examples/blink/build
$ cd Pico-74HC595/examples/blink/build
$ cmake ..
$ make -j4
```

## Upload

```shell
$ cp shift_register_74hc595.uf2 /run/media/$USER/RPI-RP2
```
## Pinout

### 74HC595 shift register diagram
```
    ___   ___
QB  |  |_|  |   VCC
QC  |       |   QA
QD  |       |   SER
QE  |       |   OE
QF  |       |   RCLK
QG  |       |   SRCLK
QH  |       |   SRCLR
GND |       |   QH'
    ---------
```
</br>

### Pin connections
```
74HC595     pico
-------     ----
VCC         3.3V
SER         GP12
OE          GND
RCLK        GP10
SRCLK       GP11
SRCLR       3.3V

```