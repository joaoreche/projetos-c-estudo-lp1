#include <stdio.h>
#include <string.h>

void main() {
    char palavra[20], vogais[6] = {'a', 'e', 'i', 'o', 'u', '\0'}, L;
    int contadorVogais=0;

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    printf("Digite o caractere que deseja substituir as vogais: ");
    scanf(" %c", &L);

    for(int i=0; palavra[i] != '\0'; i++) {
        for(int j=0; vogais[j] != '\0'; j++) {
            if(palavra[i] == vogais[j]) {
                contadorVogais++;
                palavra[i] = L;
            }
        }
    }

    printf("\nQuantidade de vogais: %d", contadorVogais);
    printf("\nPalavra com as vogais substituidas: %s", palavra);
}
