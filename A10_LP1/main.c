/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

void processar_caso(char digito_falho, char numero_str[]) {
    int i = 0; // Índice para ler a string original (ponteiro de leitura)
    int j = 0; // Índice para escrever na string modificada (ponteiro de escrita)

    // 1. Remove o dígito falho, modificando a string no próprio local ("in-place").
    // Percorre a string lendo com 'i' e escrevendo com 'j'.
    while (numero_str[i] != '\0') {
        // Se o caractere atual NÃO for o dígito falho...
        if (numero_str[i] != digito_falho) {
            // ...copia ele para a posição de escrita.
            numero_str[j] = numero_str[i];
            j++; // Avança a posição de escrita.
        }
        i++; // Sempre avança a posição de leitura.
    }
    // Finaliza a nova string (mais curta) com o caractere nulo.
    numero_str[j] = '\0';

    // 2. Encontra o primeiro dígito significativo para evitar zeros à esquerda (ex: "00123").
    // A variável 'ponteiro_inicio' vai apontar para o começo do número a ser impresso.
    char *ponteiro_inicio = numero_str;
    while (*ponteiro_inicio == '0' && *(ponteiro_inicio + 1) != '\0') {
        ponteiro_inicio++;
    }

    // 3. Imprime o valor numérico resultante.
    // Se a string ficou vazia ou só tem zeros, o ponteiro_inicio apontará para '0' ou '\0'.
    // Se a string resultante for "" (vazia) ou "0" ou "00", o valor numérico é 0.
    if (strlen(ponteiro_inicio) == 0) {
        printf("0\n");
    } else {
        // Imprime a string a partir do primeiro dígito significativo.
        printf("%s\n", ponteiro_inicio);
    }
}

int main() {
    int d; // Para armazenar o dígito falho (1 a 9)
    char n_str[102]; // Vetor para armazenar o número como string (100 dígitos + '\0' + margem)

    /*printf("Digite o digito falho: ");
    scanf("%d", &d);
    printf("Digite a string: ");
    scanf("%[^\n]", n_str);*/
    // O loop continua enquanto scanf conseguir ler dois valores (dígito e string).
    // A condição de parada (0 0) é verificada dentro do loop.
    while (scanf("%d %s", &d, n_str) == 2) {
        
        // Condição de parada do problema
        if (d == 0 && strcmp(n_str, "0") == 0) {
            break;
        }

        // Converte o dígito 'd' (int) para um caractere para facilitar a comparação.
        // Se d=5, digito_char se torna '5'.
        char digito_falho_char = d + '0';

        // Chama a função para processar e imprimir o resultado para este caso de teste.
        processar_caso(digito_falho_char, n_str);
    }

    return 0;
}