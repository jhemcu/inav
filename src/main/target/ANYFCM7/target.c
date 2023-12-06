/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

#define TIM_EN      TIMER_OUTPUT_ENABLED
#define TIM_EN_N    TIMER_OUTPUT_ENABLED | TIMER_OUTPUT_N_CHANNEL

timerHardware_t timerHardware[] = {
    // DEF_TIM(TIM12, CH1, PB14, TIM_USE_PWM | TIM_USE_PPM,   0, 0 ), // S1_IN
    // DEF_TIM(TIM12, CH2, PB15, TIM_USE_PWM,                 0, 0 ), // S2_IN
    // DEF_TIM(TIM8,  CH1, PC6,  TIM_USE_PWM,                 0, 0 ), // S3_IN DMA2_ST2 DMA2_ST2
    // DEF_TIM(TIM8,  CH2, PC7,  TIM_USE_PWM,                 0, 0 ), // S4_IN DMA2_ST3 DMA2_ST2
    // DEF_TIM(TIM8,  CH3, PC8,  TIM_USE_PWM,                 0, 0 ), // S5_IN DMA2_ST4 DMA2_ST2
    // DEF_TIM(TIM8,  CH4, PC9,  TIM_USE_PWM,                 0, 0 ), // S6_IN DMA2_ST7

    DEF_TIM(TIM4,  CH3,  PB8,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S10_OUT 1 DMA1_ST7
    DEF_TIM(TIM2,  CH3,  PA2,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S6_OUT  2 DMA1_ST1
    DEF_TIM(TIM4,  CH2,  PB7,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S5_OUT  3 DMA1_ST3
    DEF_TIM(TIM2,  CH4,  PA3,  TIM_USE_OUTPUT_AUTO,               0, 1 ), // S1_OUT  4 DMA1_ST7 DMA1_ST6
    DEF_TIM(TIM5,  CH2,  PA1,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S2_OUT DMA1_ST4
    DEF_TIM(TIM1,  CH2N, PB0,  TIM_USE_OUTPUT_AUTO,               0, 1 ), // S3_OUT DMA2_ST6 DMA2_ST2
    DEF_TIM(TIM3,  CH2,  PB5,  TIM_USE_OUTPUT_AUTO | TIM_USE_LED, 0, 0 ), // S4_OUT DMA1_ST5
    DEF_TIM(TIM5,  CH1,  PA0,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S7_OUT DMA1_ST2
    DEF_TIM(TIM1,  CH3N, PB1,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S8_OUT DMA2_ST6
    DEF_TIM(TIM3,  CH1,  PB4,  TIM_USE_OUTPUT_AUTO,               0, 0 ), // S9_OUT DMA1_ST4
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
