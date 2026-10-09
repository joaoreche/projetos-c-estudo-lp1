# Cifra de César

## Descrição
Implementação em C do algoritmo clássico de criptografia por substituição conhecido como **Cifra de César**.

O programa recebe uma frase e uma chave inteira de deslocamento $K$. A função `Criptografar` percorre os caracteres da frase e desloca cada letra em $K$ posições no alfabeto, preservando maiúsculas, minúsculas e o ciclo alfabético de 26 letras.

## Exemplo
- **Entrada:**
  - Frase: `Ola Mundo`
  - Deslocamento $K$: `3`
- **Saída:**
  - Frase criptografada: `Roh Pxqgr`
