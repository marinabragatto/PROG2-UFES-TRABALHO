#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>


#define TAM_MAX 5

struct Vector {
    data * data;
    int tamAtual;
    int tamMax;
};


Vector *VectorConstruct(){
    Vector * vector;
    vector = (Vector*)malloc(sizeof(Vector));
    if(vector == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    vector->tamAtual = 0;

    vector->tamMax = TAM_MAX;
    vector->data = (data*)malloc(sizeof(data)*(TAM_MAX));
    if(vector->data == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }

    return vector;
}

void VectorPushBack(Vector *v, data val){
    int tamAtual  = 0, tamMax = 0;
    tamAtual = VectorSize(v);
    tamMax = v->tamMax;
    
    if(tamAtual >= tamMax){
        v->data = realloc (v->data, sizeof(data)*(tamAtual + tamMax));
        if(v->data == NULL){
            printf("erro ao alocar\n");
            exit(1);
        }
        v->tamMax += TAM_MAX;
    }

    v->data[tamAtual] = val;
    v->tamAtual++;

}


data VectorGet(Vector *v, int i){
    return v->data[i];
}


int VectorSize(Vector *v){
    return v->tamAtual;
}

void VectorDestroy(Vector *v, void (*destroy)(data)){
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

void imprimeElementoVetorDeIdx( Vector * v, void (*imprime)(data), int idx){
    imprime(v->data[idx]);
}

void  ordenaVetor(Vector * v, int (*compar)(const void *, const void *)){
    qsort(v->data, v->tamAtual, sizeof(data) , compar);
}

void destroiParcialmenteOrdenado(Vector * v){
    if(v){
        if(v->data){
            free(v->data);
        }
        free(v);
    }
}