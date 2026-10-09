#include <stdio.h>

int Sequencial(int n, int *vet, int indice) {

    if(indice < 10) {
        if(vet[indice] == n) {
            return 1;
        }
    }
    else {
        return 0;
    }

    return Sequencial(n, vet, indice+1);
}

int main() {
    int num, vetor[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int indice = 0;

    printf("Digite o numero desejado: ");
    scanf("%d", &num);

    if(Sequencial(num, vetor, indice) == 1) {
        printf("Possui numero correpondente");
    }
    else {
        printf("Nao possui o numero correspodente");
    }
}
