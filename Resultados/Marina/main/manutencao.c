#include "manutencao.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Manutencao{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO]; 
    char localizacao[MAX_TAM_LOC];
    int tempoEstimado;
};

Manutencao * criaManutencao(char *nome, char * estado, char * localizacao){
    Manutencao * manutencao;
    
    manutencao =  (Manutencao*)malloc(sizeof(Manutencao));
    
    strcpy(manutencao->localizacao, localizacao);
    strcpy(manutencao->estado, estado);
    strcpy(manutencao->nome, nome);
    manutencao->tempoEstimado = 0;
    
    return manutencao;
}
//PORTA DE ENTRADA (nome do item) 
//RUIM (estado de conservação) 
//SALA 22 BLOCO B (localização) 




/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(){
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
    manutencao = criaManutencao(nome,estado,loc);

    return manutencao;
}


/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
void setTempoEstimadoManutencaocriaManutencao(Manutencao *m, char * setor){
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
    



    if(strcmp(setor, "RH") == 0){
        mult = FATOR_MULT_RH;
    }
    if(strcmp(setor, "FINANCEIRO") == 0){
        mult = FATOR_MULT_FINANC;
    }
    if(strcmp(setor, "P&D") == 0){
        mult = FATOR_MULT_PED;
    }
    if(strcmp(setor, "VENDAS") == 0){
        mult = FATOR_MULT_VENDAS;
    }
    if(strcmp(setor, "MARKETING") == 0){
        mult = FATOR_MULT_MARK;
    }
    
    m->tempoEstimado = mult*horas;
    
    
    /* ○ Cada estado atribui uma quantidade de tempo: RUIM é 3h, REGULAR é 
2h e BOM é 1h 
○ O setor do usuário impacta no cálculo. Cada setor tem um fator de 
multiplicação. RH = 2, FINANCEIRO = 3, P&D = 1, VENDAS = 1, 
MARKETING = 1 
○ O cálculo é realizado multiplicando o tempo do estado pelo fator do 
setor. Por exemplo, se o estado é RUIM e o setor é o RH, o tempo 
estimado será atribuído como 3 * 2 = 6h */
}

char getTipoManutencao(){
    return 'M';
}

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param s  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m){
    if(m){
        free(m);
    }
    // realizar uma tipagem?
}

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado){
//- Tipo: Manutencao
//- Nome do item: PORTA DE ENTRADA
//- Estado de conservacao: RUIM
//- Local: SALA 22 CT-7
//- Tempo estimado: 6h



    printf("- Tipo: Manutencao\n- Nome do item: %s\n- Estado de conservacao: %s\n- Local: %s\n- Tempo estimado: %dh\n", ((Manutencao*)dado)->nome, ((Manutencao*)dado)->estado, ((Manutencao*)dado)->localizacao, ((Manutencao*)dado)->tempoEstimado);

}

int getTempoEstimadoManutencao(void *dado){
    return (((Manutencao*)dado)->tempoEstimado);
}