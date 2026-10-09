#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Criptografar(char frase[], int K) {

    char fraseCriptografada[150];
    int j=0;

    for(int i=0; frase[i] != '\0'; i++, j++) {
        if(isalpha(frase[i])) {
            if(frase[i] + K > 'z') {
                fraseCriptografada[j] = frase[i] + K - 26;
            }
            else if(isupper(frase[i])) {
                if(frase[i] + K > 'Z') {
                    fraseCriptografada[j] = frase[i] + K - 26;
                }
                else {
                    fraseCriptografada[j] = frase[i] + K;
                }
            }
            else {
                fraseCriptografada[j] = frase[i] + K;
            }
        }
        else {
            fraseCriptografada[j] = frase[i];
        }
    }
    fraseCriptografada[j] = '\0';

    printf("\n%s", fraseCriptografada);

}

int main() {

    char frase[150];
    int K=-1;

    do {
        printf("\nDigite uma frase: ");
        scanf(" %[^\n]", frase);

        printf("\nInsira um numero K (K=0 para o programa): ");
        scanf("%d", &K);

        Criptografar(frase, K);
    } while(K != 0);

    return 0;

}
