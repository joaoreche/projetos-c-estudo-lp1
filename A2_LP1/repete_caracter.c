#include <stdio.h>

int main() {
    int numeros[6];
    char caracteres[6];

    for (int i = 0; i < 6; i++) {
        printf("Digite numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < 6; i++) {
        printf("Digite caractere %d: ", i + 1);
        scanf(" %c", &caracteres[i]);
    }

    printf("\nSaida:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < numeros[i]; j++) {
            printf("%c", caracteres[i]);
        }
        printf("\n");
    }

    return 0;
}
