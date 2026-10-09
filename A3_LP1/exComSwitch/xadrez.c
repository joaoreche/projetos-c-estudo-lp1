#include <stdio.h>

int main() {
    int matTab[8][8], vetContador[7] = {0};

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            scanf("%d", &matTab[i][j]);
        }
    }

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            switch(matTab[i][j]){
                case 0:
                    vetContador[0] += 1;
                    break;
                case 1:
                    vetContador[1] += 1;
                    break;
                case 2:
                    vetContador[2] += 1;
                    break;
                case 3:
                    vetContador[3] += 1;
                    break;
                case 4:
                    vetContador[4] += 1;
                    break;
                case 5:
                    vetContador[5] += 1;
                    break;
                default:
                    vetContador[6] += 1;
            }
        }
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
