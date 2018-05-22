#include <stdio.h>
#include <string.h>

//variaveis globais
int nPalavras;
int nColunas, nLinhas;
char matriz[100][100];
char lista[100][100];


//prototipo
void lerArquivo();
void imprimir();
void dimencoes();

//funcao main
int main(){

    dimencoes();
    lerArquivo();

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
    printf("Informe o numero de palavras: ");
    scanf("%d", &nPalavras);
}


//documentacao funcao
//------------
void lerArquivo(){    

    //contadores
    int i, j;

    //ler matriz
    FILE *arquivoX;
    char *nome = "matriz.txt";
    arquivoX = fopen(nome, "r");

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            fscanf(arquivoX ,"%c", &matriz[i][j]);
        }
    }
    fclose(arquivoX);

    
    //ler lista de palavras
    nome = "palavras.txt";
    arquivoX = fopen(nome, "r");
    int c=0;

    while(!feof(arquivoX)){
        fscanf(arquivoX, "%s", &lista[c++]);
    }
    fclose(arquivoX);

    //imprimir arquivos
    printf("\n");
    imprimir();

    return;
}


//documentacao funcao
//------------
void imprimir(){

    int i, j;

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("%c%c", matriz[i][j], j==nColunas-1?'\n':' ');
        }
    }
    
    printf("\n");

    for(i=0; i<nPalavras; i++){
        printf("%s\n", lista[i]);
    }

    return;
}