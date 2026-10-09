#include <stdio.h>
#include <string.h>

int main() {
    char string[40], palavra[20];
    char *p;
    int cont = 0;

    printf("Digite uma frase: ");
    scanf(" %[^\n]", string);

    printf("Digite uma palavra: ");
    scanf(" %[^\n]", palavra);

    p = string;
    while(p != NULL) {
        p = strstr(p, palavra);

        if(p != NULL) {
            cont++;
            p++;
        }
    }

    if(cont != 0) {
        printf("Qnte de %s: %d", palavra, cont);
    }
    else {
        printf("Nao ha nenhuma orrencia dessa palavra");
    }
}

