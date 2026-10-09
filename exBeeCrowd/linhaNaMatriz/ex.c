#include <stdio.h>

int main() {

    int L;
    char T;
    double media=0, soma=0;
    float M[12][12];

    scanf("%d", &L);
    scanf(" %c", &T);

    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++)
            scanf("%f", &M[i][j]);

    for(int j=0; j<12; j++) {
        soma += M[L][j];
    }

    if(T == 'M') {
        media = soma/12;
        printf("%.1f\n", media);
    }
    else
        printf("%.1f\n", soma);

    return 0;
}
