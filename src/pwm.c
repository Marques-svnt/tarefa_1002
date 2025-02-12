#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "defines.h"
#include "interrupt.h"
#include "init.h"

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
    // Inicializa PWM para os LEDs
    uint pwm_slice_vermelho = pwm_init_gpio(VERMELHO, pwm_wrap);
    uint pwm_slice_azul = pwm_init_gpio(AZUL, pwm_wrap);
}

void leds_pwm()
{

    if (led_estado)
    {
        adc_select_input(0);
        sleep_us(5); // Pequeno delay para estabilidade
        uint16_t vrx_value = adc_read();
        adc_select_input(1);
        sleep_us(5); // Pequeno delay para estabilidade
        uint16_t vry_value = adc_read();

        printf("VRX: %u, VRY: %u\n", vrx_value, vry_value);

        if (vrx_value >= 1500 && vrx_value <= 2500) 
        {
            pwm_set_gpio_level(VERMELHO, 0);
        }
        else if (vrx_value > 2500) 
        {
            pwm_set_gpio_level(VERMELHO, vrx_value);
        }
        else if (vrx_value < 1500)
        {
            int i = 4095 - vrx_value;
            pwm_set_gpio_level(VERMELHO, (vrx_value + i));
        }

        if (vry_value >= 1500 && vry_value <= 2500) 
        {
            pwm_set_gpio_level(AZUL, 0);
        }
        else if (vry_value > 2500) 
        {
            pwm_set_gpio_level(AZUL, vry_value);
        }
        else if (vry_value < 1500)
        {
            int j = 4095 - vry_value;
            pwm_set_gpio_level(AZUL, (vry_value + j));
        }
    }
    else
    {
        pwm_set_gpio_level(VERMELHO, 0);
        pwm_set_gpio_level(AZUL, 0);
    }
}