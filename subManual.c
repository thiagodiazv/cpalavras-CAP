#include <stdio.h>
#include <string.h>

int main() {
    int MAX_COLUNAS, MAX_LINHAS;
	int i, j, k, l = 0, s = 0, p, n=0, g=0;
    int nPalavras;
    

    printf("Digite o numero de linhas do seu caca palavras:\n");
    scanf("%d", &MAX_LINHAS);
    printf("Digite o numero de colunas do seu caca palavras:\n");
    scanf("%d", &MAX_COLUNAS);
	char linhasCaca[MAX_LINHAS][MAX_COLUNAS];
	char colunasCaca[MAX_COLUNAS][MAX_LINHAS];
	char linhasInverso[MAX_LINHAS][MAX_COLUNAS];
	char colunasInverso[MAX_COLUNAS][MAX_LINHAS];

	for (i = 0; i < MAX_LINHAS; ++i) {
        printf("Digite as letras da %da linha\n", i+1);
		for (j = 0; j < MAX_COLUNAS; ++j) {
			scanf(" %c", &linhasCaca[i][j]);
		}
	}
		
	printf("\n");
		   
	for (i = 0; i < MAX_LINHAS; ++i) {
		for (j = 0; j < MAX_COLUNAS; ++j){
			colunasCaca[i][j] = linhasCaca[j][i];
			
		printf("\n");
		}
	}

	printf("\n");

	for (i = 0; i < MAX_LINHAS; ++i) {
		for (j = 0; j < MAX_COLUNAS; ++j){
			printf("%c ", linhasCaca[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < MAX_LINHAS; ++i) {
		for (j = 0; j < MAX_COLUNAS; ++j){
			printf("%c ", colunasCaca[i][j]);
			
		}
		printf("\n");
	}

	printf("\n");

    printf("Digite o numero de palavras que devem ser encontradas:\n");
    scanf("%d", &nPalavras);
	for (k = 0; k < nPalavras; k++){
		char word[30];
		printf("Digite a palavra: ");
		fflush (stdin);
		gets(word);
		fflush (stdin);
		if (strstr(linhasCaca[0], word) == NULL )
		 n = n+1;
		else if (strstr(colunasCaca[0], word) == NULL)
		 g = g+1;
		if (n == 1 && g == 1)
		printf("Palavra nao encontrada :(\n");
		else 
		printf("Palavra encontrada!\n");
		n = 0;
		g = 0;
	}	
	return 0;
}
