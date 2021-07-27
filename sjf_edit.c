#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5             // Quantidade de processos
#define MAX_TEMPO_PROCESSO 15      // Quantidade maxima de tempo que um processo pode durar
#define TEMPO_MAX 10    // Quantidade maxima de tempo que cada processo pode executar por vez

int pTempo[N];    // Lista de tempo para execucao de cada processo
char pID[N];      // Lista de ID dos processos 
int tam = 0;        // Tamanho lista de processos

// Cria processos
void criarProcesso (int aux) {
        tam++;
        pTempo[aux] = rand()%MAX_TEMPO_PROCESSO + 1;
        pID[aux] = aux;
        printf("Processo %d criado. Tempo requerido para execucao: %ds. \n\n", pID[aux], pTempo[aux]); 
}

//EXCLUI PROCESSOS CASO ELES TENHAM SIDO CONCLUIDOS
void excluirProcesso(int id){
    for(int i = id; i<tam; i++){
	pTempo[i] = pTempo[i+1];
	pID[i] = pID[i+1];
    }
    pTempo[tam-1] = 0;
}

void organizarTempo(){
    int aux1, aux2, aux3; 
    for(int i=0;i<N;i++){
    	for(int j=0; j<N;j++){
	    if(pTempo[i] < pTempo[j]){
	    	aux1 = pTempo[i];  aux2 = pID[i];
	    	pTempo[i] = pTempo[j];
         	pID[i] = pID[j];
         	
         	pTempo[j] = aux1;
         	pID[j] = aux2;
    	    }
    	}
    }
}

//RODA PROCESSOS SE ELES AINDA PRECISAREM USAR A CPU
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
    
    organizarTempo();
    
    printf("Lista de processos organizada por menor tempo:\n");
    for(int i = 0; i < N ; i ++) {
        printf("Processo %d - Tempo %d\n", pID[i], pTempo[i]);
    }
    
    
   int i = 0;
    //WHILE RODA ATE QUE NAO HAJAM MAIS PROCESSOS
    while(tam!=0){
       
    	//RODA PROCESSO
    	executarProcesso(i);
        
        //ENCERRA PROCESSO APOS RODAR
    	if(pTempo[i]==0){
    	    printf("----------------------\n|Processo %d Finalizou|\n----------------------\n\n", pID[i]);
    	    excluirProcesso(i);
    	    tam = tam - 1;   	
    	}
    	
    	
    }
    
    return 0;
}
