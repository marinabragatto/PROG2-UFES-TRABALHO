#include "vetor.h"
#include <stdlib.h>


#define TAM_MAX 5

//typedef void *data_type; // void pointer
struct Vector {
    data_type * data;
    int tamAtual;
    int tamMax;
};



/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector * vector;
    vector = (Vector*)malloc(sizeof(Vector));
    vector->tamAtual = 0;

    vector->tamMax = TAM_MAX;
    vector->data = (data_type*)malloc(sizeof(data_type)*(TAM_MAX));

    return vector;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val){
    int tamAtual  = 0, tamMax = 0;
    tamAtual = VectorSize(v);
    tamMax = v->tamMax;
    
    if(tamAtual >= tamMax){
        v->data = realloc (v->data, sizeof(data_type)*(tamAtual + tamMax));
        v->tamMax += TAM_MAX;
    }

    v->data[tamAtual] = val;
    v->tamAtual++;

}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamAtual;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    if(v){
        if(v->data){
            int i = 0;
            for(i = 0; i < VectorSize(v); i++){
                destroy(v->data[i]);
            }
            free(v->data);
        }
        free(v);
    }
}

void imprimeElementoVetorDeIdx( Vector * v, void (*imprime)(data_type), int idx){
    imprime(v->data[idx]);
}