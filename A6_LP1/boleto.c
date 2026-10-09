#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAXA_VENCIMENTO 0.10

void TipoBanco(char banco[4]) {
    switch(atoi(banco)) {
        case 001:
            printf("\nO boleto eh do Banco do Brasil!");
            break;
        case 033:
            printf("\nO boleto eh do banco Santander!");
            break;
        case 104:
            printf("\nO boleto eh da Caixa Economica Federal!");
            break;
        case 341:
            printf("\nO boleto eh do banco Itau!");
            break;
        case 745:
            printf("\nO boleto eh da Citibank!");
            break;
        default:
            printf("\nBanco desconhecido!");
    }
}

double ValorBoleto(char valor[11]) {
    double valorBoleto;

    valorBoleto = atof(valor)/100;
    valorBoleto += valorBoleto * TAXA_VENCIMENTO;

    return valorBoleto;
}

int main() {
    char boleto[54], banco[4], valor[11], escolha[10];
    int j=0, length;

    do {
        printf("Digite o boleto: ");
        scanf(" %[^\n]", boleto);

        for(int i=0; boleto[i] != '\0'; i++) {
            if(boleto[i] != '.' && boleto[i] != ',') {
                boleto[j] = boleto[i];
                j++;
            }
        }
        boleto[j] = '\0';
        j=0;

        for(int i=0; i<3; i++) {
            banco[j] = boleto[i];
            j++;
        }
        banco[j] = '\0';
        j=0;

        length = strlen(boleto);

        for(int i=length - 10; i < length; i++) {
            if(boleto[i] != '0') {
                valor[j] = boleto[i];
                j++;
            }
        }
        valor[j] = '\0';

        TipoBanco(banco);
        printf("\nO valor a ser pago eh: R$%.2f", ValorBoleto(valor));

        printf("\n\nDigite FIM para encerrar o programa: ");
        scanf(" %s", escolha);
        strupr(escolha);
    } while(strcmp(escolha, "FIM") != 0);

    return 0;
}
