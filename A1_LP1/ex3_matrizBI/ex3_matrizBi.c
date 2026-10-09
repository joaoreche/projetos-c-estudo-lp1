#include <stdio.h>

int main() {
    int matA[5][5]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    int matB[5][5]={2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};
    int matC[5][10], x=0, y=0;

 for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        matC[x][y] = matA[i][j];
        y++;
        matC[x][y] = matB[i][j];
        y++;
    }
    y=0;

    x++;
}
for(int i=0; i<5; i++) {
    for(int j=0; j<10; j++) {
        printf("%d ", matC[i][j]);
    }
    printf("\n ");
}

}
