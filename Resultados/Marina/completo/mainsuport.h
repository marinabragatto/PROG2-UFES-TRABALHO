#ifndef _MAIN_SUPORT_H
#define _MAIN_SUPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "ticket.h"
#include "software.h"
#include "manutencao.h"
#include "outros.h"
#include "tecnico.h"
#include "usuario.h"
#include "vetor.h"

#define TAM_MAX_OPERACAO 30

typedef enum {
    TECNICO,
    USUARIO
} FuncaoTipo;

int calculaMediaIdadePorTipo(Vector * v, FuncaoTipo tipo);
int calculaMediaHorasTrabalhadasTecnicos(Vector * listaTec);

void imprimeBancoUsuarios(Vector * listaUsuarios);
void imprimeBancoTecnicos(Vector * listaTec);
void imprimeRelatorio(Vector * listaTec, Vector * listaUsuarios, Fila * fila);
void imprimeFilaTickets(Fila * fila);
void imprimeRankingTecnicos(Vector * listaTec);
void imprimeRankingUsuarios(Vector * listaUsuarios);

#endif