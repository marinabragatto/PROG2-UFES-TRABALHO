#include "manutencao.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Manutencao{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO]; 
    char localizacao[MAX_TAM_LOC];
    int tempoEstimado;
    char setordoPedinte[MAX_TAM_PED];
};

Manutencao * criaManutencao(char *nome, char * estado, char * localizacao, char * setor){
    Manutencao * manutencao;
    
    manutencao =  (Manutencao*)malloc(sizeof(Manutencao));
    if(manutencao == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    
    strcpy(manutencao->localizacao, localizacao);
    strcpy(manutencao->estado, estado);
    strcpy(manutencao->nome, nome);
    if(setor[0] != '\0'){
       strcpy(manutencao->setordoPedinte, setor); 
    }
    
    manutencao->tempoEstimado = 0;
    
    return manutencao;
}

Manutencao *lerManutencao(char * setor){
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO];
    char loc[MAX_TAM_LOC];
    
    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*[\n]");
    scanf("%[^\n]", estado);
    scanf("%*[\n]");
    scanf("%[^\n]", loc);
    scanf("%*[\n]");
    
    Manutencao * manutencao;
    manutencao = criaManutencao(nome,estado,loc, setor);

    return manutencao;
}


void setTempoEstimadoManutencao(Manutencao *m){
    int mult = 0, horas = 0;
    if(strcmp(m->estado, "RUIM") == 0){
        horas = TEMPO_ESTIMADO_RUIM;
    }
    if(strcmp(m->estado, "REGULAR") == 0){
        horas = TEMPO_ESTIMADO_REGULAR;
    }
    if(strcmp(m->estado, "BOM") == 0){
        horas = TEMPO_ESTIMADO_BOM;
    }
    

    if(strcmp(m->setordoPedinte, "RH") == 0){
        mult = FATOR_MULT_RH;
    }
    if(strcmp(m->setordoPedinte, "FINANCEIRO") == 0){
        mult = FATOR_MULT_FINANC;
    }
    if(strcmp(m->setordoPedinte, "P&D") == 0){
        mult = FATOR_MULT_PED;
    }
    if(strcmp(m->setordoPedinte, "VENDAS") == 0){
        mult = FATOR_MULT_VENDAS;
    }
    if(strcmp(m->setordoPedinte, "MARKETING") == 0){
        mult = FATOR_MULT_MARK;
    }
    
    m->tempoEstimado = mult*horas;
    

}

char getTipoManutencao(){
    return 'M';
}


void desalocaManutencao(void *m){
    if(m){
        free(m);
    }

}

void notificaManutencao(void *dado){

    printf("- Tipo: Manutencao\n- Nome do item: %s\n- Estado de conservacao: %s\n- Local: %s\n- Tempo estimado: %dh\n", ((Manutencao*)dado)->nome, ((Manutencao*)dado)->estado, ((Manutencao*)dado)->localizacao, ((Manutencao*)dado)->tempoEstimado);

}

int getTempoEstimadoManutencao(void *dado){
    return (((Manutencao*)dado)->tempoEstimado);
}

