#include <stdio.h>
#include "pico/stdlib.h"



int main()
{
    stdio_init_all();
    initI2C();

    display(10,20);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
