#include <stdio.h>
#include "pico/stdlib.h"
#include "defines.h"
#include "display.h"
#include "init.h"
#include "interrupt.h"
#include "pwm_leds.h"

int main()
{
    // Função que chama todas as inicializações do projeto
    init();
    borda(true);
    display(60, 28); // Quadrado centralizado no display
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(JOYSTICK_PB, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    while (true)
    {
        leds_pwm();
        sleep_ms(10);
    }
}
