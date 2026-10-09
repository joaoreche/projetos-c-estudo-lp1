#include <stdio.h>
#include <string.h>

void subString(char origem[], char destino[], int inicio, int fim) {

    int j=0;

        for(int i=inicio; i < fim; i++) {
            destino[j] = origem[i];
            j++;
        }
        destino[j] = '\0';

    }

void juntaString(char string2[], char metade[]) {

    strcat(string2, metade);

    printf("Resultado: %s", string2);

}

int main() {

    char string1[50], string2[50], metade[50];
    int length;

    printf("Digite a palavra 1: ");
    scanf(" %[^\n]", string1);
    printf("Digite a palavra 2: ");
    scanf(" %[^\n]", string2);

    length = strlen(string1)/2;

    subString(string1, metade, 0, length);

    juntaString(string2, metade);

    return 0;
}
