#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "defines.h"
#include "interrupt.h"

extern bool led_estado;

uint pwm_init_gpio(uint gpio, uint wrap)
{
    gpio_set_function(gpio, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_wrap(slice_num, wrap);

    pwm_set_enabled(slice_num, true);
    return slice_num;
}

void pwm_slice_init()
{
    uint pwm_wrap = 4096;
    uint pwm_slice_X = pwm_init_gpio(JOYSTICK_X_PIN, pwm_wrap);
    uint pwm_slice_Y = pwm_init_gpio(JOYSTICK_Y_PIN, pwm_wrap);

    // Inicializa PWM para os LEDs
    uint pwm_slice_vermelho = pwm_init_gpio(VERMELHO, pwm_wrap);
    uint pwm_slice_azul = pwm_init_gpio(AZUL, pwm_wrap);
}

void leds_pwm()
{
    if (led_estado)
    {
        adc_select_input(0);
        uint16_t vrx_value = adc_read();
        adc_select_input(1);
        uint16_t vry_value = adc_read();

        pwm_set_gpio_level(VERMELHO, vrx_value);
        pwm_set_gpio_level(AZUL, vry_value);
    } else{
        pwm_set_gpio_level(VERMELHO, 0);
        pwm_set_gpio_level(AZUL, 0);
    }
}