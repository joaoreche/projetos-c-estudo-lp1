#include <stdio.h>

int CalculaDigitos(int maiorNum) {

    int T=0;

    while(maiorNum > 0) {
        maiorNum /= 10;
        T++;
    }

    return T;

}

int main() {

    int N, maiorNum, M[15][15];
    int contador=1;

    do {
        scanf("%d", &N);

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) {
                if(i == 0 && j == 0) {
                    M[i][j] = 1;
                }
                else if(i != 0) {
                    M[i][j] = M[i-1][j] * 2;
                }
                else {
                    M[i][j] = M[i][j-1] * 2;
                }
            }
        }

        maiorNum = M[N-1][N-1];

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                printf("%*d", CalculaDigitos(maiorNum), M[i][j]);
                if(j < N-1){
                    printf(" ");
                }
            }
            printf("\n");
        }

        if(contador = N) {
            printf("\n");
        }

        contador++;
    } while(N != 0);

    return 0;

}
