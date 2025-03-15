#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void * data; // void pointer
typedef struct Vector Vector;


Vector *VectorConstruct();

void VectorPushBack(Vector *v, data val);


data VectorGet(Vector *v, int i);

int VectorSize(Vector *v);

void VectorDestroy(Vector *v, void (*destroy)(data));


void imprimeElementoVetorDeIdx(Vector * v, void (*imprime)(data), int idx);

void  ordenaVetor(Vector * v, int (*compar)(const void *, const void *));

void destroiParcialmenteOrdenado(Vector * v);

#endif