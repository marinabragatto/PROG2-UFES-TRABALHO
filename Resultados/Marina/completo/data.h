#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data Data;

Data *lerData();


void imprimeData(Data *d);


int comparaData(Data *d1, Data *d2);


int calcularDiffAnosData(Data *inicio, Data *fim);


void liberaData(Data *d);

Data * criarData(int dia, int mes, int ano); 

#endif /* _DATA_H */