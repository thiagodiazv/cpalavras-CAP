#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//variáveis globais
int nColunas, nLinhas, nPalavras, tamPalavras;
char matriz[100][100], lista[100][100];

//prototipo
void aleat();
void dimencoes();
void imprimir();


//======main======
int main(){

    dimencoes();
    aleat();
    imprimir();

    return 0;
}

//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void dimencoes(){
    //ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &nColunas);
    //numero de palavras
    printf("Informe o numero de palavras: ");
    scanf("%d", &nPalavras);
    printf("Informe o tamanho de letras das palavras: ");
    scanf("%d", &tamPalavras);

    return;
}

//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void imprimir(){

    int i, j;
    printf("\n");

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("%c%c", matriz[i][j], j==nColunas-1?'\n':' ');
        }
    }
    for(i=0; i<nPalavras; i++){
        printf("%s\n", lista[i]);
    }

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void aleat(){

    //contadores
    int i, j;

    srand(time(NULL));

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            matriz[i][j]=(rand()%26)+(65);
        }
    }

    for(i=0; i<nPalavras; i++){
        for(j=0; j<tamPalavras; j++){
            lista[i][j]=(rand()%26)+(65);
        }
    }

    return;
}
