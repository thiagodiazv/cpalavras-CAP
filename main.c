#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//variáveis globais
int nPalavras;
int nColunas, nLinhas;
char matriz[100][100];
char lista[100][100];



//prototipo
void lerArquivo();
void imprimir();
void dimencoes();
int start();
void aleat();


//main!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//----------------------------------
int main(int argc, char *argv[]){

    int x;
    x=start();    
    dimencoes();
    printf("\nstart = %d\n", x);

    if(x==0){
        lerArquivo();
        imprimir();
    }
    else if (x==1){
        aleat();
    }

    return 0;
}



//======================================================================================================



//documentacao funcao
//------------
int start(){

    int opcao;
    
    printf("Escolha o modo de criacao do caca palavras:\n\n");
    printf("\t - Abrir arquivos com matriz e palavras (0)\n");
    printf("\t - Matriz e palavras aleatorias (1)\n");
    printf("\t - Inserir tudo manualmente (2)\n");

    scanf("%d", &opcao);
    //printf("\nVoce escolheu opcao ~%d~", opcao);

    return opcao;

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

    return;
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
            fscanf(arquivoX ,"%c ", &matriz[i][j]);
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



//documentacao funcao
//------------
void aleat(){

    //contadores
    int i, j;

    srand(time(NULL));    

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            matriz[i][j]=(rand()%26)+(65);
        }
    }

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("%c%c", matriz[i][j], j==nColunas-1?'\n':' ');
        }
    }

    return;
}

