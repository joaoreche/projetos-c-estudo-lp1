#include <stdio.h>
#include <string.h>

void main() {
    int vetorIndices[20], contador=0;
    char palavra[20], L;

    printf("Digite uma palavra/frase (ate 20 caracteres): ");
    scanf("%[^\n]", palavra);
    printf("Digite um caractere: ");
    scanf(" %c", &L);
    strupr(palavra);

    for(int i=0; palavra[i] != '\0'; i++) {
        if(palavra[i] == toupper(L)) {
            vetorIndices[contador] = i;
            contador++;
        }
    }
    printf("Indices correpondentes a letra %c: ", L);
    for(int i=0; i < contador ; i++)
        printf("%d ", vetorIndices[i]);
}
