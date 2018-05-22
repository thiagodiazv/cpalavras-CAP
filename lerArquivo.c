#include <stdio.h>
#include <string.h>

int main(){

//ler tamanho da matriz
    int nColunas, nLinhas;
    printf("Informe o numero de linhas:");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas:");
    scanf("%d", &nColunas);
    
//ler lista de palavras
    char lista[30][50];

    int i, j, c=0;
    
    FILE *arquivo1;

    char *nome = "palavras.txt";

    arquivo1 = fopen(nome, "r");

    while(!feof(arquivo1)){
        fscanf(arquivo1, "%s", &lista[c++]);
    }

    for(i=0; i<c; i++){
        printf("%s\n", lista[i]);
    }

    fclose(arquivo1);


printf("\n\n\n");
//ler matriz


    char matriz[100][100];

    FILE *arquivo2;

    nome = "matriz.txt";

    arquivo2 = fopen(nome, "r");

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            fscanf(arquivo2 ,"%c", &matriz[i][j]);
        }
    }

    for(i=0; i<nLinhas; i++){
        for(j=0; j<nColunas; j++){
            printf("%c%c", matriz[i][j], j==nColunas-1?'\n':' ');
        }
    }

    fclose(arquivo2);


    return 0;
}