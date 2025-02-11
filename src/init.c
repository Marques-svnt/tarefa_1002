#include <stdio.h>
#include "pico/stdlib.h"
#include "display.h"

void init(){
    stdio_init_all();
    initI2C();
}