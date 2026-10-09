#include <stdio.h>

/**
 * @brief Troca os valores de duas variáveis inteiras.
 *        Usa ponteiros para modificar as variáveis originais.
 * 
 * @param a Ponteiro para a primeira variável.
 * @param b Ponteiro para a segunda variável.
 */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Ordena um array de inteiros em ordem crescente usando Bubble Sort.
 * 
 * @param arr O array a ser ordenado.
 * @param n O número de elementos no array.
 */
void bubble_sort_crescente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/**
 * @brief Ordena um array de inteiros em ordem decrescente usando Bubble Sort.
 * 
 * @param arr O array a ser ordenado.
 * @param n O número de elementos no array.
 */
void bubble_sort_decrescente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/**
 * @brief Imprime os elementos de um array, um por linha.
 * 
 * @param arr O array a ser impresso.
 * @param n O número de elementos a imprimir.
 */
void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int n; // Quantidade total de números a serem lidos
    scanf("%d", &n);

    // Arrays para separar os números. O tamanho é 'n' pois, no pior caso,
    // todos os números podem ser pares ou todos podem ser ímpares.
    int pares[n];
    int impares[n];
    int cont_pares = 0;
    int cont_impares = 0;

    // 1. Leitura e Separação
    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);

        // Verifica se o valor é par ou ímpar
        if (valor % 2 == 0) {
            pares[cont_pares] = valor;
            cont_pares++;
        } else {
            impares[cont_impares] = valor;
            cont_impares++;
        }
    }

    // 2. Ordenação dos Pares (Crescente)
    bubble_sort_crescente(pares, cont_pares);

    // 3. Ordenação dos Ímpares (Decrescente)
    bubble_sort_decrescente(impares, cont_impares);

    // 4. Impressão dos resultados
    imprimir_array(pares, cont_pares);
    imprimir_array(impares, cont_impares);

    return 0;
}