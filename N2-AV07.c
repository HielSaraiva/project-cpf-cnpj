/*Alunos: Hiel Saraiva e Conrado Einstein*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void gerador_CPF(void);
int valida_CPF(char cpf[]);

void gerador_CNPJ(void);
int valida_CNPJ(char cnpj[]);

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

void gerador_CPF(void) {
	srand(time(NULL));
	int cont1, cont2, vetor_contador[11];
	
	for(cont1 = 0; cont1 <= 8; cont1 += 1) {

		int n = rand() % 10;
		vetor_contador[cont1] = n;
	}
	
	//Primeiro dígito significativo:
	int soma1 = 0, i1 = 10, res1, ver1;
	
	for(cont1 = 0; cont1 <= 8; cont1 += 1) {
		soma1 += vetor_contador[cont1]*i1;
		i1 -= 1;
	}
	res1 = soma1 % 11;
	
	if(res1 < 2){
		ver1 = 0;
	} else if (res1 >= 2){
		ver1 = 11 - res1;
	}
	vetor_contador[9] = ver1;
	
	//Segundo Dígito significativo:
	int soma2 = 0, i2 = 11, res2 , ver2;
	
	for(cont1 = 0; cont1 <= 9; cont1 += 1) {
		soma2 += vetor_contador[cont1]*i2;
		i2 -= 1;
	}
	res2 = soma2 % 11;
	
	if(res2 < 2) {
		ver2 = 0;
	}else if (res2 >= 2) {
		ver2 = 11 - res2;
	}
	vetor_contador[10] = ver2;
	
	printf("\nO CPF criado é: ");
	for(cont1 = 0 ; cont1 <= 8 ; cont1 += 1){
		if((cont1%3 == 0) && (cont1 != 0)){
			printf(".");
		}
		printf("%d",vetor_contador[cont1]);
	}
	printf("-%d%d\n", ver1, ver2);
}

int valida_CPF (char cpf[]){
	
	int cont1,vetor_contador[11], vetor_cpf[11], cont2 = 0;
	
	//Transformando o string em um vetor de inteiros
	for(cont1 = 0; cont1 <= 13; cont1 += 1) {
		if(cpf[cont1] != '.' && cpf[cont1] != '-') {
			vetor_cpf[cont2] = cpf[cont1] - '0';
			vetor_contador[cont2] = vetor_cpf[cont2];
			cont2 += 1;
		}
	}
	
	//Primeiro dígito significativo:
	int soma1 = 0, i1 = 10 , div1, res1, ver1;
	
	for(cont1 = 0; cont1 <= 8; cont1 += 1) {
		soma1 += vetor_contador[cont1]*i1;
		i1 -= 1;
	}
	res1 = soma1 % 11;
	
	if(res1 < 2){
		ver1 = 0;
	} else if (res1 >= 2){
		ver1 = 11 - res1;
	}
	vetor_contador[9] = ver1;
	
	//Segundo Dígito significativo:
	int soma2 = 0, i2 = 11, div2 , res2 , ver2;
	
	for(cont1 = 0; cont1 <= 9; cont1 += 1) {
		soma2 += vetor_contador[cont1]*i2;
		i2 -= 1;
	}
	res2 = soma2 % 11;
	
	if(res2 < 2) {
		ver2 = 0;
	}else if (res2 >= 2) {
		ver2 = 11 - res2;
	}
	vetor_contador[10] = ver2;
	
	int comp1 = 0;
	
	for(cont1 = 0 ; cont1 <= 10 ; cont1 += 1){
		if(vetor_contador[cont1] == vetor_cpf[cont1]){
			comp1 += 1;
		}
	}
	if(comp1 == 11){
		return 1;
	} else {
		return 0;
	}
}

void gerador_CNPJ(void) {
	srand(time(NULL));
	int cont1, cont2, vetor_contador[14];
	
	for(cont1 = 0; cont1 <= 11; cont1 += 1) {
		int n = rand() % 10;
		vetor_contador[cont1] = n;
	}
	
	//Primeiro dígito significativo:
	int soma1 = 0, i1 = 5, res1, ver1;
	
	for(cont1 = 0; cont1 <= 11; cont1 += 1) {
		soma1 += vetor_contador[cont1]*i1;
		i1 -= 1;
		if(i1 == 1){
			i1 = 9;
		}
	}
	res1 = soma1 % 11;
	
	if(res1 < 2){
		ver1 = 0;
	} else if (res1 >= 2){
		ver1 = 11 - res1;
	}
	vetor_contador[12] = ver1;
	
	//Segundo Dígito significativo:
	int soma2 = 0, i2 = 6, res2 , ver2;
	
	for(cont1 = 0; cont1 <= 12; cont1 += 1) {
		soma2 += vetor_contador[cont1]*i2;
		i2 -= 1;
		if(i2 == 1){
			i2 = 9;
		}
	}
	res2 = soma2 % 11;
	
	if(res2 < 2) {
		ver2 = 0;
	}else if (res2 >= 2) {
		ver2 = 11 - res2;
	}
	vetor_contador[13] = ver2;
	
	printf("\nO CNPJ criado é: %d%d.", vetor_contador[0], vetor_contador[1]);
	for(cont1 = 2; cont1 <= 7; cont1 += 1) {
		if(cont1%5 == 0) {
			printf(".");
		} 
		printf("%d", vetor_contador[cont1]);
	}
	printf("/");
	for(cont1 = 8; cont1 <= 11; cont1 += 1) {
		printf("%d", vetor_contador[cont1]);
	}
	printf("-%d%d", ver1, ver2);
}

int valida_CNPJ (char cnpj[]){
	
	int cont1,vetor_contador[14], vetor_cnpj[14], cont2 = 0;
	
	//Transformando o string em um vetor de inteiros
	for(cont1 = 0; cont1 <= 17; cont1 += 1) {
		if(cnpj[cont1] != '.' && cnpj[cont1] != '-' && cnpj[cont1] != '/') {
			vetor_cnpj[cont2] = cnpj[cont1] - '0';
			vetor_contador[cont2] = vetor_cnpj[cont2];
			cont2 += 1;
		}
	}
	
	//Primeiro dígito significativo:
	int soma1 = 0, i1 = 5, res1, ver1;
	
	for(cont1 = 0; cont1 <= 11; cont1 += 1) {
		soma1 += vetor_contador[cont1]*i1;
		i1 -= 1;
		if(i1 == 1){
			i1 = 9;
		}
	}
	res1 = soma1 % 11;
	
	if(res1 < 2){
		ver1 = 0;
	} else if (res1 >= 2){
		ver1 = 11 - res1;
	}
	vetor_contador[12] = ver1;
	
	//Segundo Dígito significativo:
	int soma2 = 0, i2 = 6, res2 , ver2;
	
	for(cont1 = 0; cont1 <= 12; cont1 += 1) {
		soma2 += vetor_contador[cont1]*i2;
		i2 -= 1;
		if(i2 == 1){
			i2 = 9;
		}
	}
	res2 = soma2 % 11;
	
	if(res2 < 2) {
		ver2 = 0;
	}else if (res2 >= 2) {
		ver2 = 11 - res2;
	}
	vetor_contador[13] = ver2;
	
	int comp1 = 0;
	
	for(cont1 = 0 ; cont1 <= 13 ; cont1 += 1){
		if(vetor_contador[cont1] == vetor_cnpj[cont1]){
			comp1 += 1;
		}
	}
	if(comp1 == 14){
		return 1;
	} else {
		return 0;
	}
}