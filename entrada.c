#include <stdio.h>
#include <string.h>

#define max 10

int main(){

    int start;
    
    printf("Escolha o modo de criacao do jogo:\n\n");
    printf("\t - Matriz e palavras aleatorias (0)\n");
    printf("\t - Inserir tudo manualmente (1)\n");
    printf("\t - Abrir arquivos com matriz e palavras (2)\n");
    printf("\t - Matriz aleatoria e arquivo com palavras (3)\n");
    printf("\t - Arquivo com matriz e palavras aleatorias (4)\n");    
    printf("\n");
    scanf("%d", &start);
    printf("Voce escolheu opcao ~%d~", start);

    return 0;
}