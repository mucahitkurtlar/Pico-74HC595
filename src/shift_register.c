#include <stdlib.h>
#include "pico/stdlib.h"
#include "shift_register.h"

shreg * new_shreg(int c_pin, int d_pin, int l_pin) {
    shreg *new_sh = (shreg *) malloc(sizeof (shreg));
    //allocate memory for new shift register object
    new_sh->clk_pin = c_pin;
    new_sh->data_pin = d_pin;
    new_sh->latch_pin = l_pin;
    //set pins
    new_sh->pin = 0b00000000;
    //set default pins state
    return new_sh;
    //return the shift register
}

void clock_signal(shreg *reg) {
    gpio_put(reg->clk_pin, 1);
    sleep_us(500);
    gpio_put(reg->clk_pin, 0);
    sleep_us(500);
}

void latch_enable(shreg *reg) {
    gpio_put(reg->latch_pin, 1);
    sleep_us(500);
    gpio_put(reg->latch_pin, 0);
}

void send_data(shreg *reg, unsigned int data_out) {
    unsigned hold;
    for (int i = 0; i < 8 ; i++){
        gpio_put(reg->data_pin, (data_out >> i) & (0x01));
        clock_signal(reg);
    }
    //send data as serail...
    latch_enable(reg);
    //...and enable latch
}

void shreg_put(shreg *reg, shreg_pin pin, bool value) {
    unsigned int pin_b;
    switch (pin) {
    case QA:
        pin_b = 0b10000000;
        break;
    case QB:
        pin_b = 0b01000000;
        break;
    case QC:
        pin_b = 0b00100000;
        break;
    case QD:
        pin_b = 0b00010000;
        break;
    case QE:
        pin_b = 0b00001000;
        break;
    case QF:
        pin_b = 0b00000100;
        break;
    case QG:
        pin_b = 0b00000010;
        break;
    case QH:
        pin_b = 0b00000001;
        break;
    
    default:
        pin_b = 0b00000000;
        break;
    }
    //select enums binary equivalent
    if (value) {
        reg->pin = reg->pin | pin_b;
        //if pin desired as high use OR
    } else {
        reg->pin = reg->pin & ~pin_b;
        //if pin desired as low take complement of pin_b and use AND
    }
        send_data(reg, reg->pin);
}