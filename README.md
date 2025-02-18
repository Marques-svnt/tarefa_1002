Projeto: Controle de LEDs PWM e Joystick com Raspberry Pi Pico W

Descrição

Este projeto utiliza a placa BitDogLab baseada no RP2040 para controlar LEDs RGB via PWM usando os valores analógicos de um joystick, exibir um quadrado móvel no display SSD1306 proporcionalmente ao movimento do joystick e gerenciar o acionamento de botões com interrupções e debounce.

Funcionalidades

Controle de LEDs por PWM

O LED Azul tem seu brilho ajustado conforme o eixo Y do joystick.

O LED Vermelho tem seu brilho ajustado conforme o eixo X do joystick.

Os LEDs permanecem apagados quando o joystick está na posição central.

Movimentação do Joystick

Exibição de um quadrado 8x8 pixels no display SSD1306, movido proporcionalmente aos valores analógicos lidos.

Interrupções e Debounce

Botão A: Ativa/desativa os LEDs PWM.

Botão do Joystick (PB): Alterna o estado do LED verde e modifica o estilo da borda do display.

Implementação de debounce via software para evitar leituras incorretas.

Requisitos

Placa BitDogLab com RP2040

Joystick analógico

LEDs RGB (GPIOs 11, 12, 13)

Botões (Joystick PB - GPIO 22, Botão A - GPIO 5)

Display SSD1306 via I2C (GPIO 14 e 15)

Pico SDK configurado no VS Code

Simulador Wokwi integrado ao VS Code

Configuração

Mapeamento de GPIOs

Componente

GPIO

LED Vermelho

GPIO 11

LED Azul

GPIO 13

LED Verde

GPIO 12

Joystick X/Y

ADC 0/1 (GPIO 26/27)

Joystick PB

GPIO 22

Botão A

GPIO 5

Display SSD1306

GPIO 14/15 (I2C)

Compilação e Execução

Configure o SDK do RP2040 no seu ambiente.

Compile o programa no VS Code.

Copie o arquivo main.uf2 para a placa BitDogLab em modo boot.

Emulação com Wokwi

Instale a extensão Wokwi for VS Code.

Configure e execute a simulação.

Demonstração no YouTube

Vídeo Demonstrativo do Projeto

Colaboradores

Gabriel Marques

Licença

Este projeto está licenciado sob a MIT License.

