

// Criar a função deposita e saque (receber um numero de conta), pesquisar através de pesquisa
// binária e atualizar o saldo, verificando o limite.
// Caso exceda o limite não realizar o saque e dar mensagem de erro

// executar a ordenação por seleção por numero de conta.
// em seguida exibir todas as contas ordenadas.

#include <stdio.h>

struct CONTA
   {
      char nome[30];
	  int numconta;
	  float limite;
	  float saldo;
   };

void cadastraconta(struct CONTA contas[])
{
   contas[0].numconta=101; strcpy(contas[0].nome,"Robert");  contas[0].limite=1500;  contas[0].saldo=300;
   contas[1].numconta=15;  strcpy(contas[1].nome,"Luana");   contas[1].limite=1000;  contas[1].saldo=300;
   contas[2].numconta=110; strcpy(contas[2].nome,"Bruno");   contas[2].limite=2500;  contas[2].saldo=300;
   contas[3].numconta=99;  strcpy(contas[3].nome,"Ruan");    contas[3].limite=1500;  contas[3].saldo=300;
   contas[4].numconta=88;  strcpy(contas[4].nome,"Juan");    contas[4].limite=1500;  contas[4].saldo=300;

}

void mostraUmaconta(struct CONTA *conta)
{
   printf("\nConta: %03d",conta->numconta);
   printf(" Nome: %-15s",conta->nome);
   printf(" Saldo: %.2f\t",conta->saldo);
}

void ordenaConta(struct CONTA *vet, int tam) {
    for (int i=0; i<tam;i++){
    int minimo = i;
     // pega indice do menor
    for (int j=i+1;j<tam;j++){
        if ( vet[j].numconta < vet[minimo].numconta)
        {
            minimo = j;
        }
    }
    struct CONTA aux = vet[minimo];
    vet[minimo] = vet[i];
    vet[i] = aux;
    }
    printf("\n***Clientes ordenados pelo numero das contas***\n");
	for (int x=0;x<tam;x++){
	printf("\nCliente: %s\nNum da conta: %d\nLimite: %.2f\nSaldo: %.2f\n",
	       vet[x].nome, vet[x].numconta, vet[x].limite, vet[x].saldo);
    }
}

int PesquisaBinaria(struct CONTA *vet, int Inicio, int Fim, int Valor) {
    int Meio;
    if(Inicio>Fim)
        return -1;
    Meio = (Inicio + Fim) / 2;
    if(Valor > vet[Meio].numconta)
        return(PesquisaBinaria(vet, Meio + 1, Fim, Valor));
    if(Valor < vet[Meio].numconta)
        return(PesquisaBinaria(vet, Inicio, Meio-1, Valor));
    return Meio;
}

void deposito(struct CONTA *vet, int x) {
    float valorDeposito=0;

    printf("\nDigite o valor que deseja depositar: ");
    scanf("%f", &valorDeposito);

    vet[x].saldo += valorDeposito;

    printf("\n***Saldo Depositado!***\n");
    printf("\nCliente: %s\nNum da conta: %d\nLimite: %.2f\nSaldo: %.2f\n",
	       vet[x].nome, vet[x].numconta, vet[x].limite, vet[x].saldo);
}

void saque(struct CONTA *vet, int x) {
    float valorSaque=0;

    printf("\nDigite o valor que deseja sacar: ");
    scanf("%f", &valorSaque);

    while(valorSaque > vet[x].limite + vet[x].saldo) {
        printf("\nNao ha limite suficiente para esse saque! Digite o valor novamente: ");
        scanf("%f", &valorSaque);
    }
        vet[x].saldo -= valorSaque;
        printf("\n***Saldo Sacado!***\n");
        printf("\nCliente: %s\nNum da conta: %d\nLimite: %.2f\nSaldo: %.2f\n",
               vet[x].nome, vet[x].numconta, vet[x].limite, vet[x].saldo);

}

int main()
{
    struct CONTA vet[5];
    int i=5, inptNumConta=0, indiceConta;
    char escolha;

    cadastraconta(vet);
    ordenaConta(vet, i);

    printf("\nDigite o numero da sua conta: ");
    scanf("%d", &inptNumConta);

    while(escolha != 'p') {
        while(PesquisaBinaria(vet, 0, i, inptNumConta) == -1) {
            printf("Numero da conta nao encontrado, digite novamente: ");
            scanf("%d", &inptNumConta);
        }
        indiceConta = PesquisaBinaria(vet, 0, i, inptNumConta);

        printf("\nDigite 'd' para depositar ou 's' para sacar: ");
        scanf(" %c", &escolha);
        while(escolha != 'd' && escolha != 's' && escolha != 'p') {
            printf("Caractere invalido, digite novamente: ");
            scanf(" %c", &escolha);
        }
        if(escolha == 'd')
            deposito(vet, indiceConta);
        else
            saque(vet, indiceConta);
        printf("\nDeseja continuar o programa? (digite 'p' caso deseje parar) ");
        scanf(" %c", &escolha);
    }

    return 0;

}
