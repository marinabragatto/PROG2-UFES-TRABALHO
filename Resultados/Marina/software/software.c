#include "software.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//#define MAX_TAM_NOME_SOFTWARE 100
//#define MAX_TAM_CAT 25
//#define MAX_TAM_MOTIVO 200

//#define TEMPO_ESTIMADO_BUG 3
//#define TEMPO_ESTIMADO_OUTROS 2
//#define TEMPO_ESTIMADO_DUVIDA 1

/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
struct Software {
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    int tempoEstimado;

};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    Software *soft;

    soft = (Software*)malloc(sizeof(Software));
    
    soft->impacto = impacto;
    strcpy(soft->categoria, categoria);
    strcpy(soft->motivo, motivo);
    strcpy(soft->nome, nome);
    soft->tempoEstimado = 0;

    return soft;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware(){
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    
    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*[\n]");
    scanf("%[^\n]", categoria);
    scanf("%*[\n]");
    scanf("%d\n", &impacto);
    scanf("%[^\n]", motivo);
    scanf("%*[\n]");
    
    Software * soft;
    soft = criaSoftware(nome,categoria,impacto,motivo);
    //SOFTWARE (tipo do ticket) 
    //EXCEL (nome do software) 
    //DUVIDA (categoria da solicitação) 
    //2 (impacto no trabalho) 
    //NAO CONSIGO ORDENAR COLUNA DE DADOS
    return soft;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_BUG + s->impacto;

    }
    if(strcmp(s->categoria, "DUVIDA") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }
    if(strcmp(s->categoria, "OUTROS") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }

}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado){
    return (((Software*)dado)->tempoEstimado);
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware(){
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s){
    if(s){
        free(s);
    }
    // realizar uma tipagem?
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado){
    printf("- Tipo: Software\n- Nome do software: %s\n- Categoria: %s\n- Nível do impacto: %d\n- Motivo: %s\n- Tempo estimado: %dh\n", ((Software*)dado)->nome, ((Software*)dado)->categoria, ((Software*)dado)->impacto, ((Software*)dado)->motivo, ((Software*)dado)->tempoEstimado);
    //- Tipo: Manutencao
  //  - Nome do item: PORTA DE ENTRADA
  //  - Estado de conservacao: RUIM
   // - Local: SALA 22 CT-7
   // - Tempo estimado: 6h
}