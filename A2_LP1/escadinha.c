#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    if (n <= 2) {
        printf("1\n");
        return 0;
    }

    int escadinhas = 1;
    int diff = v[1] - v[0];

    for (int i = 2; i < n; i++) {
        if (v[i] - v[i - 1] != diff) {
            escadinhas++;
            diff = v[i] - v[i - 1];
        }
    }

    printf("%d\n", escadinhas);

    return 0;
}
