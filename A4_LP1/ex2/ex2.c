#include <stdio.h>
#include <string.h>

#define TAXA_ASSOCIACAO_JOVEM 200
#define TAXA_ASSOCIACAO_ADULTO 300

int calculoPlanoJovem(int dependentes) {
    int totalJovem;

    totalJovem = TAXA_ASSOCIACAO_JOVEM + (30 * 12);
    if (dependentes != 0)
        totalJovem += dependentes * 10 * 12;

    return totalJovem;
}

int calculoPlanoAdulto(int dependentes) {
    int totalAdulto;

    if (dependentes == 0)
        totalAdulto = TAXA_ASSOCIACAO_ADULTO + (60 - 60 * 0.1) * 6 + 60 * 6;
    else
        totalAdulto = TAXA_ASSOCIACAO_ADULTO + 60 * 12;

    return totalAdulto;
}

void main() {
    int idade, numDependentes;
    char tipoPlano[10];

    printf("Qual a sua idade? ");
    scanf("%d", &idade);

    printf("\nNumero de dependentes: ");
    scanf("%d", &numDependentes);

    if (idade >= 16 && idade < 20)
        strcpy(tipoPlano, "Jovem");
    else
        strcpy(tipoPlano, "Adulto");

    printf("\nPlano: %s", tipoPlano);
    printf("\nNumero de dependentes: %d", numDependentes);

    if (strcmp(tipoPlano, "Jovem") == 0)
        printf("\nTotal a pagar em 1 ano: R$%d,00", calculoPlanoJovem(numDependentes));
    else
        printf("\nTotal a pagar em 1 ano: R$%d,00", calculoPlanoAdulto(numDependentes));
}
