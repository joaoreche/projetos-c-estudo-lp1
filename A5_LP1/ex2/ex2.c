#include <stdio.h>
#include <string.h>

void main() {
    char palavra[20], L;
    int contadorLetras=0;

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    strupr(palavra);
    printf("\nDigite uma letra: ");
    scanf(" %c", &L);

    for(int i=0; palavra[i] != '\0'; i++) {
        if(palavra[i] == toupper(L)) {
            contadorLetras++;
        }
    }

    printf("\nQuantidade de ocorrencias da letra: %d", contadorLetras);
}
