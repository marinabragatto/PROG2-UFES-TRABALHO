#include "fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_QTD_ELEMT 5

/**
 * Uma estrutura que armazenará os tickets que serão atribuidos aos técnicos.
 *
 * A estrutura seguirá a ideia de uma Fila, isto é, primeiro ticket deve ser o primeiro a ser tratado.
 */
struct Fila {
    int qtd;
    int capacidade;
    Ticket ** elementos;
};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila(){
    Fila * fila;

    fila = (Fila*)malloc(sizeof(Fila));

    fila->elementos = (Ticket**)malloc(sizeof(Ticket*)*MIN_QTD_ELEMT);
    fila->capacidade = MIN_QTD_ELEMT;
    fila->qtd = 0;




    return fila;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
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

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
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

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f){
    int i = 0;
    return f->qtd;

}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status){
    int i = 0, soma = 0;
    for(i = 0; i < f->qtd; i++){
        if (getStatusTicket(f->elementos[i]) == status ){
            soma += 1;
        }        
    }
    return soma;
}    

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i){
    return f->elementos[i];

}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f){
    int i = 0; 

    for(i = 0; i < f->qtd; i++){
        notificaTicket(f->elementos[i]);
    }

}