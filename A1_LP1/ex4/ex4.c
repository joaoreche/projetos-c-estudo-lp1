#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float c[10], h[10], areas[10], potComodo[10], totalPot = 0;
    int numComodos, classes[10], numLamp[10], totalLamp = 0;

    printf("Digite a quantidade de cômodos da residência? ");
    scanf("%d", &numComodos);

    for(int i=0; i < numComodos; i++) {
        printf("Digite a classe do cômodo %d (1 a 5): ", i+1);
        scanf("%d", &classes[i]);
        if (classes[i] < 1 || classes[i] > 5) {
            printf("\nNúmero Inválido! Digite novamente: ");
            scanf("%d", &classes[i]);
        }
    }

    for(int i=0; i < numComodos; i++) {
        printf("Digite o comprimento do cômodo: ");
        scanf("%f", &c[i]);
        printf("Digite a altura do cômodo: ");
        scanf("%f", &h[i]);
        areas[i] = c[i] * h[i];
    }

    for (int i=0; i< numComodos; i++) {
        switch (classes[i]) {
            case 1:
                potComodo[i] = areas[i] * 10;
                break;
            case 2:
                potComodo[i] = areas[i] * 15;
                break;
            case 3:
                potComodo[i] = areas[i] * 18;
                break;
            case 4:
                potComodo[i] = areas[i] * 20;
                break;
            default:
                potComodo[i] = areas[i] * 25;
        }
        numLamp[i] = ceil(potComodo[i] / 60); // função ceil() vem da biblioteca <math.h> e sempre arredonda um número float/double para cima
        totalLamp += numLamp[i];
        totalPot += potComodo[i];
    }

    printf("\nResultados por Cômodo:\n");

    for(int i = 0; i < numComodos; i++) {
        printf("\nCômodo %d:\n", i+1);
        printf("Área: %.2f m²\n", areas[i]);
        printf("Potência de Iluminação: %.2f\n", potComodo[i]);
        printf("Número de Lâmpadas: %d\n", numLamp[i]);
    }

        printf("\nResultados Totais:\n");
        printf("Total de Lâmpadas: %d\n", totalLamp);
        printf("Total de Potência de Iluminação: %.2f\n", totalPot);
}
