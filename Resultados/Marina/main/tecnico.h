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

int comparaTecnicoECpf(Tecnico * tecnico, char * cpf);

int comparaDoisTecnicos(Tecnico * tecnico1, Tecnico * tecnico2);

int getIdadeTecnico(Tecnico * tecnico);

int getTempoTrabalhadoTecnicos(Tecnico * tecnico);


/*
T (caractere indicando cadastro de um técnico) 
HEIMERDINGER GARCIA (nome) 
456.987.123-96 (CPF) 
20/10/1945 (data de nascimento) 
(90)99876-1234 (telefone) 
MASCULINO (gênero) 
GERAL (área de atuação) 
20 (disponibilidade de trabalho) 
3500 (salário) 
U (caractere indicando cadastro de um usuário) 
TAHM KENCH (nome) 
123.932.250-46 (CPF) 
01/09/1955 (data de nascimento) 
(34)96373-7004 (telefone) 
OUTROS (gênero) 
RH (setor) 
*/
#endif
