#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define N 9

// filas de prioridade

int fila1[N] = 	{256, 2, 4, 8, 16, 32, 64, 128, 256}; // a fila inicial ja foi preenchida para simular que a fila ja tinha sido preenchida por processos
int fila2[N] = 	{-1, -1, -1, -1, -1, -1, -1, -1, -1}; // os numeros identificam a quantidade de quantium necessario no processamento
int fila4[N] = 	{-1, -1, -1, -1, -1, -1, -1, -1, -1}; // o -1 indica um espaço vazio na lista
int fila8[N] = 	{-1, -1, -1, -1, -1, -1, -1, -1, -1};
int fila16[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
int fila32[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
int fila64[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

void atualizaFila(int variavel){ // uma função para atualizar os vetores e os mesmos se comportem como filas 

int j;
int x;
	switch (variavel)
	{
	   case 1:
	     for(int i = 0; i< N; i++){
	     	if(fila1[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila1[j] > 0 ){
	     				x = fila1[i];
	     				fila1[i] = fila1[j];
	     				fila1[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case 2:
	     for(int i = 0; i< N; i++){
	     	if(fila2[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila2[j] > 0 ){
	     				x = fila2[i];
	     				fila2[i] = fila2[j];
	     				fila2[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	   
	   case 4:
	     for(int i = 0; i< N; i++){
	     	if(fila4[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila4[j] > 0 ){
	     				x = fila4[i];
	     				fila4[i] = fila4[j];
	     				fila4[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case 8:
	     for(int i = 0; i< N; i++){
	     	if(fila8[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila8[j] > 0 ){
	     				x = fila8[i];
	     				fila8[i] = fila8[j];
	     				fila8[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	   
	   case 16:
	     for(int i = 0; i< N; i++){
	     	if(fila16[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila16[j] > 0 ){
	     				x = fila16[i];
	     				fila16[i] = fila16[j];
	     				fila16[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   case 32:
	     for(int i = 0; i< N; i++){
	     	if(fila32[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila32[j] > 0 ){
	     				x = fila32[i];
	     				fila32[i] = fila32[j];
	     				fila32[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	   break;
	
	   default:
	     for(int i = 0; i< N; i++){
	     	if(fila64[i] < 1){
	     		j = i + 1;
	     		for(j; j<N; j++){
	     			if(fila64[j] > 0 ){
	     				x = fila64[i];
	     				fila64[i] = fila64[j];
	     				fila64[j] = x;
	     				j = N;
					 }
				 }
			 }
		 }
	}
return;	
}


void processo1(){ // processo da fila 1
	printf("Processo 1\n");
	int i = 0;
	int cont = 0;
	while(i<3){ // a equipe acertou que a cada 3 processamentos da fila primaria as outras seriam processadas na sequencia
		if(fila1[i]!=-1){
			std::cout << "consumindo 1 quantium" << std::endl;
			if(fila1[i] - 1 > 0){
				fila2[cont] = fila1[i] - 1; // caso o processo necessite de mais de 1 quatium, ele é direcionado para filas que disponibilizarão mais quantium
				fila1[i] = -1;
				cont++;
			}
			else{
				fila1[i] = -1;
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
		if(fila2[i]!=-1){
			std::cout << "consumindo 2 quantium" << std::endl;
			if(fila2[i] - 2 > 0){
				fila4[cont] = fila2[i] - 2;
				fila2[i] = -1;
				cont++;
			}
			else{
				fila2[i] = -1;
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
		if(fila4[i]!=-1){
			std::cout << "consumindo 4 quantium" << std::endl;
			if(fila4[i] - 4 > 0){
				fila8[i] = fila4[i] - 4;
				fila4[i] = -1;
				cont++;
			}
			else{
				fila4[i] = -1;
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
		if(fila8[i]!=-1){
			std::cout << "consumindo 8 quantium" << std::endl;
			if(fila8[i] - 8 > 0){
				fila16[cont] = fila8[i] - 8;
				fila8[i] = -1;
				cont++;
			}
			else{
				fila8[i] = -1;
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
		if(fila1[i]!=-1){
			std::cout << "consumindo 16 quantium" << std::endl;
			if(fila16[i] - 16 > 0){
				fila32[cont] = fila16[i] - 16;
				fila16[i] = -1;
				cont++;
			}
			else{
				fila16[i] = -1;
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
		if(fila32[i]!=-1){
			std::cout << "consumindo 32 quantium" << std::endl;
			if(fila32[i] - 32 > 0){
				fila64[cont] = fila32[i] - 32;
				fila32[i] = -1;
				cont++;
			}
			else{
				fila32[i] = -1;
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
		if(fila64[i]!=-1){
			std::cout << "consumindo 64 quantium" << std::endl;
			if(fila64[i] - 64 > 0){
				fila64[i] = fila64[i] - 64;
			}
			else{
				fila64[i] = -1;
			}
		}
		i++;
	}
	atualizaFila(64);
	return;
}

void mostrarFilas(){  // função para mostrar o desenvolvimento das filas
	std::cout << "fila 1" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila1[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 2" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila2[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 4" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila4[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 8" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila8[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 16" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila16[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 32" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila32[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << "fila 64" << std::endl;
  	for(int i = 0; i < N; i++){
  		std::cout << fila64[i] <<" ";
	}
	std::cout << std::endl;
}


int main(){
      printf("Filas Multiplas\n");  
      mostrarFilas();
       printf("Inicio dos processos\n");
      int j=20;   // foi utilizado um valor de 20 para evitar problemas com erro de tempo
      while(j--){ // cada processamento é individual de cada fila, depois de cada processo é mostrado o desenvolvimento das filas 
      	processo1();
      	mostrarFilas();
		
		processo2();
		mostrarFilas();
		
		processo3();
		mostrarFilas();
		
		processo4();
		mostrarFilas();
		
		processo5();
		mostrarFilas();
		
		processo6();
		mostrarFilas();
		
		processo7();
		mostrarFilas();	
	  }
    return 0;
}
