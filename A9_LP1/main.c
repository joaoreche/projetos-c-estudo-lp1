#include <stdio.h>

/**
 * @brief Verifica se um número inteiro tem dígitos repetidos.
 *        Usa a sugestão de converter para string e notação de ponteiro.
 * 
 * @param numero O número a ser verificado.
 */
int tem_digitos_unicos(int numero) {
    char numero_str[5]; // Buffer para a string. B <= 1000, então 4 dígitos + '\0' é o máximo.
    
    // Converte o número inteiro para uma string.
    sprintf(numero_str, "%d", numero);

    // Array para marcar os dígitos que já vimos.
    // Índice 0 para o dígito '0', índice 1 para '1', etc.
    // Inicializamos todos com 0 (indicando que não vimos nenhum dígito ainda).
    int digitos_vistos[10] = {0};

    // Ponteiro 'p' que aponta para o início da string do número.
    char *p = numero_str;

    // Percorre a string usando o ponteiro 'p' até encontrar o final ('\0').
    while (*p != '\0') {
        // Converte o caractere do dígito (ex: '5') para um inteiro (ex: 5).
        int digito_atual = *p - '0';

        // Verifica no nosso array se já vimos esse dígito.
        if (digitos_vistos[digito_atual] == 1) {
            return 0; // Se sim, encontramos um dígito repetido. Retorna falso.
        }

        // Se não vimos, marcamos como visto para futuras verificações.
        digitos_vistos[digito_atual] = 1;

        // Avança o ponteiro para o próximo caractere.
        p++;
    }

    // Se o laço terminar sem encontrar repetições, todos os dígitos são únicos.
    return 1; // Retorna verdadeiro.
}

/**
 * @brief Função principal. Lê os intervalos e imprime a contagem.
 */
int main() {
    int a, b;

    // O laço continua enquanto scanf conseguir ler dois inteiros com sucesso.
    // Esta é uma forma comum de processar múltiplos casos de teste.
    while (scanf("%d %d", &a, &b) == 2) {
        int contador = 0;

        // Itera por todos os números no intervalo [a, b], inclusive.
        for (int i = a; i <= b; i++) {
            // Se o número 'i' tiver dígitos únicos...
            if (tem_digitos_unicos(i)) {
                // ...incrementa o contador.
                contador++;
            }
        }
        // Imprime o resultado final para este caso de teste.
        printf("%d\n", contador);
    }

    return 0;
}