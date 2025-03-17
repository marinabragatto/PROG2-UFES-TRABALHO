#include "funcoesmenu.h"
#include "database.h"

struct DataBase {
    Vector * listaTec;
    Vector * listaUsuarios;
    Fila * fila;
};

DataBase * criaDataBase(){
    DataBase * base;
    base = (DataBase*)malloc(sizeof(DataBase));
    if(base == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    base->fila = criaFila();
    base->listaTec = VectorConstruct();
    base->listaUsuarios = VectorConstruct();
    return base;
}

Vector * retornaListaTecnicos(DataBase * base){
    return base->listaTec;
}

Vector * retornaListaUsuarios(DataBase * base){
    return base->listaUsuarios;
}

Fila * retornaFila(DataBase * base){
    return base->fila;
}

void destroiDataBase(DataBase * base){
    if(base){
        if(base->fila){
            desalocaFila(base->fila);
        }
        if(base->listaTec){
            VectorDestroy(base->listaTec, desalocaTecnico);
        }
        if(base->listaUsuarios){
            VectorDestroy(base->listaUsuarios, desalocaUsuario);
        }        
        
        free(base);
    }
    
}
int userJaCadastradoBanco(Vector * usuarios, Usuario * user){
    Usuario * atual;
    for(int k = 0; k < VectorSize(usuarios); k++){
        atual = VectorGet(usuarios, k);
        if(comparaDoisUsuarios(atual, user)){
            return 1;
        }
    }

    return 0;
}

int tecnicoJaCadastradoBanco(Vector * tecnicos, Tecnico * tec){
    Tecnico * atual;

    for(int k = 0; k < VectorSize(tecnicos); k++){
        atual = VectorGet(tecnicos, k);
        if(comparaDoisTecnicos(atual, tec)){
            return 1;
        }
    }

    return 0;
}

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

int calculaMediaHorasTrabalhadasTecnicos(Vector * listaTec){
    int i = 0, size = 0;
    size = VectorSize(listaTec);

    int somatorio = 0;

    void * perfilGenerico;


    for(i = 0 ; i < size; i++){
        perfilGenerico = VectorGet(listaTec,i);
        
        somatorio += getTempoTrabalhadoTecnicos(perfilGenerico);
        
    }
    return somatorio/size;
}