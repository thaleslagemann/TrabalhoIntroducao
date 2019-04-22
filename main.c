//
//  Trabalho 1 - Introdução à Ciência da Informação
//  Felipe Machado, Matheus Filipe, Thales Lagemann
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int dado[4], codificado[7], detectado[3], matrizG[7][4], i, j, matrizH[3][7], posicao = 0, selec, decimal;
	FILE *fp, *fp2;
	char resposta;

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
	
	printf("Inserir valores em <1> Binario ou <2> Decimal?\n");
	scanf("%d", &selec);

	switch (selec) {
		case 1:
			printf ("Entre com 4 bits um de cada vez:\n");
			for (i = 0; i < 4; ++i) {
				scanf("%d", &dado[i]);
			}
		break;

		case 2:
			printf("Entre com um numero de 0 a 15:\n");
			scanf("%d", &decimal);

			for (int i = 3; i >= 0; --i) {
				if(decimal % 2 == 0) {
					dado[i] = 0;
					decimal = decimal / 2;
				} else {
					dado[i] = 1;
					decimal = decimal / 2;
				}
			}
			printf("Numero convertido para binario:\n");
			for (int i = 0; i < 4; ++i) {
				printf("%d ", dado[i]);
			}
			printf("\n");
		break;

		default:
			exit(1);
		break;
	}

	

	for (i = 0; i < 7; i++) {
		codificado[i] = matrizG[i][0]*dado[0] + matrizG[i][1]*dado[1] + matrizG[i][2]*dado[2] + matrizG[i][3]*dado[3];
	}

	for (i = 0; i < 4; i++) {
		if (i == 2) {
			continue;
		}
		if (codificado[i] % 2 == 0) {
			codificado[i] = 0;
		} else {
			codificado[i] = 1;
		}
	}

	for (i = 0; i < 7; ++i) {
		printf("%d ", codificado[i]);
	}

	printf("\nDeseja simular um erro?\n");
	scanf(" %c", &resposta);

	switch(resposta) {
		case 's':
			printf("Digite o novo codigo, com o erro inserido:\n");
			for (int i = 0; i < 7; ++i)	{
				scanf("%d", &codificado[i]);
			}
		break;

		case 'n':
			printf("Nao foram inseridos erros.\n");
			exit(0);
		break;

		default:
			exit(1);
		break;
	}

	for (int i = 0; i < 3; ++i) {
		detectado[i] = 0;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 7; ++j) {
			detectado[i] = detectado[i] + (codificado[j] * matrizH[i][j]);
		}
		if (detectado[i] % 2 == 0) {
			detectado[i] = 0;
		} else {
			detectado[i] = 1;
		}
	}

	printf("\nDetecção de erros: \n");
	for (int i = 0; i < 3; ++i)	{
		printf("%d ", detectado[i]);
	}

	for (int i = 2; i >= 0; --i)	{
		posicao = posicao + detectado[i] * pow(2, i);
	}

	printf("\nErro na posicao: %d\n", posicao);

	if (codificado[posicao-1] == 1 ) {
		codificado[posicao-1] = 0;
	} else {
		codificado[posicao-1] = 1;
	}

	for (int i = 0; i < 7; ++i) {
		printf("%d ", codificado[i]);
	}
	printf("\n");

	for (int i = 0; i < 3; ++i) {
		detectado[i] = 0;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 7; ++j) {
			detectado[i] = detectado[i] + (codificado[j] * matrizH[i][j]);
		}
		if (detectado[i] % 2 == 0) {
			detectado[i] = 0;
		} else {
			detectado[i] = 1;
		}
	}

	for (int i = 0; i < 3; ++i) {
		printf("%d ", detectado[i]);
	}
	printf("\n");

	return 0;
}
