#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "src/headers/gerador.h"

void gerador_CPF(void) {
	srand((unsigned int)time(NULL));
	int cont1, vetor_contador[11];
	
	for(cont1 = 0; cont1 <= 8; cont1 += 1) {

		int n = rand() % 10;
		vetor_contador[cont1] = n;
	}
	
	//Primeiro digito significativo:
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
	
	//Segundo digito significativo:
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
	
	printf("\nO CPF criado foi: ");
	for(cont1 = 0 ; cont1 <= 8 ; cont1 += 1){
		if((cont1%3 == 0) && (cont1 != 0)){
			printf(".");
		}
		printf("%d",vetor_contador[cont1]);
	}
	printf("-%d%d\n", ver1, ver2);
}

void gerador_CNPJ(void) {
	srand((unsigned int)time(NULL));
	int cont1, vetor_contador[14];
	
	for(cont1 = 0; cont1 <= 11; cont1 += 1) {
		int n = rand() % 10;
		vetor_contador[cont1] = n;
	}
	
	//Primeiro digito significativo:
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
	
	//Segundo digito significativo:
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
	
	printf("\nO CNPJ criado foi: %d%d.", vetor_contador[0], vetor_contador[1]);
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