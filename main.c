#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//variáveis globais
int nColunas, nLinhas, nPalavras, tamPalavras;
char matriz[100][100], lista[100][100];
char vetorzaum[1000000];


//prototipo
void lerArquivo();
void imprimir();
void dimencoes();
int start();
void aleat();


//main!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(int argc, char *argv[]){

    int x;
    x=start();
    printf("\nopcao escolida = %d\n\n", x);   
    dimencoes();    

    if(x==0){
        aleat();
        imprimir();
    }
    else if(x==1){
        lerArquivo();
        imprimir();
    }
    else if(x==2){
        printf("nao esta feita kkkkk\n");
    }

/*
    //char vetorzaum[nLinhas*nColunas*10];
    int i, j, cont=0;

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            vetorzaum[cont] = matriz[i][j];
            cont++;       
        }
        vetorzaum[cont] = '\n';
        cont++;
    }
    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            vetorzaum[cont] = matriz[j][i];
            cont++;       
        }
        vetorzaum[cont] = '\n';
        cont++;
    }
    vetorzaum[cont] = '\0';


//    for(i=0; i<cont; i++){
//        printf("%c", vetorzaum[i]);
//    }
//    printf("\n\n");


    int c=1;
    char achadas[nPalavras+1][nLinhas+nColunas];
    strcpy(achadas[0], "Palavras achadas:");


    for(i=0; i<nLinhas; i++){
        if(strstr(vetorzaum, lista[i]) != NULL){
            strcpy(achadas[c], lista[i]);
            c++;
        }
    }

    for(i=0; i<c; i++){
        printf("%s\n", achadas[i]);
    }

*/

    return 0;
}



//======================================================================================================



//Objetivo: 
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
int start(){

    int opcao;
    
    printf("Escolha o modo de criacao do caca palavras:\n\n");
    printf("\t - Criar matriz e palavras aleatorias (0)\n");
    printf("\t - Abrir arquivos de matriz e palavras (1)\n");
    printf("\t - Inserir dados manualmente (2)\n");

    scanf("%d", &opcao);
    //printf("\nVoce escolheu opcao ~%d~", opcao);

    return opcao;

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