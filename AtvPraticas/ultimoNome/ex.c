#include <stdio.h>
#include <string.h>

int main() {
    char nomeCompleto[40];
    char *p;
    int length, ultimoNome = 0, primeiroNome = 0;

    printf("Digite um nome completo: ");
    scanf("%[^\n]", nomeCompleto);

    p = nomeCompleto;
    length = strlen(nomeCompleto);

    for(int i = 0; nomeCompleto[i] != ' '; i++) {
        primeiroNome++;
    }
    for(int i = length-1; nomeCompleto[i] != ' '; i--) {
        ultimoNome++;
    }

    printf("%s, ", (p + (length - ultimoNome)));
    for(int i = 0; i < primeiroNome; i++) {
        printf("%c", *(p+i));
    }
}
