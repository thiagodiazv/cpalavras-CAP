#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    //ler tamanho da matriz
    int nColunas, nLinhas;
    printf("Informe o numero de linhas:");
    scanf("%d", &nLinhas);
    printf("Informe o numero de colunas:");
    scanf("%d", &nColunas);

    int i, j, cont=0;

    char matriz[nLinhas][nColunas]; /*= { {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','b','c','d','e','f','g','h','i','j'},
                                        {'a','g','a','g','o','f','g','h','i','j'},
                                        {'a','a','c','d','e','f','g','h','i','j'},
                                        {'a','t','c','d','e','f','p','a','t','o'},
                                        {'a','o','c','d','e','f','g','h','i','j'} };*/

    char lista[nLinhas][nLinhas+nColunas]; //= {"gato", "pato", "ganso", "marreco", "galo", "macaco", "rato", "coelho", "urubu", "cabra"};

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
/*
    for(i=0; i<cont; i++){
        printf("%c", vetorzaum[i]);
    }
*/
    int c=1;
    char achadas[nLinhas+1][10000];
    strcpy(achadas[0], "Palavras achadas: ");


    for(i=0; i<nLinhas; i++){
        //tet = strstr(vetorzaum, lista[i]);
        //printf("%s\n", tet);
        if(strstr(vetorzaum, lista[i]) != NULL){
            strcat(achadas[c++], lista[i]);
        }
    }



    
    for(i=0; i<c; i++){
        printf("%s\n", achadas[i]);
    }


    return 0;
}