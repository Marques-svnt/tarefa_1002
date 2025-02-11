#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "display.h"
#include "defines.h"

void led_init()
{
    gpio_init(VERMELHO);
    gpio_init(AZUL);
    gpio_init(VERDE);
    gpio_set_dir(VERMELHO, GPIO_OUT);
    gpio_set_dir(AZUL, GPIO_OUT);
    gpio_set_dir(VERDE, GPIO_OUT);
}

void joystick_init()
{
    adc_init();
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);
    gpio_init(JOYSTICK_PB);
    gpio_set_dir(JOYSTICK_PB, GPIO_IN);
    gpio_pull_up(JOYSTICK_PB);
}

void init()
{
    stdio_init_all();
    initI2C();
    led_init();
    joystick_init();
}