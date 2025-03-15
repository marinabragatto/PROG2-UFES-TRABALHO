
#ifndef _TECNICO_H
#define _TECNICO_H


#define MAX_TAM_NOME_TECNICO 100
#define MAX_TAM_CPF 15
#define MAX_TAM_TELEF 18
#define MAX_TAM_GEN 18
#define MAX_TAM_AREA_AT 40

#include "data.h"

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *nome, char *cpf, Data * data, char * telefone, char * genero, char * areaAt, int disponibilidadeTrab, float salario);

Tecnico *lerTecnico();

void desalocaTecnico(void *t);

void notificaTecnico(void *dado);

float getSalarioTecnico(void *dado);

int getDisponibilidadeTrabalhoTecnico(void *dado);

char * getAreaAtuacaoTecnico(Tecnico * tecnico);

int comparaTecnicoECpf(Tecnico * tecnico, char * cpf);

int comparaDoisTecnicos(Tecnico * tecnico1, Tecnico * tecnico2);

int getIdadeTecnico(Tecnico * tecnico);

int getTempoTrabalhadoTecnicos(Tecnico * tecnico);


Tecnico * tecnicoRecebeTicket(Tecnico * tec, Ticket * ticket);

int comparaDoisTecnicosRanking1(void * a, void * b);

int tecnicoPodePegarTicket(Tecnico * tec, Ticket * ticket);


#endif