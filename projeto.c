/*Alunos: Hiel Saraiva e Conrado Einstein*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "validador.h"
#include "gerador.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opc;
	char v[20];
	
	do {
		printf("\nBem-vindo ao validador de CPF/CNPJ do Conrado e do Hiel\n\n");
		printf("1- Verifica se um dado CPF ou CNPJ é válido ou não\n");
	 	printf("2- Gera um CPF\n");
	 	printf("3- Gera um CNPJ\n");
		printf("0- Para sair do programa\n\n");
		scanf("%d", &opc);
		
		switch (opc) {
			case 0:
				printf("Você escolheu sair....\n\n");
				break;
			case 1:
				printf("\nDigite um CPF ou CNPJ usando a respectiva forma(XXX.XXX.XXX-XX OU XX.XXX.XXX/XXXX-XX): ");
				fflush(stdin);
				scanf("%s", v);
				if(strlen(v) == 14) {
					if(valida_CPF(v) == 1) {
						printf("O CPF é válido!!\n");
					} else {
						printf("O CPF é inválido!!\n");
					}
				} else if(strlen(v) == 18) {
					if(valida_CNPJ(v) == 1) {
						printf("O CNPJ é válido!!\n");
					} else {
						printf("O CNPJ é inválido!!\n");
					}
				}
				break;
			case 2:
				gerador_CPF();
				break;
			case 3:
				gerador_CNPJ();
				break;	
		}
	} while(opc != 0);	
	system("pause");
	return 0;
}