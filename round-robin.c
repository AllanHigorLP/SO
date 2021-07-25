#include <stdlib.h> 
#include <stdio.h>  
#define tam 30 //número máximo de processos
 
int processos[tam];          
int quantProcessos;
int quantum;                
 
void processamento(){       
    int numero;
    int i;
    for (i=1; i<=quantProcessos; i++){
        printf("\nDigite o valor de quantum do processo %d:", i);
        scanf("%d", &numero);               //Leitura de valor inserido pelo usuario
        processos[i]= numero;                 //cada processo recebe o valor informado de quantum
    }
}
 
void fila(){
    int contadorFila=quantProcessos;            //contagem de processos que estão na fila
    int frenteFila = 1;                 //Primeira posição da fila
    while(contadorFila !=0){
        while(processos[frenteFila] <= 0){ //Tira processos que terminaram seu processamento
            frenteFila++;
            if(frenteFila>= quantProcessos) //Faz a rotação
                frenteFila=0;
        }
        printf("\n\nO processo %d possui %d quantum restantes", frenteFila , processos[frenteFila]);
        printf("\nPode ser processado ate %d quantum", quantum);
        processos[frenteFila] = processos[frenteFila] - quantum;       
        if( processos[frenteFila]<=0){
            printf("\nterminou de processar.\n");
            contadorFila--;
        }
        else{
            printf("\nE vai pro final da fila com %d quantum restantes.\n", processos[frenteFila]);
        }
        frenteFila++;                               //Atualiza primeira posição
            if(frenteFila>quantProcessos)    //Faz a rotação
                frenteFila=0;
        system("PAUSE");
    }
}
 
main(){
    printf("\nDigite o valor do quantum base para processamento: ");
    scanf("%d", &quantum);
    printf("\nNumero de processos: ");
    scanf("%d", &quantProcessos);
    processamento();
    fila();
    getch();
} 