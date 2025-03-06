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

void imprimeBancoUsuarios(Vector * listaUsuarios){
    int i =0, tamanho = 0;

    printf("----- BANCO DE USUARIOS -----\n");
    tamanho  = VectorSize(listaUsuarios);
    for(i = 0; i < tamanho; i++){
        imprimeElementoVetorDeIdx(listaUsuarios, notificaUsuario, i);
    }
    printf("----------------------------\n");
}      

void imprimeBancoTecnicos(Vector * listaTec){
    int i = 0, tamanho = 0;
    printf("----- BANCO DE TECNICOS -----\n");
    tamanho = VectorSize(listaTec);
    for(i = 0; i < tamanho; i++){
        imprimeElementoVetorDeIdx(listaTec, notificaTecnico, i);
    }
    printf("----------------------------\n");
}

void imprimeRelatorio(Vector * listaTec, Vector * listaUsuarios, Vector * fila){
    int mediaIdadeTec = 0, mediaIdadeUser = 0;
    mediaIdadeTec = calculaMediaIdadePorTipo(listaTec, TECNICO);
    mediaIdadeUser = calculaMediaIdadePorTipo(listaUsuarios, USUARIO);

    printf("----- RELATORIO GERAL -----\n");
        
    printf("- Qtd tickets: %d\n- Qtd tickets (A): %d\n- Qtd tickets (F): %d\n", getQtdTicketsNaFila(fila), getQtdTicketsPorStatusNaFila(fila, 'A'), getQtdTicketsPorStatusNaFila(fila, 'F'));
        
    printf("- Qtd usuarios: %d\n- Md idade usuarios: %d\n- Qtd tecnicos: %d\n- Md idade tecnicos: %d\n- Md trabalho tecnicos: %d\n---------------------------\n", VectorSize(listaUsuarios), mediaIdadeUser, VectorSize(listaTec),mediaIdadeTec, 0);
}


