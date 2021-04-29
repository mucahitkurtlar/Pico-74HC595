/*
74HC595 test code. Tests QA, QB, QC, QD, QE, QF, QG and QH outs with custom library written by Mücahit KURTLAR.
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


74HC595     pico
-------     ----
VCC         3.3V
SER         GP12
OE          GND
RCLK        GP10
SRCLK       GP11
CRCLR       3.3V


author: Mücahit KURTLAR
*/

#include "pico/stdlib.h"
#include "../../src/shift_register.h"

int main() {
    int latch_pin = 10;
    int clk_pin = 11;
    int data_pin = 12;

    gpio_init(latch_pin);
    gpio_set_dir(latch_pin, GPIO_OUT);
    gpio_init(clk_pin);
    gpio_set_dir(clk_pin, GPIO_OUT);
    gpio_init(data_pin);
    gpio_set_dir(data_pin, GPIO_OUT);

    shreg *myreg = new_shreg(clk_pin, data_pin, latch_pin);
    
    while (1) {

        shreg_put(myreg, QA, 1);
        sleep_ms(500);
        shreg_put(myreg, QB, 1);
        sleep_ms(500);
        shreg_put(myreg, QC, 1);
        sleep_ms(500);
        shreg_put(myreg, QD, 1);
        sleep_ms(500);
        shreg_put(myreg, QE, 1);
        sleep_ms(500);
        shreg_put(myreg, QF, 1);
        sleep_ms(500);
        shreg_put(myreg, QG, 1);
        sleep_ms(500);
        shreg_put(myreg, QH, 1);
        sleep_ms(500);
        
        shreg_put(myreg, QA, 0);
        sleep_ms(500);
        shreg_put(myreg, QB, 0);
        sleep_ms(500);
        shreg_put(myreg, QC, 0);
        sleep_ms(500);
        shreg_put(myreg, QD, 0);
        sleep_ms(500);
        shreg_put(myreg, QE, 0);
        sleep_ms(500);
        shreg_put(myreg, QF, 0);
        sleep_ms(500);
        shreg_put(myreg, QG, 0);
        sleep_ms(500);
        shreg_put(myreg, QH, 0);
        sleep_ms(500);

    }
}