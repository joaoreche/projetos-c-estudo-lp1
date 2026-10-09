#include <stdio.h>

int Digitos(int N) {
    if(N >= 9) {
        return 1 + Digitos(N/10);
    }
    else {
        return 1;
    }
}


int main() {
    int num = 10;

    printf("Numero de digitos: %d", Digitos(num));
}
