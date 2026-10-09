#include <stdio.h>

void valoresComuns(int vetor1[20], int vetor2[20], int numElem1, int numElem2) {
    int vetorComum[20], contador = 0;

    for(int i = 0; i < numElem1; i++)
        for(int j = 0; j < numElem2; j++) {
            if (vetor1[i] == vetor2[j]) {
                vetorComum[contador] = vetor1[i];
                contador++;
            }
        }
    if (contador == 0)
        printf("\nNao exitem valores comuns");
    else {
        printf("\nValores comuns: ");
        for(int i = 0; i < contador; i++) {
            printf("%d ", vetorComum[i]);
        }
    }

}

void main() {
    int vet1[20], vet2[20], numElementosVet1, numElementosVet2;

    printf("\nDigite a quantidade de elementos do vetor 1 (max 20): ");
    scanf("%d", &numElementosVet1);

    printf("\nDigite a quantidade de elementos do vetor 2 (max 20): ");
    scanf("%d", &numElementosVet2);

    for (int i = 0; i < numElementosVet1; i++) {
        printf("\nDigite o %do elemento do vetor 1: ", i+1);
        scanf("%d", &vet1[i]);
    }
    for (int i = 0; i < numElementosVet2; i++) {
        printf("\nDigite o %do elemento do vetor 2: ", i+1);
        scanf("%d", &vet2[i]);
    }

    valoresComuns(vet1, vet2, numElementosVet1, numElementosVet2);
}
