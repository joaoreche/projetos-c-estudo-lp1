#include <stdio.h>

void inverterString(char *str) {
    char *inicio = str;
    char *fim = str;

    while (*fim != '\0') {
        fim++;
    }
    if (fim > inicio) {
        fim--;
    }

    while (inicio < fim) {
        char temp = *inicio;

        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main() {
    char entrada[50];

    printf("Digite uma string: ");
    scanf(" %[^\n]", entrada);

    inverterString(entrada);
    printf("String invertida: %s\n", entrada);

    return 0;
}
