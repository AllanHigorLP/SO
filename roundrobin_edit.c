#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//ROUD ROBIN PARECE COM O ALGORITMO DE ESCALONAMENTO GARANTIDO, COM UMA 
//DIFERENCA: O ESCALONAMENTO GARANTIDO GARANTE QUE CADA PROCESSO RODARA
//O MESMO TEMPO QUE OUTRO FAZENDO UM CALCULO DINAMICO DIVIDINDO O TEMPO
//DA CPU PELOS PROCESSOS ATIVOS, ENQUANTO O ROUND ROBIN DEFINE UM QUANTUM
//PARA FAZER O CONTROLE DE QUANTO TEMPO CADA PROCESSO TERA ACESSO A CPU


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

//RODA PROCESSOS SE ELES AINDA PRECISAREM USAR A CPU
void executarProcesso(int id, int tempo_de_execucao) {
    int time = tempo_de_execucao;
    int processTime = pTempo[id];
    
    
    //CASO O TEMPO DE EXECUCAO NECESSARIO PARA EXECUTAR O PROCESSO
    //SEJA MENOR QUE O TEMPO DISPONIBILIZADO PELO ESCALONADOR
    //O PROCESSO RODA PELO TEMPO QUE PRECISA SOMENTE
    if(time>pTempo[id]){
    	printf("Processo %d usara a CPU por %ds.\n",  pID[id], processTime);
    	printf("\n-- Rodando...\n");
        sleep(1);
    	pTempo[id] = 0;
    	printf("-- Ainda faltam %ds.\n-- Processo %d suspenso pelo escalonador.\n\n", pTempo[id],  pID[id]);
    }   
    
    //CASO O TEMPO NECESSARIO PARA EXECUTAR O PROCESSO
    //SEJA MAIOR QUE O TEMPO DISPONIBILIZADO PELO ESCALONADOR
    //O PROCESSO RODA SOMENTE O TEMPO QUE O ESCALONADOR PERMITIU
    else{
    	
    	pTempo[id] = pTempo[id] - time;
    	printf("Processo %d usara a CPU por %ds.\n",  pID[id], time);
        printf("\n-- Rodando...\n");
        sleep(2);
        printf("-- Ainda faltam %ds.\n-- Processo %d suspenso pelo escalonador.\n\n", pTempo[id],  pID[id]);
    
    }   
}

int main(){
    int tempo_de_execucao = TEMPO_MAX;
    srand(time(NULL));
    
    // GERA PROCESSOS
    for(int i = 0; i < N ; i ++) {
        criarProcesso(i);
    }
   
    int i = 0;
    //WHILE RODA ATE QUE NAO HAJAM MAIS PROCESSOS
    while(tam!=0){
        if (i>= tam){
    	    i = 0;
    	}
    	
    	//PRINTA PROCESSOS ATIVOS  	
    	printf("\nProcessos ainda ativos:");
    	for(int m= 0; m<tam; m++){
    	    printf("%d  ", pID[m]);
    	} 

    	//CALCULA O TEMPO DE EXECUCAO DE CADA PROCESSO COM BASE
    	//NOS PROCESSOS ATIVOS E NO N DE TEMPO PERMITIDO
    	
    	printf("\nTEMPO DE EXECUCAO DEFINIDO:%ds \n\n",tempo_de_execucao );
    	
    	//RODA PROCESSO
    	executarProcesso(i,tempo_de_execucao);
        
        //ENCERRA PROCESSO CASO O TEMPO DE EXECUCAO RESTANTE
        //SEJA IGUALA ZERO
    	if(pTempo[i]==0){
    	    printf("----------------------\n|Processo %d Finalizou|\n----------------------\n", pID[i]);
    	    excluirProcesso(i);
    	    tam = tam - 1;
    	    	
    	}
    	i++;
    	
    }
    
    return 0;
}
