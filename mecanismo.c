#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define dim 10

int main(){

    int i, j, cont=0;

    char achadas[dim+1][10000];
    strcpy(achadas[0], "Palavras achadas: ");

    char matriz[dim][dim] = { {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','b','c','d','e','f','g','h','i','j'},
                              {'a','g','a','g','o','f','g','h','i','j'},
                              {'a','a','c','d','e','f','g','h','i','j'},
                              {'a','t','c','d','e','f','p','a','t','o'},
                              {'a','o','c','d','e','f','g','h','i','j'} };

    char lista[dim][20] = {"gato", "pato", "ganso", "marreco", "galo", "macaco", "rato", "coelho", "urubu", "cabra"};

    char vetorzaum[dim*1000];

    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            vetorzaum[cont] = matriz[i][j];
            cont++;       
        }
        vetorzaum[cont] = '\n';
        cont++;
    }
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
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
    printf("\n\nPalavras achadas\n");

    char *tet;

    for(i=0; i<dim; i++){
        tet = strstr(vetorzaum, lista[i]);
        //printf("%s\n", tet);
        strcat(achadas[i+1], tet);
    }


/*
    
    for(i=0; i<dim; i++){
        printf("%s\n", lista[i]);
    }
*/

    return 0;
}