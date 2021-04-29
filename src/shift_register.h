/*
author: Mücahit KURTLAR
license
*/

#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

enum shreg_pin{
    QA,
    QB,
    QC,
    QD,
    QE,
    QF,
    QG,
    QH
};
typedef enum shreg_pin shreg_pin;
//define pin enumeration

struct shreg {
    int clk_pin;
    int data_pin;
    int latch_pin;
    unsigned int pin;
};
typedef struct shreg shreg;
//define shift register structure

shreg * new_shreg(int c_pin, int d_pin, int l_pin);
//takes pin numbers as parameters and returns shift register pointer
void clock_signal(shreg *reg);
//creates clock signal
void latch_enable(shreg *reg);
//enables latch pin
void send_data(shreg *reg, unsigned int data_out);
//sends serial data to 74HC595
void shreg_put(shreg *reg, shreg_pin pin, bool value);
//sets selected pin digital high or digital low

#endif