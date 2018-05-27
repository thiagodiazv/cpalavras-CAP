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
    char transposta[100][100];
    char lista[100][100];
    char randW[100][100];
    char vetor[1000000];
    char faltam[100][100]; 
} infos;


//prototipo
int subStart();
void subDimencoes();
void subLeitura();
void subImprimir();
void subAleat();
void subPalavras(); 
void subMecanismo();
void subManual();
void subLinear();


//main!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(int argc, char *argv[]){

    int x=subStart();

    infos valores;

    if(x==0){
        subDimencoes(&valores);
        subAleat(&valores);
        subPalavras(&valores);
        subImprimir(&valores);
    }
    else if(x==1){
        subLeitura(&valores);
        subLinear(&valores);
        subMecanismo(&valores);
    }
    else if(x==2){
        subDimencoes(&valores);
        subManual(&valores);
        subLinear(&valores);
        subMecanismo(&valores);
    }
    else{
        printf("opcao nao valida!");
        return 0;
    }
    
    return 0;
}



//=========================================================



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
//-nome1:
void subDimencoes(infos *p){

    //ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &p->nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &p->nColunas);
    //numero de palavras
    printf("Informe o numero de palavras: ");
    scanf("%d", &p->nPalavras);
    printf("\n");

    return;
}


//Objetivo: 
//Parâmetros formais
//-nome1:
void subAleat(infos *p){

    //contadores
    int i, j;

    srand(time(NULL));

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->matriz[i][j]=(rand()%26)+(65);
        }
    }

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->transposta[j][i]=p->matriz[i][j];
        }
    }

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:
void subPalavras(infos *p){

    srand(time(NULL));

    int i, j, indL, indC;

    for(i=0; i<p->nPalavras; i++){
        
        indL=(rand()%p->nLinhas)+1;
        indC=(rand()%p->nColunas)+1;

        for(j=0; j<p->nPalavras; j++){    
            if(i%2==0){
                p->randW[i][j] = p->matriz[i][indL];
                indL++;
            }
            else{
                p->randW[i][j] = p->transposta[i][indC];
                indC++;
            }
        }
    }

    return;
}


//Objetivo: Ler a matriz e as palavras a partir de arquivos de texto.
//Parâmetros formais
//-nome1:
void subLeitura(infos *p){

    //contadores
    int i, j;

    char nome[2][1000];

    fflush(stdin);
    printf("Insira o nome do arquivo da matriz (com .txt):\n");
    gets(nome[0]);
    printf("Insira o nome do arquivo da lista de palavras (com .txt):\n");
    gets(nome[1]);    
    fflush(stdin);

    //ler matriz
    FILE *arquivoX;

    arquivoX = fopen(nome[0], "r");

    fscanf(arquivoX, "%d", &p->nLinhas);
    
    fscanf(arquivoX, "%d", &p->nColunas);

    fgetc(arquivoX);

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            fscanf(arquivoX ,"%c ", &p->matriz[i][j]);
        }
    }
    fclose(arquivoX);


    //ler lista de palavras
    arquivoX = fopen(nome[1], "r");

    fscanf(arquivoX, "%d", &p->nPalavras);
    
    for(i=0; i<p->nPalavras; i++){
        fscanf(arquivoX, "%s", &p->lista[i]);
    }
    fclose(arquivoX);
    
    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:
void subManual(infos *p){

    int i, j;

    for (i=0; i<p->nLinhas; i++) {
        printf("Digite as letras da %da linha\n", i+1);
        for (j=0; j <p->nColunas; j++) {
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
//-nome1:
void subLinear(infos *p){

    int i, j, cont0=0;

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->vetor[cont0] = p->matriz[i][j];
            cont0++;
        }
        //p->vetor[cont0] = '\n';
        //cont0++;
    }
    for(i=0; i<p->nColunas; i++){
        for(j=0; j<p->nLinhas; j++){
            p->vetor[cont0] = p->matriz[j][i];
            cont0++;
        }
        //p->vetor[cont0] = '\n';
        //cont0++;
    }
    p->vetor[cont0] = '\0';

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:
void subMecanismo(infos *p){

    int i, c=0, flag=1;

    for(i=0; i<p->nLinhas; i++){
        if(strstr(p->vetor, p->lista[i]) == NULL){
            strcpy(p->faltam[c], p->lista[i]);
            c++;
            flag=0;
        }
    }

    if(flag==1){
        printf("\nCaca palavras contem todas as palavras!!\n");
    }
    else if (flag==0){
        printf("\nCaca palavras NAO contem todas as palavras!!\n\nPalavras nao achadas:\n");
        for(i=0; i<c; i++){
            printf("%s\n", p->faltam[i]);
        }
    }

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:
void subImprimir(infos *p){

    int i, j;

    printf("\nMatriz de Palavras Aleatorias:\n");
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            printf("%c%c", p->matriz[i][j], j==p->nColunas-1?'\n':' ');
        }
    }

    printf("\nLista de Palavras Aleatorias:\n");
    for(i=0; i<p->nPalavras; i++){
        printf("%s\n", p->randW[i]);
    }

    printf("\n");

    return;
}