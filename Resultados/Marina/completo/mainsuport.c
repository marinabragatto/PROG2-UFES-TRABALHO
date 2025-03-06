#include "mainsuport.h"



int calculaMediaIdadePorTipo(Vector * v, FuncaoTipo tipo){
    int i = 0, size = 0;
    size = VectorSize(v);

    int somatorio = 0;

    void * perfilGenerico;


    for(i = 0 ; i < size; i++){
        perfilGenerico = VectorGet(v,i);
        
        if(tipo == TECNICO){
            somatorio += getIdadeTecnico(perfilGenerico);
        }
        else if(tipo == USUARIO){
            somatorio += getIdadeUsuarios(perfilGenerico);
        }
    
        
    }
    return somatorio/size;
}