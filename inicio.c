#include <stdio.h>
#include <string.h>

//prototipos
void start();

//main
int main(){

    start();

    return 0;
}


//documentacao funcao
//------------
void start(){

    int opcao;
    
    printf("Escolha o modo de criacao do caca palavras:\n\n");
    printf("\t - Criar matriz e palavras aleatorias (0)\n");
    printf("\t - Abrir arquivos de matriz e palavras (1)\n");
    printf("\t - Inserir dados manualmente (2)\n");

    scanf("%d", &opcao);
    printf("\nVoce escolheu opcao ~%d~", opcao);
    
    return;
}