#include "fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_QTD_ELEMT 5

struct Fila {
    int qtd;
    int capacidade;
    Ticket ** elementos;
};

Fila *criaFila(){
    Fila * fila;

    fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }

    fila->elementos = (Ticket**)malloc(sizeof(Ticket*)*MIN_QTD_ELEMT);
    if(fila->elementos == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    fila->capacidade = MIN_QTD_ELEMT;
    fila->qtd = 0;

    return fila;
}

void desalocaFila(Fila *f){
    int i = 0;
    if(f){
        if(f->elementos){
            for(i = 0; i < f->qtd; i++){
                desalocaTicket(f->elementos[i]);
            }
            
            free(f->elementos);
        }

        free(f);
    }
}

void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
        Ticket * ticket;
        ticket = criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);
        
        if(f->qtd >= f->capacidade){
            f->elementos = (Ticket**)realloc(f->elementos, sizeof(Ticket*)*(f->capacidade+MIN_QTD_ELEMT));
            f->capacidade += MIN_QTD_ELEMT;
        }
        char id[MAX_TAM_ID];
        sprintf(id, "Tick-%d", f->qtd+1);

        setIDTicket(ticket,id);
        
        f->elementos[f->qtd] = ticket;
        f->qtd++;
        
        return;
}

int getQtdTicketsNaFila(Fila *f){
    int i = 0;
    return f->qtd;

}


int getQtdTicketsPorStatusNaFila(Fila *f, char status){
    int i = 0, soma = 0;
    for(i = 0; i < f->qtd; i++){
        if (getStatusTicket(f->elementos[i]) == status ){
            soma += 1;
        }        
    }
    return soma;
}    

Ticket *getTicketNaFila(Fila *f, int i){
    return f->elementos[i];

}

void notificaFila(Fila *f){
    int i = 0; 

    for(i = 0; i < f->qtd; i++){
        notificaTicket(f->elementos[i]);
    }

}