/*
author: Mücahit KURTLAR
license: GNU GENERAL PUBLIC LICENSE Version 3
*/

#ifndef SR_74HC595_H
#define SR_74HC595_H

#include <math.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define CLOCK_DELAY_US 5
#define LATCH_DELAY_US 5

// Define pin enumeration
typedef enum {
    QA,
    QB,
    QC,
    QD,
    QE,
    QF,
    QG,
    QH
} sr_74hc595_pin_t;

// Define shift register structure
typedef struct {
    int clk_pin;
    int data_pin;
    int latch_pin;
    unsigned int pins_state;
} sr_74hc595_t;

/*! \brief Creates and returns a new shift register with given pin numbers
 *
 * \param clk_pin Clock pin
 * \param data_pin Data pin
 * \param latch_pin Latch pin
 */
sr_74hc595_t new_sr_74hc595(int clk_pin, int data_pin, int latch_pin) {
    sr_74hc595_t sr_74hc595;

    // Set pins
    sr_74hc595.clk_pin = clk_pin;
    sr_74hc595.data_pin = data_pin;
    sr_74hc595.latch_pin = latch_pin;

    // Set default pins state
    sr_74hc595.pins_state = 0b00000000;

    // Return the created shift register
    return sr_74hc595;
}

/*! \brief Creates clock signal
 *
 * \param sr_74hc595 Shift register pointer
*/
static void clock_signal(sr_74hc595_t* sr_74hc595) {
    gpio_put(sr_74hc595->clk_pin, 1);
    sleep_us(CLOCK_DELAY_US);
    gpio_put(sr_74hc595->clk_pin, 0);
    sleep_us(CLOCK_DELAY_US);
}

/*! \brief Enables latch
 *
 * \param sr_74hc595 Shift register pointer
*/
static void latch_enable(sr_74hc595_t* sr_74hc595) {
    gpio_put(sr_74hc595->latch_pin, 1);
    sleep_us(LATCH_DELAY_US);
    gpio_put(sr_74hc595->latch_pin, 0);
}

/*! \brief Sends data to shift register
 *
 * \param sr_74hc595 Shift register pointer
 * \param data_out Data to send
*/
static void send_data(sr_74hc595_t* sr_74hc595, unsigned int data_out) {
    unsigned hold;
    // Send data as serail...
    for (int i = 0; i < 8; i++) {
        gpio_put(sr_74hc595->data_pin, (data_out >> i) & (0x01));
        clock_signal(sr_74hc595);
    }
    // ... and enable latch
    latch_enable(sr_74hc595);
}

/*! \brief Set selected pin digital high or digital low
 *
 * \param sr_74hc595 Shift register pointer
 * \param pin Pin number (0-7) or (QA-QH)
 * \param value 1 for high, 0 for low
 */
static void sr_74hc595_put(sr_74hc595_t* sr_74hc595, sr_74hc595_pin_t pin, bool value) {
    if (value) {
        // Use OR operator to set pin high
        sr_74hc595->pins_state |= (unsigned int)pow(2, (7 - pin));
    } else {
        // Take complement of pin_bin and use AND operator to set pin low
        sr_74hc595->pins_state &= ~(unsigned int)pow(2, (7 - pin));
    }
    // Send pin data to 74HC595
    send_data(sr_74hc595, sr_74hc595->pins_state);
}

#endif
