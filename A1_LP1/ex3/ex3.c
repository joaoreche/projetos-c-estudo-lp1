#include <stdio.h>

int main() {
    int matA[25], matB[25], matC[50], x=0;

    for (int i=0;i<25;i++) {
        //printf("Digite os valores da matriz A: ");
        scanf("%d",&matA[i]);
    }
    for (int i=0;i<25;i++) {
        //printf("Digite os valores da matriz B: ");
        scanf("%d",&matB[i]);
    }
    for (int i=0;i<50;i+=2) {
	    matC[i]=matA[x];
        matC[i+1]=matB[x];
        x++;
    }
    printf("Matriz C: ");
    for (int i=0;i<50;i++) {
        printf("%d ",matC[i]);
    }

}
