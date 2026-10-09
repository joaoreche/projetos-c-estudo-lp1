#include <stdio.h>

int main() {
    int vetorA[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int vetorB[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int vetorC[20];
    int x=0;

    for(int i=0; i<20; i++) {
            vetorC[x]= vetorA[i] + vetorB[i];
            x++;
    }

    printf("Vetor C: ");

    for(int i=0; i<20; i++) {
        printf("%d, ", vetorC[i]);
    }
}
