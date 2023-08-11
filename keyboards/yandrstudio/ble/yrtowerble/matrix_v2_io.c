/* Copyright 2021 JasonRen(biu)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "matrix.h"
#include "wait.h"
#include "quantum.h"
#include "gpio.h"


#   ifdef USE_BOTH_595_AND_GPIO
const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#   endif
const pin_t row_pin = MATRIX_ROW_PIN;
const uint8_t mask_of_each_595[MATRIX_ROWS][MATRIX_COLS][2] = MATRIX_OF_74HC595;


const uint8_t sr_zero = SR_74HC595_ZERO_ONEP;

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { setPinInputHigh(pin); }
}


static void shift_out_single(uint8_t value) {
    for (uint8_t i = 0; i < 8; i++) {
        writePinLow(SPI_SCK_PIN_OF_595);
        if ((value>>i)&1) {
            writePinHigh(SPI_MOSI_PIN_OF_595);
        } else {
            writePinLow(SPI_MOSI_PIN_OF_595);
        }
        writePinHigh(SPI_SCK_PIN_OF_595);
    }
}



// matrix code
static void select_col(uint8_t f_row, uint8_t f_col, uint8_t col) {
    uint8_t i = 0, j = 0, k = 0;
#   ifdef USE_BOTH_595_AND_GPIO
    if (col_pins[col] != NO_PIN) {
        writePinHigh(col_pins[col]);
        return;
    }
#   endif

    writePinLow(SPI_74HC595_CS);
    for (i = 0; i < NUM_OF_74HC595; ++i) {
        if (i == mask_of_each_595[f_row][f_col][0]) {
            shift_out_single(mask_of_each_595[f_row][f_col][1]);
        } else {
            shift_out_single(SR_74HC595_ZERO_ONEP);
        }
    }
    writePinHigh(SPI_74HC595_CS);
}

static void unselect_cols(void) {
    uint8_t i = 0;
#   ifdef USE_BOTH_595_AND_GPIO
    for (i = 0; i < MATRIX_COLS; ++i) {
        if (col_pins[i] != NO_PIN) {
            writePinLow(col_pins[i]);
        }
    }
#   endif

    writePinLow(SPI_74HC595_CS);
    for (i = 0; i < NUM_OF_74HC595; ++i) {
        shift_out_single(sr_zero);
    }
    writePinHigh(SPI_74HC595_CS);
}

static void unselect_rows(void) {
    setPinInputLow(row_pin);
}

static void init_pins(void) {
    setPinOutput(SPI_SCK_PIN_OF_595);
    setPinOutput(SPI_MOSI_PIN_OF_595);
    setPinOutput(SPI_74HC595_CS);
    writePinHigh(SPI_SCK_PIN_OF_595);
    writePinHigh(SPI_MOSI_PIN_OF_595);
    writePinHigh(SPI_74HC595_CS);
#   ifdef USE_BOTH_595_AND_GPIO
    uint8_t i = 0;
    for (i = 0; i < MATRIX_COLS; ++i) {
        if (col_pins[i] != NO_PIN) {
            setPinOutput(col_pins[i]);
        }
    }
#   endif
    unselect_rows();
    unselect_cols();
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;
    uint8_t f_row = col / N_COL_AS_ONE_ROW;
    uint8_t f_col = col % N_COL_AS_ONE_ROW;

    // Select col
    select_col(f_row, f_col, current_col);
    matrix_output_select_delay();

    // Store last value of row prior to reading
    matrix_row_t last_row_value    = current_matrix[f_row];
    matrix_row_t current_row_value = last_row_value;

    // Check row pin state
    if (readPin(row_pin) == 1) {
        // Pin HI, set col bit
        current_row_value |= (MATRIX_ROW_SHIFTER << f_col);
    } else {
        // Pin LO, clear col bit
        current_row_value &= ~(MATRIX_ROW_SHIFTER << f_col);
    }
    // Determine if the matrix changed state
    if ((last_row_value != current_row_value)) {
        matrix_changed |= true;
        current_matrix[f_row] = current_row_value;
    }

    // Unselect col
    unselect_cols();
    matrix_output_unselect_delay(current_col, matrix_changed);  // wait for all Row signals to go HIGH


    return matrix_changed;
}



void matrix_init_custom(void) {
    // initialize key pins
    init_pins();
}

uint8_t matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set col, read rows
    for (uint8_t current_col = 0; current_col < MATRIX_COLS*MATRIX_ROWS; current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return (uint8_t)changed;
}
