#include <stdio.h>
#include <string.h>

void subString(char origem[][9], char destino[][4], int inicio, int fim, int numLinhas) {

    int j=0;

    for(int l=0; l < numLinhas; l++) {

        for(int i=inicio; i <= fim; i++) {
            destino[l][j] = origem[l][i];
            j++;
        }

        destino[l][j] = '\0';
        j=0;

    }
}

void ConverteRA(char raAntigo[][9], char curso[][4], char anoIngresso[][4], char semestreIngresso[][4], char numSequencial[][4], int numCasos) {

    char raNovo[5][14], codigoCursos[5][4] = {"048\0"};

    for(int i=0; i < numCasos; i++) {
        strcpy(raNovo[i], "003");

        if(strcmp(curso[i], "AD") == 0) {
            strcat(raNovo[i], "048");
            strcat(raNovo[i], anoIngresso[i]);
            strcat(raNovo[i], semestreIngresso[i]);
            strcat(raNovo[i], "1");
            strcat(raNovo[i], numSequencial[i]);
        }
        else if(strcmp(curso[i], "AN") == 0) {
            strcat(raNovo[i], "048");
            strcat(raNovo[i], anoIngresso[i]);
            strcat(raNovo[i], semestreIngresso[i]);
            strcat(raNovo[i], "3");
            strcat(raNovo[i], numSequencial[i]);
        }
    }

    for(int i=0; i < numCasos; i++) {
        printf("%s\n", raNovo[i]);
    }
}

int main() {

    int numCasos;
    char raAntigo[5][9], curso[5][4], anoIngresso[5][4], semestreIngresso[5][4], numSequencial[5][4];

    printf("Digite a quantidade de casos que deseja testar (0-5): ");
    scanf("%d", &numCasos);

    printf("Digite o(s) RA(s): ");
    for(int i=0; i < numCasos; i++) {
        scanf(" %[^\n]", raAntigo[i]);
    }
    //separando sigla do curso
    subString(raAntigo, curso, 0, 1, numCasos);
    //separando ano de ingresso do aluno
    subString(raAntigo, anoIngresso, 2, 3, numCasos);
    //separando semestre de ingresso do aluno
    subString(raAntigo, semestreIngresso, 4, 4, numCasos);
    //separando numero sequencial do aluno
    subString(raAntigo, numSequencial, 5, 7, numCasos);

    ConverteRA(raAntigo, curso, anoIngresso, semestreIngresso, numSequencial, numCasos);

    return 0;

}
