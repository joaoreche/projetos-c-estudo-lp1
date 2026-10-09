#include <stdio.h>
#include <stdlib.h> // Para rand(), srand(), system()
#include <string.h> // Para strcmp(), strlen(), etc.
#include <time.h>   // Para time()
#ifdef _WIN32
#include <windows.h> // Para Sleep() no Windows
#else
#include <unistd.h>  // Para sleep() no Linux/Unix
#endif

// --- Funções Auxiliares (Módulos) ---

/**
 * @brief Pausa a execução do programa por um número de segundos.
 *        Funciona tanto em Windows quanto em Linux/macOS.
 */
void pausar_segundos(int segundos) {
    #ifdef _WIN32
        Sleep(segundos * 1000); // Sleep recebe milissegundos
    #else
        sleep(segundos);        // sleep recebe segundos
    #endif
}

/**
 * @brief Limpa a tela do console.
 *        Funciona tanto em Windows quanto em Linux/macOS.
 */
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Adiciona um novo dígito aleatório ao final de uma string.
 *        Usa notação de ponteiro para encontrar o final da string.
 * @param sequencia Ponteiro para a string que será modificada.
 */
void adicionar_digito_aleatorio(char *sequencia) {
    // A dica do exercício sugere rand() % 9, que gera de 0 a 8.
    // Para gerar de 0 a 9, o correto é rand() % 10. Vamos seguir a lógica de 0 a 9.
    int novo_digito_num = rand() % 10; 
    char novo_digito_char = novo_digito_num + '0'; // Converte int para char

    // Encontra o final da string usando um ponteiro
    char *final_string = sequencia;
    while (*final_string != '\0') {
        final_string++;
    }

    // Adiciona o novo dígito e o terminador nulo
    *final_string = novo_digito_char;
    *(final_string + 1) = '\0';
}

/**
 * @brief Executa o turno de um jogador: mostra a sequência, pede a resposta e verifica.
 * @param numero_jogador O número do jogador (1 ou 2).
 * @param sequencia_correta A sequência que deve ser memorizada.
 * @return int Retorna 1 se o jogador acertou, 0 se errou.
 */
int turno_do_jogador(int numero_jogador, const char *sequencia_correta) {
    char resposta_jogador[100]; // Buffer para a resposta

    limpar_tela();
    printf("Jogador %d, prepare-se para memorizar...\n", numero_jogador);
    pausar_segundos(2);

    printf("Memorize a sequencia: %s\n", sequencia_correta);
    pausar_segundos(5); // Tempo para memorizar

    limpar_tela();
    printf("Jogador %d, digite a sequencia que voce memorizou: ", numero_jogador);
    scanf("%s", resposta_jogador);

    // Compara a resposta com a sequência correta
    if (strcmp(resposta_jogador, sequencia_correta) == 0) {
        printf("Correto!\n");
        pausar_segundos(2);
        return 1; // Acertou
    } else {
        printf("Incorreto! A sequencia era: %s\n", sequencia_correta);
        pausar_segundos(3);
        return 0; // Errou
    }
}

// --- Função Principal ---

int main() {
    // Inicializa o gerador de números aleatórios com uma semente baseada no tempo
    srand(time(NULL));

    char sequencia[100] = ""; // Armazena a sequência de números, começa vazia
    int rodada = 1;
    int pontos_j1 = 0;
    int pontos_j2 = 0;

    printf("Bem-vindo ao Jogo de Memorizacao!\n");
    printf("Dois jogadores serao desafiados a memorizar uma sequencia crescente de numeros.\n");
    pausar_segundos(4);

    while (1) { // Loop infinito para as rodadas
        limpar_tela();
        printf("--- Rodada %d ---\n", rodada);
        pausar_segundos(2);

        // Adiciona um novo dígito à sequência
        adicionar_digito_aleatorio(sequencia);

        // Turno do Jogador 1
        if (!turno_do_jogador(1, sequencia)) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Jogador 1 errou!\n");
            printf("O JOGADOR 2 VENCEU!\n");
            printf("Total de digitos memorizados pelo vencedor: %d\n", pontos_j2);
            break; // Sai do loop e termina o jogo
        }
        pontos_j1++;

        // Turno do Jogador 2
        if (!turno_do_jogador(2, sequencia)) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Jogador 2 errou!\n");
            printf("O JOGADOR 1 VENCEU!\n");
            printf("Total de digitos memorizados pelo vencedor: %d\n", pontos_j1);
            break; // Sai do loop e termina o jogo
        }
        pontos_j2++;

        rodada++;
    }

    return 0;
}