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
#include "database.h"



int main(){
    char op = 'a';

    DataBase * dataBase = criaDataBase();

    while(1){
        scanf("%*[^A-Za-z0-9]");
        scanf("%c\n", &op);

        Vector * listaTec = retornaListaTecnicos(dataBase); 
        Vector * listaUsuarios = retornaListaUsuarios(dataBase);
        Fila * fila = retornaFila(dataBase);

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

    destroiDataBase(dataBase);
    return  0;
}

