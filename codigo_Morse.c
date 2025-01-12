#include "pico/stdlib.h"

// Definições de pinos e tempos
#define PINO_LED_Verde 11       // Pino conectado ao LED
#define DURACAO_PONTO 200       // 0,2 segundos para o ponto (.)
#define DURACAO_TRACO 800       // 0,8 segundos para o traço (_)
#define INTERVALO_ELEMENTOS 125 // Intervalo entre pontos e traços dentro de uma letra (0,125 segundos)
#define INTERVALO_LETRAS 250    // Intervalo entre letras (0,25 segundos)
#define PAUSA_CICLO 3000        // Intervalo entre ciclos da mensagem (3 segundos)

// Função que emite a mensagem "SOS" em código Morse
void emitir_mensagem_SOS()
{
    // Enviar 3 pontos para formar a letra 'S'
    for (int i = 0; i < 3; i++)
    {
        gpio_put(PINO_LED_Verde, true);      // Acender o LED
        
        sleep_ms(DURACAO_PONTO);       // Manter aceso por DURACAO_PONTO

        gpio_put(PINO_LED_Verde, false);     // Apagar o LED

        sleep_ms(INTERVALO_ELEMENTOS); // Intervalo entre os pontos
    }
    sleep_ms(INTERVALO_LETRAS); // Pausa entre a letra 'S' e 'O'

    // Enviar 3 traços para formar a letra 'O'
    for (int i = 0; i < 3; i++)
    {
        gpio_put(PINO_LED_Verde, true);
        sleep_ms(DURACAO_TRACO);
        gpio_put(PINO_LED_Verde, false);
        sleep_ms(INTERVALO_ELEMENTOS);
    }
    sleep_ms(INTERVALO_LETRAS); // Pausa entre a letra 'O' e 'S'

    // Enviar 3 pontos novamente para formar a letra 'S'
    for (int i = 0; i < 3; i++)
    {
        gpio_put(PINO_LED_Verde, true);
        sleep_ms(DURACAO_PONTO);
        gpio_put(PINO_LED_Verde, false);
        sleep_ms(INTERVALO_ELEMENTOS);
    }
}

// Função principal
int main()
{
    // Inicializar o pino do LED
    gpio_init(PINO_LED_Verde);
    gpio_set_dir(PINO_LED_Verde, GPIO_OUT); // Configurar o pino como saída
    

    // Loop infinito para enviar repetidamente a mensagem "SOS"
    while (true)
    {   
        // Chamando a função aonde vai ter os paramentro para criar o SOS com as LEDs
        emitir_mensagem_SOS(); // Enviar a mensagem "SOS" em código Morse
        sleep_ms(PAUSA_CICLO); // Pausa antes de repetir o ciclo
    }
}
