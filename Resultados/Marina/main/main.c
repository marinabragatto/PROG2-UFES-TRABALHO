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
#include "funcoesmenu.h"



int main(){
    char op = 'a';
    
    Vector * listaTec;
    Vector * listaUsuarios;
    Fila * fila;
    fila = criaFila();
    listaTec = VectorConstruct();
    listaUsuarios = VectorConstruct();

    while(1){
        scanf("%*[^A-Za-z0-9]");
        scanf("%c\n", &op);
        if(op == 'F'){
            break;
        }
        if(op == 'T'){
            listaTec = operacaoT(listaTec);
        }
        if(op == 'U'){
            listaUsuarios = operacaoU(listaUsuarios);
        }
        if(op == 'E'){
            operacaoE(listaTec, listaUsuarios, fila);
        }
        if(op == 'A'){
            fila = operacaoA(fila, listaUsuarios);
        }
    }

    VectorDestroy(listaTec, desalocaTecnico);
    VectorDestroy(listaUsuarios, desalocaUsuario);
    desalocaFila(fila);

    return  0;
}