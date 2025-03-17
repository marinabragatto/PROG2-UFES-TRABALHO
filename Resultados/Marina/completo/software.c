#include "software.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct Software {
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    int tempoEstimado;

};


Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    Software *soft;

    soft = (Software*)malloc(sizeof(Software));
    if(soft == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    
    soft->impacto = impacto;
    strcpy(soft->categoria, categoria);
    strcpy(soft->motivo, motivo);
    strcpy(soft->nome, nome);
    soft->tempoEstimado = 0;

    return soft;
}

Software *lerSoftware(){
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    
    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", categoria);
    scanf("%d\n", &impacto);
    scanf("%[^\n]\n", motivo);
    
    Software * soft;
    soft = criaSoftware(nome,categoria,impacto,motivo);
    return soft;
}


void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_BUG + s->impacto;

    }
    if(strcmp(s->categoria, "DUVIDA") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }
    if(strcmp(s->categoria, "OUTROS") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_OUTROS + s->impacto;
    }

}

int getTempoEstimadoSoftware(void *dado){
    return (((Software*)dado)->tempoEstimado);
}


char getTipoSoftware(){
    return 'S';
}


void desalocaSoftware(void *s){
    if(s){
        free(s);
    }

}

void notificaSoftware(void *dado){
    printf("- Tipo: Software\n- Nome do software: %s\n- Categoria: %s\n- Nível do impacto: %d\n- Motivo: %s\n- Tempo estimado: %dh\n", ((Software*)dado)->nome, ((Software*)dado)->categoria, ((Software*)dado)->impacto, ((Software*)dado)->motivo, ((Software*)dado)->tempoEstimado);
}