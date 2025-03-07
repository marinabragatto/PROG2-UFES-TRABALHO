#ifndef _USUARIO_H
#define _USUARIO_H


#define MAX_TAM_NOME_USER 100
#define MAX_TAM_CPF_USER 15
#define MAX_TAM_TELEF_USER 18
#define MAX_TAM_GEN_USER 18
#define MAX_TAM_SETOR_USER 40

#include "data.h"

typedef struct Usuario Usuario;

Usuario *criaUsuario(char *nome, char *cpf, Data * data, char * telefone, char * genero, char * setor);

Usuario *lerUsuario();

void desalocaUsuario(void *u);

void notificaUsuario(void *dado);

int comparaUsuariooECpf(Usuario * user, char * cpf);

int comparaDoisUsuarios(Usuario * user1, Usuario * user2);

int getIdadeUsuarios(Usuario * user);

char * getSetorUsuario(Usuario * user);


#endif
