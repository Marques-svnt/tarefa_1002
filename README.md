# Projeto: Controle de LEDs PWM e Joystick com Raspberry Pi Pico W

## Descrição
Este projeto utiliza a placa BitDogLab baseada no RP2040 para controlar LEDs RGB via PWM usando valores analógicos de um joystick, exibir um quadrado móvel no display SSD1306 e gerenciar botões com interrupções e debounce.

---

## Funcionalidades

### Configuração do PWM
- Controle de intensidade dos LEDs vermelho e azul via PWM com valores do joystick.

### Movimento do Quadrado no Display
- Quadrado 8x8 pixels movido proporcionalmente ao joystick.


### Interrupções e Debounce
- **Botão A:** Ativa/desativa LEDs PWM.
- **Joystick PB:** Alterna LED verde e estilo da borda do display.

---

## Requisitos

- Placa BitDogLab com RP2040
- Joystick analógico
- LEDs RGB (GPIOs 11, 12, 13)
- Display SSD1306 via I2C (GPIO 14 e 15)

---

## Configuração

### Mapeamento de GPIOs
| Componente | GPIO |
|------------|------|
| LED Vermelho | GPIO 11 |
| LED Azul | GPIO 13 |
| LED Verde | GPIO 12 |
| Joystick X/Y | GPIO 26/27 |
| Joystick PB | GPIO 22 |
| Botão A | GPIO 5 |
| Display SSD1306 | GPIO 14/15 |

---

## Compilação e Execução
1. Configure o Pico SDK no VS Code.
2. Compile com a extensão **Raspberry Pi Pico Project**.
3. Copie o `main.uf2` para a placa em modo boot.

---

## Emulação com Wokwi
1. Instale o **Wokwi for VS Code**.
2. Configure e execute a simulação.

---

## Demonstração no YouTube
- [Demonstração do Projeto](https://www.youtube.com/watch?v=ixlabSdBb7g)

---

## Colaboradores
- [Gabriel Marques](https://github.com/Marques-svnt)

---

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).

