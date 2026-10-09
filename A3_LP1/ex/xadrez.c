#include <stdio.h>

int main() {
    int matTab[8][8], vetContador[7] = {0};

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            scanf("%d", &matTab[i][j]);
        }
    }

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++)
        vetContador[matTab[i][j]]++;
    }

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%d ", matTab[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<7; i++) {
        printf("%d:", i);
        printf("%d\n", vetContador[i]);
    }
}
