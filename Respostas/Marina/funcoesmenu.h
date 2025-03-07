#ifndef _FUNCOES_MENU_H
#define _FUNCOES_MENU_H

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
#include "mainsuport.h"

//Possui as opcoes do menu 'A' 'E'


Vector * operacaoT(Vector * tecnicos);

Vector * operacaoU(Vector * usuarios);

void operacaoE(Vector * listaTec, Vector * listaUsuarios, Fila * fila);

Fila * operacaoA(Fila  * fila, Vector * listaUsuarios);



#endif