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
SRCLR       3.3V


author: Mücahit KURTLAR
license: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include "pico/stdlib.h"
#include "../../src/shift_register_74hc595.h"

// Define shift register pins
#define CLK_PIN 11
#define DATA_PIN 12
#define LATCH_PIN 10

int main() {
    // Set clk pin as output
    gpio_init(CLK_PIN);
    gpio_set_dir(CLK_PIN, GPIO_OUT);
    
    // Set data pin as output
    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);

    // Set latch pin as output
    gpio_init(LATCH_PIN);
    gpio_set_dir(LATCH_PIN, GPIO_OUT);

    // Create new shift register
    struct shift_register_74hc595_t *myreg = new_shreg_74hc595(CLK_PIN, DATA_PIN, LATCH_PIN);
    
    while (1) {
        for (size_t qi = QA; qi <= QH; qi++) {
            shreg_74hc595_put(myreg, qi, 1);
            sleep_ms(500);
        }
        for (size_t qi = QA; qi <= QH; qi++) {
            shreg_74hc595_put(myreg, qi, 0);
            sleep_ms(500);
        }
    }
}