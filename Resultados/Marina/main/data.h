#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Estrutura que representa uma Data.
 */
typedef struct Data Data;

/**
 * @brief Lê uma data no formato dd/mm/aaaa da entrada padrão.
 * @return Uma estrutura Data contendo a data lida.
 */
Data *lerData();

/**
 * @brief Imprime uma data no formato dd/mm/aaaa com uma quebra de linha no final.
 * @param d Ponteiro para a estrutura Data a ser impressa.
 */
void imprimeData(Data *d);

/**
 * @brief Compara se duas datas são exatamente iguais.
 * @param d1 Ponteiro para a primeira estrutura Data.
 * @param d2 Ponteiro para a segunda estrutura Data.
 * @return Retorna 1 se as datas forem iguais e 0 caso contrário.
 */
int comparaData(Data *d1, Data *d2);

/**
 * @brief Calcula a diferença de anos entre duas datas da mesma forma que se calcula aniversários.
 * @param inicio Ponteiro para a estrutura Data inicial.
 * @param fim Ponteiro para a estrutura Data final.
 * @return A diferença de anos entre as duas datas.
 */
int calcularDiffAnosData(Data *inicio, Data *fim);

/**
 * @brief Libera a memória alocada para uma estrutura Data.
 * @param d Ponteiro para a estrutura Data a ser desalocada.
 */
void liberaData(Data *d);

Data * criarData(int dia, int mes, int ano); 

#endif /* _DATA_H */