//
//  Trabalho 1 - Introdução à Ciência da Informação
//  Felipe Machado, Matheus Filipe, Thales Lagemann
//
#include <stdio.h>

int main()
{
	int dado[4], codificado[7], matrizG[7][4], i, j, matrizH[3][7];
	FILE *fp, *fp2;

	fp = fopen("matrizG", "r");
	fp2 = fopen("matrizH", "r");

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 4; j++) {
			fscanf(fp, "%d", &matrizG[i][j]);
			printf("%d ", matrizG[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 7; j++) {
			fscanf(fp2, "%d", &matrizH[i][j]);
			printf("%d ", matrizH[i][j]);
		}
		printf("\n");
	}
	
	printf (" Entre com 4 bits um de cada vez: \n");
	for (i = 0; i < 4; ++i) {
		scanf("%d", &dado[i]);
	}

	for (i = 0; i < 7; i++) {
		codificado[i] = matrizG[i][0]*dado[0]+matrizG[i][1]*dado[1]+matrizG[i][2]*dado[2]+matrizG[i][3]*dado[3];
		printf("\n");
	}

	if(codificado[0] %2 == 0) {
    	codificado[0] = 0;
    } else {
    	codificado[0] = 1;
    }

    if (codificado[1] %2 == 0) {
	    codificado[1] = 0;
    } else {
    	codificado[1] = 1;
    }

    if(codificado[3] %2 == 0) {
	    codificado[3] = 0;
    } else {
        codificado[3] = 1;
    }

	
    for (i = 0; i < 7; ++i) {
    	printf("%d ", codificado[i]);
    }

    return 0;
}
