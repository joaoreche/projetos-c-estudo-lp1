#include <stdio.h>

/**
 * @brief Calcula o N-ésimo número triangular de forma recursiva.
 *
 * @param n O índice do número triangular a ser calculado.
 * @return O valor do n-ésimo número triangular.
 */
int numero_triangular(int n) {
    // Caso Base: Se n for 0 ou 1, o valor é o próprio n.
    if (n <= 1) {
        return n;
    }
    // Passo Recursivo: T(n) = n + T(n-1)
    else {
        return n + numero_triangular(n - 1);
    }
}

/**
 * @brief Imprime uma linha com 'k' pontos de forma recursiva.
 *
 * @param k A quantidade de pontos a serem impressos.
 */
void imprimir_pontos(int k) {
    // Caso Base: Se não há mais pontos para imprimir, não faz nada.
    if (k <= 0) {
        return;
    }
    // Passo Recursivo: Imprime um ponto e chama a si mesma para o resto.
    printf(". ");
    imprimir_pontos(k - 1);
}

/**
 * @brief Imprime o triângulo de pontos de base 'n' de forma recursiva.
 *
 * @param n A base do triângulo (número de linhas).
 */
void imprimir_triangulo(int n) {
    // Caso Base: Se o número de linhas for 0, não faz nada.
    if (n <= 0) {
        return;
    }
    // Passo Recursivo: Imprime o triângulo menor primeiro.
    imprimir_triangulo(n - 1);

    // Depois de imprimir o triângulo menor, imprime a linha atual.
    imprimir_pontos(n);
    printf("\n"); // Pula para a próxima linha
}

int main() {
    int n;

    printf("Digite um numero natural N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, insira um numero nao negativo.\n");
        return 1;
    }

    // Parte 1: Calcular e exibir o valor
    int resultado = numero_triangular(n);
    printf("O %d-esimo numero triangular e: %d\n\n", n, resultado);

    // Parte 2: Imprimir o triângulo
    printf("A representacao do triangulo e:\n");
    imprimir_triangulo(n);

    return 0;
}
