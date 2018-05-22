//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//funcao main()

int main(int argc, char *argv[]){

    //int strtol(aleat(), (NULL), 10);


    //ler tamanho da matriz
    int nColunas, nLinhas;
    printf("Informe o numero de linhas:");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas:");
    scanf("%d", &nColunas);

    //func rand()
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
