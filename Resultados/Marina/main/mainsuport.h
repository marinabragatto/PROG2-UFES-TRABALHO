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

typedef enum {
    TECNICO,
    USUARIO
} FuncaoTipo;

int calculaMediaIdadePorTipo(Vector * v, FuncaoTipo tipo);

#endif