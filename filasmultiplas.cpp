#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <time.h>

#define N 9
#define NIL -1

int FILA_1[N] = {2, 2, 4, 8, 16, 16, 256, 128, 256};
int FILA_2[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};
int FILA_4[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};
int FILA_8[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};
int FILA_16[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};
int FILA_32[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};
int FILA_64[N] = {NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL};

#define ID_FILA_1 1
#define ID_FILA_2 2
#define ID_FILA_4 4
#define ID_FILA_8 8
#define ID_FILA_16 16
#define ID_FILA_32 32
#define ID_FILA_64 64

void atualizaFila(int idFila){
int j;
int x;
	switch (idFila){
	   case ID_FILA_1:
	     for(int i = 0; i< N; i++){
	     	if(FILA_1[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_1[j] > 0 ){
	     				x = FILA_1[i];
	     				FILA_1[i] = FILA_1[j];
	     				FILA_1[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case ID_FILA_2:
	     for(int i = 0; i< N; i++){
	     	if(FILA_2[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_2[j] > 0 ){
	     				x = FILA_2[i];
	     				FILA_2[i] = FILA_2[j];
	     				FILA_2[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	   
	   case ID_FILA_4:
	     for(int i = 0; i< N; i++){
	     	if(FILA_4[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_4[j] > 0 ){
	     				x = FILA_4[i];
	     				FILA_4[i] = FILA_4[j];
	     				FILA_4[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case ID_FILA_8:
	     for(int i = 0; i< N; i++){
	     	if(FILA_8[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_8[j] > 0 ){
	     				x = FILA_8[i];
	     				FILA_8[i] = FILA_8[j];
	     				FILA_8[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	   
	   case ID_FILA_16:
	     for(int i = 0; i< N; i++){
	     	if(FILA_16[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_16[j] > 0 ){
	     				x = FILA_16[i];
	     				FILA_16[i] = FILA_16[j];
	     				FILA_16[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case ID_FILA_32:
	     for(int i = 0; i< N; i++){
	     	if(FILA_32[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_32[j] > 0 ){
	     				x = FILA_32[i];
	     				FILA_32[i] = FILA_32[j];
	     				FILA_32[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   default:
	     for(int i = 0; i< N; i++){
	     	if(FILA_64[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(FILA_64[j] > 0 ){
	     				x = FILA_64[i];
	     				FILA_64[i] = FILA_64[j];
	     				FILA_64[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	}
}


void processo1(){
	printf("Processo 1\n");
	int i = 0;
	int cont = 0;
	while(i<3){
		if(FILA_1[i]!=NIL){
			printf("Processando quantum 1");
			if(FILA_1[i] - 1 > 0){
				FILA_2[cont] = FILA_1[i] - 1;
				FILA_1[i] = NIL;
				cont++;
			}
			else{
				FILA_1[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(1);
	return;
}

void processo2(){
	printf("Processo 2\n");
	int i = 0;
	int cont = 0;
	while(i<3){
		if(FILA_2[i]!=NIL){
			printf("Processando quantum 2");
			if(FILA_2[i] - 2 > 0){
				FILA_4[cont] = FILA_2[i] - 2;
				FILA_2[i] = NIL;
				cont++;
			}
			else{
				FILA_2[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(2);
	return;
}

void processo3(){
	printf("Processo 3\n");
	int i = 0;
	int cont = 0;
	while(i<2){
		if(FILA_4[i]!=NIL){
			printf("Processando quantum 4");
			if(FILA_4[i] - 4 > 0){
				FILA_8[i] = FILA_4[i] - 4;
				FILA_4[i] = NIL;
				cont++;
			}
			else{
				FILA_4[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(4);
	return;
}

void processo4(){
	printf("Processo 4\n");
	int i = 0;
	int cont = 0;
	while(i<2){
		if(FILA_8[i]!=NIL){
			printf("Processando quantum 8");
			if(FILA_8[i] - 8 > 0){
				FILA_16[cont] = FILA_8[i] - 8;
				FILA_8[i] = NIL;
				cont++;
			}
			else{
				FILA_8[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(8);
	return;
}

void processo5(){
	printf("Processo 5\n");
	int i = 0;
	int cont = 0;
	while(i<1){
		if(FILA_1[i]!=NIL){
			printf("Processando quantum 16");
			if(FILA_16[i] - 16 > 0){
				FILA_32[cont] = FILA_16[i] - 16;
				FILA_16[i] = NIL;
				cont++;
			}
			else{
				FILA_16[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(16);
	return;
}

void processo6(){
	printf("Processo 6\n");
	int i = 0;
	int cont = 0;
	while(i<1){
		if(FILA_32[i]!=NIL){
			printf("Processando quantum 32");
			if(FILA_32[i] - 32 > 0){
				FILA_64[cont] = FILA_32[i] - 32;
				FILA_32[i] = NIL;
				cont++;
			}
			else{
				FILA_32[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(32);
	return;
}

void processo7(){
	printf("Processo 7\n");
	int i = 0;
	while(i<1){
		if(FILA_64[i]!=NIL){
			printf("Processando quantum 64");
			if(FILA_64[i] - 64 > 0){
				FILA_64[i] = FILA_64[i] - 64;
			}
			else{
				FILA_64[i] = NIL;
			}
		}
		i++;
	}
	atualizaFila(64);
	return;
}

void printarFilas(){
	printf("FILA %d\n", ID_FILA_1);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_1[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_2);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_2[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_4);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_4[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_8);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_8[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_16);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_16[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_32);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_32[i] <<" ";
	}

	printf("\nFILA %d\n", ID_FILA_64);
  	for(int i = 0; i < N; i++){
  		std::cout << FILA_64[i] <<" ";
	}
	std::cout << std::endl;
}


int main(){
      printarFilas();
      int j=10;
      while(j--){
      	processo1();
      	printarFilas();
		
	processo2();
	printarFilas();
	
	processo3();
	printarFilas();
	
	processo4();
	printarFilas();
	
	processo5();
	printarFilas();
	
	processo6();
	printarFilas();
	
	processo7();
	printarFilas();	

	sleep(2);
	}
    return 0;
}
