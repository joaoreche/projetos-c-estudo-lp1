#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    char nome[10], nome1[10], senha[21];

    printf("\nDigite um nome: ");
    //scanf("%s", nome); não le strings com espaços
    scanf("%[^\n]", nome); // le string com espaços
    // vetor nao precisa de &, pois um vetor sem [] indica a posicao inicial do vetor

    //gets(nome);
    printf("\nO nome digitado eh: %s", nome);

    nome1[0] = 'R';
    nome1[1] = 'e';
    nome1[2] = 'c';
    nome1[3] = 'h';
    nome1[4] = 'e';
    nome1[5] = '\0';

    printf("\nO nome digitado letra a letra eh: %s", nome1);

    //conta a qtde de caracteres digitados
    printf("\nQtde caracteres digitados: %d", strlen(nome));

    //concatenar string
    strcat(nome, nome1);
    printf("\nNome: %s e Nome1: %s", nome, nome1);

    //nome1 = "Silva"; ERRADO

    strcpy(nome1, "Vitor"); // substitui o valor de nome1
    printf("\nNome: %s e Nome1: %s", nome, nome1);

    //if (senha == "ADMIN") ERRADO

    //compara
    if(strcmp(senha, "ADMIN") == 0)
        printf("\nIguais");
    else
        printf("\nDiferentes");

    //transforma todos os caracteres em maiusculo/minusculo
    printf("\nMaiusculo %s", strupr(nome));
    printf("\nMinusculo %s", strlwr(nome));

    //transforma apenas um caracter para maisculo/minusculo
    printf("\nA segunda letra de nome eh: %c", toupper(nome[1]));
    printf("\nA segunda letra de nome eh: %c", tolower(nome[1]));

    //--funcao de conversao de numeros:
    char numeroInt[10] = "1520", numeroFloat[10] = "15.20";

    int num = atoi(numeroInt); //converte em UM numero inteiro
    printf("\n%d", num);
    float num1 = atof(numeroFloat); //converte em UM numero float
    printf("\n%f", num1);
}
