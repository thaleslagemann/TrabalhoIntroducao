//
//  Trabalho 1 - Introdução à Ciência da Informação
//  Felipe Machado, Matheus Filipe, Thales Lagemann
//
#include <stdio.h>

int main()
{
	int dado[10], matrizG[7][4], i, j;
	FILE *fp;

	fp = fopen("matrizG", "r");

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 4; j++) {
			fscanf(fp, "%d", &matrizG[i][j]);
		}
	}
	
	printf (" Entre com 4 bits um de cada vez: \n");
	scanf("%d",&dado[0]);
	scanf("%d",&dado[1]);
	scanf("%d",&dado[2]);
	scanf("%d",&dado[3]);
	
	
	return 0;
}
