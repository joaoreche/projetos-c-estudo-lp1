#include <stdio.h>
#include <string.h>

void inverteFrase(char frase[5][12], char fraseInvertida[10][12]) {
    for(int i=0; i<10; i++) {
            printf("%s", frase);
        }
        printf("\n");
}

int main() {
    char frase[10][12], fraseInvertida[5][12];

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    inverteFrase(frase, fraseInvertida);
}
