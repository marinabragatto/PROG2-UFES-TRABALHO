#include "ticket.h"

#include "software.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct Ticket {
    char cpf[MAX_TAM_CPF];
    void * tipo;// Armazenar um ponteiro para um tipo específico de ticket (ex: Software, Manuntencao, etc.)
    char id[MAX_TAM_ID];
    char fim[15];
    int finalizado;


    // Funções de callback
    func_ptr_tempoEstimado getTempo;
    func_ptr_tipo getTipo;
    func_ptr_notifica notifica;
    func_ptr_desaloca desaloca;

};

Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
    
    Ticket * ticket;


    ticket = (Ticket*)malloc(sizeof(Ticket));
    if(ticket == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    ticket->tipo = dado;
    
    strcpy(ticket->cpf, cpfSol);
    strcpy(ticket->fim, "Aberto");
    ticket->finalizado = 0;

    ticket->getTempo = getTempo;
    ticket->getTipo = getTipo;
    ticket->notifica = notifica;
    ticket->desaloca = desaloca;
    
    return ticket;

}


void setIDTicket(Ticket *d, char *id){
    strcpy(d->id, id);
}


void finalizaTicket(Ticket *t){
    strcpy(t->fim, "Finalizado");
    t->finalizado = 1;

}


char *getCPFSolicitanteTicket(Ticket *t){
    return t->cpf;
}


int getTempoEstimadoTicket(Ticket *t){
    return t->getTempo(t->tipo);
}

char getTipoTicket(Ticket *t){
    return t->getTipo(t->tipo);
}


char getStatusTicket(Ticket *t){
    if(t->finalizado == 1){   
        return 'F';
    }
    else if(t->finalizado == 0){
        return 'A';
    }
    return 0;
}

void desalocaTicket(Ticket *doc){
    if(doc){
        if(doc->tipo){
            doc->desaloca(doc->tipo);
        }
        free(doc);
    }
}

void notificaTicket(Ticket *doc){
    printf("---------TICKET-----------\n");
    printf("- ID: %s\n- Usuario solicitante: %s\n", doc->id, doc->cpf);
    doc->notifica(doc->tipo);
    if(getStatusTicket(doc) == 'F'){
        printf("- Status: Finalizado\n");
    }
    if(getStatusTicket(doc) == 'A'){
        printf("- Status: Aberto\n");
    }
    
    printf("-------------------------\n");
}
