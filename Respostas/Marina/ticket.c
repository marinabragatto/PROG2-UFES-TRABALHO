#include "ticket.h"

#include "software.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#define MAX_TAM_ID 11
//#define MAX_TAM_CPF 15

/**
 * Estrutura de um Ticket contendo os parametros comuns entre todos os tipos de Tickets e um tipo genérico.
 */
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



/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
    
    Ticket * ticket;


    ticket = (Ticket*)malloc(sizeof(Ticket));

    ticket->tipo = dado;
    
    strcpy(ticket->cpf, cpfSol);
    strcpy(ticket->fim, "Aberto");
    ticket->finalizado = 0;

    ticket->getTempo = getTempo;
    ticket->getTipo = getTipo;
    ticket->notifica = notifica;
    ticket->desaloca = desaloca;
   // (getTempo(dado))
    
    return ticket;

}

/**
 * @brief Atribui um ID a um ticket
 * @param d Ticket inicializado
 * @param id ID a ser atribuido ao ticket
 */
void setIDTicket(Ticket *d, char *id){
    strcpy(d->id, id);
}

/**
 * @brief Finaliza um ticket
 * @param t Ticket inicializado
 */
void finalizaTicket(Ticket *t){
    strcpy(t->fim, "Finalizado");
    t->finalizado = 1;

}

/**
 * @brief Recupera o CPF de quem solicitou a abertura do ticket
 * @param t Ticket inicializado
 * @return CPF de quem solicitou a abertura do ticket
 */
char *getCPFSolicitanteTicket(Ticket *t){
    return t->cpf;
}

/**
 * @brief Recupera o tempo estimado para resolver um ticket
 * @param t Ticket inicializado
 * @return tempo estimado para resolver um ticket
 */
int getTempoEstimadoTicket(Ticket *t){
    return t->getTempo(t->tipo);
}

/**
 * @brief Recupera o tipo de um ticket
 * @param t Ticket inicializado
 * @return tipo do Ticket
 */
char getTipoTicket(Ticket *t){
    return t->getTipo(t->tipo);
}

/**
 * @brief Recupera o status de um ticket
 * @param t Ticket inicializado
 * @return status do Ticket
 */
char getStatusTicket(Ticket *t){
    if(t->finalizado == 1){   
        return 'F';
    }
    else if(t->finalizado == 0){
        return 'A';
    }
}

/**
 * @brief  Desaloca um ticket da memória
 * @param doc estrutura do tipo Ticket que deve ser liberada da memória
 */
void desalocaTicket(Ticket *doc){
    if(doc){
        if(doc->tipo){
            doc->desaloca(doc->tipo);
        }
        free(doc);
    }
}

/**
 * @brief  Notifica (imprime) um ticket
 * @param doc Ticket a ser notificado
 */
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
