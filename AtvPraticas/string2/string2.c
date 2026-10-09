#include <stdio.h>
#include <ctype.h>

void MudaFrase(char frase[100]) {

    char preposicao[4];
    int j=0;

    for(int i=0; frase[i] != '\0'; i++) {
        if (i==0) {
            frase[i] = toupper(frase[i]);
        }
        else if (frase[i] == ' ') {
            frase[i+1] = toupper(frase[i+1]);
        }
        else if(frase[i] == 'D') {
            if(frase[i+2] == ' ') {
                frase[i] = tolower(frase[i]);
            }
            else if(frase[i+2] == '\0') {
                frase[i] = tolower(frase[i]);
            }
            else if(frase[i+2] == 's') {
                if(frase[i+3] == ' ') {
                    frase[i] = tolower(frase[i]);
                }
                else if(frase[i+3] == '\0') {
                    frase[i] = tolower(frase[i]);
                }
            }
        }
        else if(frase[i] == 'E') {
            if(frase[i+1] == ' ') {
                frase[i] = tolower(frase[i]);
            }
            else if(frase[i+1] == '\0') {
                frase[i] = tolower(frase[i]);
            }
        }
    }

    printf("%s", frase);

}

int main() {

    char frase[100];

    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    MudaFrase(frase);

    return 0;

}
