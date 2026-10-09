#include <stdio.h>

int main() {
    int vetorA[10], vetorB[10], x=0;

    for(int i=0; i<10; i++) {
        printf("Digite os valores do vetor: ");
        scanf("%d", &vetorA[i]);
    }
    for(int i=9; i>=0; i--) {
        vetorB[x] = vetorA[i];
        x++;
    }
    printf("\nVetor B: ");

    for(int i=0; i<10; i++) {
        printf("%d ", vetorB[i]);
    }
}
