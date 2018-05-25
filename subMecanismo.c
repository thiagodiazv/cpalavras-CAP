#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    //ler tamanho da matriz
    int nColunas, nLinhas;
    printf("Informe o numero de linhas: ");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &nColunas);

    int i, j, cont=0;

    char matriz[10][10] = { {'a','b','c','d','e','f','g','h','i','j'},
                            {'a','b','c','d','e','f','g','h','i','j'},
                            {'a','b','c','d','e','f','r','a','t','o'},
                            {'a','b','c','d','e','f','g','h','i','j'},
                            {'a','b','c','d','e','f','g','h','i','j'},
                            {'a','b','c','d','e','f','g','h','i','j'},
                            {'a','g','a','l','o','f','g','h','i','j'},
                            {'a','a','c','d','e','f','g','h','i','j'},
                            {'a','t','c','d','e','f','p','a','t','o'},
                            {'a','o','c','d','e','f','g','h','i','j'} };

    char lista[10][20] = {"gato", "pato", "ganso", "marreco", "galo", "macaco", "rato", "coelho", "urubu", "cabra"};

    //char matriz[nLinhas][nColunas];
    //char lista[nLinhas][nLinhas+nColunas];


    char vetorzaum[nLinhas*nColunas*10];

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

//
    for(i=0; i<cont; i++){
        printf("%c", vetorzaum[i]);
    }
    printf("\n\n");
//


    int c=1;
    char achadas[nLinhas+1][nLinhas+nColunas];
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


    return 0;
}