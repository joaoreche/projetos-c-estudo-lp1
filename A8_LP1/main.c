#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Verifica se um caractere é uma consoante (maiúscula ou minúscula).
 * 
 * @param c O caractere a ser verificado.
 */
int is_consoante(char c) {
    // Converte o caractere para maiúsculo para simplificar a verificação.
    char c_upper = toupper(c);

    // Primeiro, verifica se é uma letra do alfabeto.
    if (c_upper >= 'A' && c_upper <= 'Z') {
        // Se for uma letra, verifica se NÃO é uma vogal.
        if (c_upper != 'A' && c_upper != 'E' && c_upper != 'I' && c_upper != 'O' && c_upper != 'U') {
            return 1; // É uma consoante.
        }
    }
    return 0; // Não é uma consoante.
}

/**
 * @brief Criptografa uma frase invertendo-a e trocando suas consoantes por '#'.
 *        A própria string passada como argumento é alterada. Usa notação de ponteiro.
 * 
 * @param frase Um ponteiro para o início da string a ser modificada.
 */
void criptografar_frase(char *frase) {
    int len = strlen(frase);
    if (len == 0) return; // Não faz nada se a string estiver vazia.

    // --- a.1) Inversão da frase usando ponteiros ---
    char *inicio = frase;
    char *fim = frase + len - 1; // Ponteiro para o último caractere

    while (inicio < fim) {
        // Troca os caracteres apontados por 'inicio' e 'fim'
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        // Move os ponteiros em direção ao centro da string
        inicio++;
        fim--;
    }

    // --- a.2) Troca de consoantes por '#' usando um ponteiro ---
    char *ptr = frase; // Ponteiro para percorrer a string já invertida

    while (*ptr != '\0') {
        if (is_consoante(*ptr)) {
            *ptr = '#'; // Altera o caractere no local
        }
        ptr++; // Avança o ponteiro para o próximo caractere
    }
}

/**
 * @brief Função principal (main) para testar a criptografia.
 */
int main() {
    // b) Cria as variáveis necessárias no main
    char frase_usuario[256];

    // Solicita a entrada do usuário
    printf("Digite uma frase para criptografar: ");
    
    // Usa fgets para ler a linha inteira, incluindo espaços.
    // É mais seguro que scanf.
    fgets(frase_usuario, sizeof(frase_usuario), stdin);

    // fgets inclui o caractere de nova linha ('\n') no final.
    // Precisamos removê-lo para que a inversão funcione corretamente.
    // A função strcspn encontra a primeira ocorrência de '\n' e a substitui por '\0'.
    frase_usuario[strcspn(frase_usuario, "\n")] = '\0';
    
    printf("\nFrase Original: %s\n", frase_usuario);

    // b) Chama a função passando a string para ser modificada
    criptografar_frase(frase_usuario);

    // Imprime o resultado final
    printf("Frase Criptografada: %s\n", frase_usuario);

    return 0;
}