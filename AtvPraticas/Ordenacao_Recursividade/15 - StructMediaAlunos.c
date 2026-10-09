#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    int RA;
    char nome[51];
    int faltas;
    float nota;
} TipoAluno;

void OrdenaAlunos(TipoAluno *alunos, int fim) {
    TipoAluno auxiliar;
    int x, y;
	for (x = fim-1; x > 0; x--){
		for (y=0;y<x;y++){
			if (strcmp(alunos[y].nome, alunos[y+1].nome)>0)
			{
			   auxiliar=alunos[y];
			   alunos[y]=alunos[y+1];
			   alunos[y+1]=auxiliar;
			}
		}
	}
}

float CalculaMedia(TipoAluno *alunos, int fim) {
    float notas = 0;

    for(int i=0; i < fim; i++) {
        notas += alunos[i].nota;
    }

    return notas/fim;
}

void OrdenarPorRA(TipoAluno *alunos, int fim) {

    TipoAluno auxiliar;
    int x, y;
	for (x = fim-1; x > 0; x--){
		for (y = 0; y < x; y++){
			   if (alunos[y].RA > alunos[(y+1)].RA)
			   {
			      auxiliar = alunos[y];
			      alunos[y]=alunos[(y+1)];
			     alunos[(y+1)]= auxiliar;
			   }
		}
	}
}
int PesquisaBinaria(struct Aluno *alunos, int Inicio, int Fim, int Valor)
{
  int Meio;
  if(Inicio>Fim)
    return -1;
  Meio = (Inicio + Fim) / 2;
  if(Valor>alunos[Meio].RA)
     return(PesquisaBinaria(alunos,Meio + 1,Fim,Valor));

	if(Valor<alunos[Meio].RA)
    return(PesquisaBinaria(alunos,Inicio,Meio-1,Valor));
  return Meio;
}

int main() {
    // Armazenar dados de 6 alunos de forma fixa
    TipoAluno alunos[6] = {
        {101, "Carlos", 2, 7.5},
        {102, "Ana", 1, 8.0},
        {103, "Pedro", 0, 6.0},
        {104, "Maria", 3, 9.0},
        {105, "Joao", 2, 7.0},
        {106, "Bianca", 4, 5.5}
    };

    int n = 6;

    // Ordenar os alunos por nome
    // CHAMAR A FUNÇÃO QUE ORDENA POR NOME
    OrdenaAlunos(alunos, n);

    // Calcular a média das notas
    // CHAMAR A FUNÇÃO MÉDIA
    float media = CalculaMedia(alunos, n);

    // Exibir alunos ordenados por nome
    for(int i=0; i < n; i++)
        printf("Alunos ordenados por nome: %s\n", alunos[i].nome);


    // Exibir a média das notas
    printf("\nMedia das notas dos alunos: %.2f\n", media);

    // Ordenar os alunos por RA para a pesquisa binária
    OrdenarPorRA(alunos, n);

    // Realizar a pesquisa binária pelo RA 105
	// Mostrar o aluno encontrado
    int raBusca = 105;
	printf("\nAluno encontrado: %s\n", alunos[PesquisaBinaria(alunos, 0, n, raBusca)].nome);

    // Realizar nova pesquisa binária pelo RA 99
	// Mostrar que aluno não encontrado
    int aBusca = 99;
    if(PesquisaBinaria(alunos, 0, n, aBusca) == -1) {
        printf("\nAluno nao encontrado!\n");
    }

    return 0;
}

