#include <stdio.h>
#include <string.h>

//prototipos
void start();

//main
int main(){

    start();

    return 0;
}


//documentacao

void start(){

    int opcao;
    
    printf("Escolha o modo de criacao do caca palavras:\n\n");
    printf("\t - Abrir arquivos com matriz e palavras (0)\n");
    printf("\t - Matriz e palavras aleatorias (1)\n");
    printf("\t - Inserir tudo manualmente (2)\n");

    scanf("%d", &opcao);
    printf("\nVoce escolheu opcao ~%d~", opcao);

}