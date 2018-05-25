#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//typedef
typedef struct{
    int nColunas;
    int nLinhas;
    int nPalavras;
    char matriz[100][100];
    char lista[100][100];
    char vetorzaum[1000000];
    char achadas[101][100];
} infos;



//prototipo
int subStart();
void subDimencoes();
void subLeitura();
void subImprimir();
void subAleat();
void subMecanismo();
void subManual();
void subLinear();


//main!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(int argc, char *argv[]){

    int x=subStart();

    //printf("\nopcao escolida = %d\n\n", x);

    infos val;

    subDimencoes(&val);

    //printf("\nnLinhas %d\nnColunas %d\nnPalavras %d\n\n", val.nLinhas, val.nColunas, val.nPalavras);


    if(x==0){
        subAleat(&val);
    }
    else if(x==1){
        subLeitura(&val);
    }
    else if(x==2){
        subManual(&val);
    }

    //subImprimir(&val);

    subLinear(&val);

    subMecanismo(&val);

    return 0;
}



//======================================================================================================



//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
int subStart(){

    int opcao;
    printf("Escolha o modo de criacao do caca palavras:\n");
    printf("\t - Criar matriz e palavras aleatorias (0)\n");
    printf("\t - Abrir arquivos de matriz e palavras (1)\n");
    printf("\t - Inserir dados manualmente (2)\n\n");
    scanf("%d", &opcao);

    return opcao;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subDimencoes(infos *p){

    //ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &p->nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &p->nColunas);
    //numero de palavras
    printf("Informe o numero de palavras: ");
    scanf("%d", &p->nPalavras);


    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subLeitura(infos *p){

    //contadores
    int i, j;

    //ler matriz
    FILE *arquivoX;
    char *nome = "matriz.txt";
    arquivoX = fopen(nome, "r");

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            fscanf(arquivoX ,"%c ", &p->matriz[i][j]);
        }
    }
    fclose(arquivoX);

    //ler lista de palavras
    //LIMITAR TAMANHO??????????????????????????????????????????
    nome = "palavras.txt";
    arquivoX = fopen(nome, "r");
    int c=0;

    while(!feof(arquivoX)){
        fscanf(arquivoX, "%s", &p->lista[c++]);
    }
    fclose(arquivoX);

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subImprimir(infos *p){

    int i, j;

    printf("\nMatriz de Palavras\n");
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            printf("%c%c", p->matriz[i][j], j==p->nColunas-1?'\n':' ');
        }
    }

    printf("\nLista de Palavras:\n");
    for(i=0; i<p->nPalavras; i++){
        printf("%s\n", p->lista[i]);
    }

    printf("\n");
    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subAleat(infos *p){

    //contadores
    int i, j;

    srand(time(NULL));

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->matriz[i][j]=(rand()%26)+(65);
        }
    }

    for(i=0; i<p->nPalavras; i++){
        for(j=0; j<(p->nColunas+p->nLinhas); j++){
            p->lista[i][j]=(rand()%26)+(65);
        }
    }

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subManual(infos *p){

  int i, j;

  for (i = 0; i <p->nLinhas; ++i) {
        printf("Digite as letras da %da linha\n", i+1);
    for (j = 0; j <p->nColunas; ++j) {
      scanf(" %c", &p->matriz[i][j]);
    }
  }
  printf("\n");
  //QUE CARAKAS?????????????????
  for (i=0; i<p->nPalavras; i++){
		printf("Digite a %da palavra: ", i+1);
		fflush (stdin);
		gets(p->lista[i]);
		fflush (stdin);
	}

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subLinear(infos *p){

    int i, j, cont=0;

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->vetorzaum[cont] = p->matriz[i][j];
            cont++;
        }
        p->vetorzaum[cont] = '\n';
        cont++;
    }
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->vetorzaum[cont] = p->matriz[j][i];
            cont++;
        }
        p->vetorzaum[cont] = '\n';
        cont++;
    }
    p->vetorzaum[cont] = '\0';
/*
    for(i=0; i<cont; i++){
        printf("%c", p->vetorzaum[i]);
    }
    printf("\n\n");
*/
    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subMecanismo(infos *p){

    int i, c=1;
    strcpy(p->achadas[0], "Palavras achadas:");

    for(i=0; i<p->nLinhas; i++){
        if(strstr(p->vetorzaum, p->lista[i]) != NULL){
            strcpy(p->achadas[c], p->lista[i]);
            c++;
        }
    }
    printf("c eh %d\n", c);

    for(i=0; i<c; i++){
        printf("%s\n", p->achadas[i]);
    }

    return;
}
