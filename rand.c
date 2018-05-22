//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//variaveis globais
int nColunas, nLinhas, nPalavras;

//prototipos
void dimencoes();



//funcao main
int main(int argc, char *argv[]){

    dimencoes();

    int i, j, flag;

    char mat[nLinhas][nColunas];
    //palavras[nPalavras][1000];

    srand(time(NULL));    

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            mat[i][j]=(rand()%26)+(65);
        }
    }

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("%c%c", mat[i][j], j==nColunas-1?'\n':' ');
        }
    }
  
    return 0;
}


//documentacao funcao
//------------
void dimencoes(){
    //ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &nColunas);

    //numero de palavras
    //printf("Informe o numero de palavras: ");
    //scanf("%d", &nPalavras);
}
