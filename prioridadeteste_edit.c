/* Simulador de Escalonamento de Processos*/
#include <stdio.h>
#include <stdlib.h>
/* Estrutura */
struct processos {
    int id;                     /* Identifição do processo*/              
    int temp;                  /* Tempo de duração do processo*/
    int prioridade;           
    int execucao;               /* Tempo de execução do processo*/
    int espera;                 /* Tempo de espera do processo*/
    struct processos *prox;
};

/* Declarações de Protótipo de função */
struct processos *init_processos (int id, int temp, int prioridade);
void prioridade (struct processos *proc);
void listprocs (struct processos *proc);

int main (void) {

    struct processos *plist, *ptmp;
    plist       = init_processos(1, 10, 3);
    plist->prox = init_processos(2,  1, 1); ptmp = plist->prox;
    ptmp->prox  = init_processos(3,  2, 3); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(4,  1, 4); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(5,  5, 2);
    /* Simulações executadas*/
    listprocs(plist);
    prioridade(plist);

    while (plist != NULL) {
        ptmp = plist;
        plist = plist->prox;
        free(ptmp);
    };
    return(0);
};
/* Inicialização de entrada da lista de processos*/
struct processos *init_processos (int id, int temp, int prioridade) {
    struct processos *proc;
    proc = (struct processos*)malloc(sizeof(struct processos)); 
    if (proc == NULL) {
        printf("Erro Fatal: Falha Alocacao de memoria.\nFinalizar.\n");
        exit(1);
    };
    proc->id = id;
    proc->temp = temp;
    proc->prioridade = prioridade;
    proc->execucao = 0;
    proc->espera = 0;
    proc->prox = NULL;
    return(proc);
};

/* Listando Processos */
void listprocs (struct processos *proc) {
  struct processos *tmp = proc;
  printf("Processos criados com suas prioridades e tempos de execucao \n");
  printf("\n");
  while (tmp != NULL) {
    printf("Processo: %d\tPrioridade: %d\ttemp: %d\n", tmp->id, tmp->prioridade, tmp->temp);
    tmp = tmp->prox;
  };
  printf("\n\n");
 };
/* Simulação de Processos por Prioridade
 * Obs: O processo de menor valor de prioridade obtem
 * prioridade maior na fila de processos */
void prioridade (struct processos *proc) {
  int tempo, inicio, fim, maior;
  struct processos *copia, *tmpsrc, *tmp, *maiorprimeiro;
  printf("Escalonamento por Prioridade\n");
   printf("\n");

     /* Replicando Lista de Processos */
  tmpsrc = proc;
  copia = tmp = NULL;
  while (tmpsrc != NULL) {
    if (copia == NULL) {
    copia = init_processos(tmpsrc->id, tmpsrc->temp, tmpsrc->prioridade);
    tmp = copia;
    } else {
    tmp->prox = init_processos(tmpsrc->id, tmpsrc->temp, tmpsrc->prioridade);
    tmp = tmp->prox;
    };
    tmpsrc = tmpsrc->prox;
  };
  /* Programa Principal */
  tempo = 0;
  while (copia != NULL) {

          /* Localiza o proximo processo */
    maiorprimeiro = NULL;
    maior = copia->prioridade;
    tmp = copia->prox;
    tmpsrc = copia;
    while (tmp != NULL) {
    if (tmp->prioridade < maior) {
      maior = tmp->prioridade;
      maiorprimeiro = tmpsrc;
    };
    tmpsrc = tmp;
    tmp = tmp->prox;
    };
     if (maiorprimeiro == NULL) {
    /* Verifica se o primeiro processo possui maior prioridade */
    inicio = tempo;
    tempo += copia->temp;
    fim = tempo;
    printf("Processo: %d\ttemp: %d\tEspera: %d\tRetorno: %d\n", copia->id, tempo, inicio, fim);
    tmpsrc = copia->prox;
    free(copia);
    copia = tmpsrc;
    } else {
    /* Verifica se o primeiro processo não possui maior prioridade */
    tmp = maiorprimeiro->prox;
    inicio = tempo;
    tempo += tmp->temp;
    fim = tempo;
    printf("Processo: %d\ttemp: %d \tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
    maiorprimeiro->prox = tmp->prox;
    free(tmp);
    };
  };
  printf("\n\n");
};
