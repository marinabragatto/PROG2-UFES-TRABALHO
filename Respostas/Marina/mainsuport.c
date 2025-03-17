#include "mainsuport.h"



void imprimeBancoUsuarios(Vector * listaUsuarios){
    int i =0, tamanho = 0;

    printf("----- BANCO DE USUARIOS -----\n");
    tamanho  = VectorSize(listaUsuarios);
    for(i = 0; i < tamanho; i++){
        imprimeElementoVetorDeIdx(listaUsuarios, notificaUsuario, i);
    }
    printf("----------------------------\n\n");
}      

void imprimeBancoTecnicos(Vector * listaTec){
    int i = 0, tamanho = 0;
    printf("----- BANCO DE TECNICOS -----\n");
    tamanho = VectorSize(listaTec);
    for(i = 0; i < tamanho; i++){
        imprimeElementoVetorDeIdx(listaTec, notificaTecnico, i);
    }
    printf("----------------------------\n\n");
}

void imprimeRelatorio(Vector * listaTec, Vector * listaUsuarios, Fila * fila){
    int mediaIdadeTec = 0, mediaIdadeUser = 0, mediaHorasTrabTec = 0;
    mediaIdadeTec = calculaMediaIdadePorTipo(listaTec, TECNICO);
    mediaIdadeUser = calculaMediaIdadePorTipo(listaUsuarios, USUARIO);
    mediaHorasTrabTec = calculaMediaHorasTrabalhadasTecnicos(listaTec);

    printf("----- RELATORIO GERAL -----\n");
        
    printf("- Qtd tickets: %d\n- Qtd tickets (A): %d\n- Qtd tickets (F): %d\n", getQtdTicketsNaFila(fila), getQtdTicketsPorStatusNaFila(fila, 'A'), getQtdTicketsPorStatusNaFila(fila, 'F'));
        
    printf("- Qtd usuarios: %d\n- Md idade usuarios: %d\n- Qtd tecnicos: %d\n- Md idade tecnicos: %d\n- Md trabalho tecnicos: %d\n---------------------------\n\n", VectorSize(listaUsuarios), mediaIdadeUser, VectorSize(listaTec),mediaIdadeTec, mediaHorasTrabTec);
}

void imprimeFilaTickets(Fila * fila){
    printf("----- FILA DE TICKETS -----\n");
    notificaFila(fila);
    printf("---------------------------\n\n");
}

void imprimeRankingTecnicos(Vector * listaTec){
    Vector * ordenado;

    ordenado = VectorConstruct();
    
    for(int i = 0; i < VectorSize(listaTec); i++){
        VectorPushBack(ordenado, VectorGet(listaTec,i));
    }

    ordenaVetor(ordenado, comparaDoisTecnicosRanking1);
    printf("----- RANKING DE TECNICOS -----\n");
    for(int i = 0; i < VectorSize(ordenado); i++){
        notificaTecnico(VectorGet(ordenado, i));
    }
    destroiParcialmenteOrdenado(ordenado);
    printf("-------------------------------\n\n");


}

void imprimeRankingUsuarios(Vector * listaUsuarios){
    Vector * ordenado;

    ordenado = VectorConstruct();
    
    for(int i = 0; i < VectorSize(listaUsuarios); i++){
        VectorPushBack(ordenado, VectorGet(listaUsuarios,i));
    }
    ordenaVetor(ordenado, comparaDoisUsuariosRanking1);
    
    printf("----- RANKING DE USUARIOS -----\n");
    for(int i = 0; i < VectorSize(ordenado); i++){
        notificaUsuario(VectorGet(ordenado, i));
    }
    destroiParcialmenteOrdenado(ordenado);
    printf("-------------------------------\n\n");


}