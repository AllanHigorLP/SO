#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define N 5             		// Quantidade de processos
#define MAX_TEMPO_PROCESSO 15     	// Quantidade maxima de tempo que um processo pode durar
#define TEMPO_MAX 10    		// Quantidade maxima de tempo que cada processo pode executar por vez
#define PRIORIDADE  10    		//PRIORIDADE DO PROCESSO

int pTempo[N];    			// Lista de tempo para execucao de cada processo
int pID[N]; 				// Lista de ID dos processos
int pPrioridade[N];     		// Lista de Prioridade dos processos 
int tam = 0;        			// Tamanho lista de processos

// Cria processos
void criarProcesso (int aux) {
        tam++;
        pTempo[aux] = rand()%MAX_TEMPO_PROCESSO + 1;
        pPrioridade[aux] = rand()%PRIORIDADE + 1;
        pID[aux] = aux;
        printf("Processo %d criado com prioridade %d. Tempo requerido para execucao: %ds. \n\n", pID[aux],pPrioridade[aux], pTempo[aux]); 
}

//EXCLUI PROCESSOS CASO ELES TENHAM SIDO CONCLUIDOS
void excluirProcesso(int id){
    for(int i = id; i<tam; i++){
	pTempo[i] = pTempo[i+1];
	pID[i] = pID[i+1];
    }
    pTempo[tam-1] = 0;
}

//ORGANIZA A LISTA DE PROCESSOS POR PRIORIDADE
void organizarPrioridade(){
    int aux1, aux2, aux3; 
    for(int i=0;i<N;i++){
    	for(int j=0; j<N;j++){
	    if(pPrioridade[i] > pPrioridade[j]){
	    	aux1 = pTempo[i]; aux2 = pPrioridade[i]; aux3 = pID[i];
	    	pTempo[i] = pTempo[j];
        	pPrioridade[i] = pPrioridade[j];
         	pID[i] = pID[j];
         	
         	pTempo[j] = aux1;
        	pPrioridade[j] = aux2;
         	pID[j] = aux3;
    	    }
    	}
    }
}
//RODA PROCESSOS
void executarProcesso(int id) {
    int processTime = pTempo[id];
    
    printf("Processo %d usara a CPU por %ds.\n",  pID[id], processTime);
    	printf("\n-- Rodando...\n");
        sleep(1);
    	pTempo[id] = 0;   
}

int main(){
    int tempo_de_execucao = TEMPO_MAX;
    srand(time(NULL));
    
    // GERA PROCESSOS
    for(int i = 0; i < N ; i ++) {
        criarProcesso(i);
    }
	
    //organiza os processos por prioridade
    organizarPrioridade();
	
    //printa a lista de processos organizada por prioridade
    printf("Lista de processos organizada por prioridade:\n");
    for(int i = 0; i < N ; i ++) {
        printf("Processo %d - Prioridade %d\n", pID[i], pPrioridade[i]);
    }
    
    int i = 0;

    //WHILE RODA ATE QUE NAO HAJAM MAIS PROCESSOS
    while(tam!=0){
        if (i>= tam){
    	    i = 0;
    	}
  
    	//RODA PROCESSO
    	executarProcesso(i);
        
        //ENCERRA PROCESSO APOS RODAR
    	if(pTempo[i]==0){
    	    printf("----------------------\n|Processo %d Finalizou|\n----------------------\n\n", pID[i]);
    	    excluirProcesso(i);
    	    tam = tam - 1;   	
    	}
    	i++;
    	
    }
    
    return 0;
}
    
