#include "outros.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct Outros {
    char local[MAX_TAM_LOC_OUTROS];
    char descricao[MAX_TAM_DESC]; 
    int nivelDif;
    int tempoEstimado;
};


Outros *criaOutros(char *local , char * descricao, int nivelDif){
    Outros * out;
    out = (Outros*)malloc(sizeof(Outros));
    
    out->nivelDif = nivelDif;
    out->tempoEstimado = 0;

    strcpy(out->local, local);
    strcpy(out->descricao, descricao);

    return out;
}


Outros *lerOutros(){
    char local[MAX_TAM_LOC_OUTROS];
    char descricao[MAX_TAM_DESC];
    int nivelDif;

    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]", descricao);
    scanf("%*[\n]");
    scanf("%[^\n]", local);
    scanf("%*[\n]");
    scanf("%d\n", &nivelDif);
   // printf("(%s) (%s)", descricao, local);

    Outros * out;
    out = criaOutros(local, descricao, nivelDif);

    return out;    
}



void setTempoEstimadoOutros(Outros *o){
    o->tempoEstimado = o->nivelDif;
}

int getTempoEstimadoOutros(void *dado){
    return (((Outros*)dado)->tempoEstimado);
}


char getTipoOutros(){
    return 'O';
}


void desalocaOutros(void *o){
    if(o){
        free(o);
    }
    // realizar uma tipagem?
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaOutros(void *dado){


    printf("- Tipo: Outros\n- Descricao: %s\n- Local: %s\n- Nivel de Dificuldade: %d\n- Tempo Estimado: %dh\n", ((Outros*)dado)->descricao, ((Outros*)dado)->local, ((Outros*)dado)->nivelDif, ((Outros*)dado)->tempoEstimado);

}