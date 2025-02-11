#include <stdio.h>
#include "pico/stdlib.h"
#include "display.h"
#include "init.h"



int main()
{
    // Função que chama todas as inicializações do projeto
    init();

    display(60,28); // Quadrado centralizado no display

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
