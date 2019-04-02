//  Felipe Machado, Matheus Filipe, Thales Lagemann
//
#include <stdio.h>

int main()
{
	int dado[10], matrizG[7][4], i, j, matrizH[3][7];
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
	scanf("%d",&dado[0]);
	scanf("%d",&dado[1]);
	scanf("%d",&dado[2]);
	scanf("%d",&dado[3]);
	
	
	return 0;
}
