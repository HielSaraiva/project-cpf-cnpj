#include "src/headers/validador.h"

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
	
	//Primeiro digito significativo:
	int soma1 = 0, i1 = 10 , res1, ver1;
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