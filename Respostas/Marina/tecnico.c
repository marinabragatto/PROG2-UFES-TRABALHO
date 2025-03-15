#include "ticket.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tecnico.h"

struct Tecnico{
    char nome[MAX_TAM_NOME_TECNICO];
    char cpf[MAX_TAM_CPF];
    char telefone[MAX_TAM_TELEF];
    char genero[MAX_TAM_GEN];
    char areaAtuacao[MAX_TAM_AREA_AT];
    Data * data;
    int disponibilidadeTrab; 
    float salario;
    int tempoTrabalhado;
};



Tecnico *criaTecnico(char *nome, char *cpf, Data * data, char * telefone, char * genero, char * areaAt, int disponibilidadeTrab, float salario){
    Tecnico * tec;

    tec = (Tecnico*)malloc(sizeof(Tecnico));
    if(tec == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }

    tec->salario = salario;
    tec->disponibilidadeTrab = disponibilidadeTrab;
    tec->tempoTrabalhado = 0;
    tec->data = data;
    strcpy(tec->cpf, cpf);
    strcpy(tec->nome, nome);
    strcpy(tec->telefone, telefone);
    strcpy(tec->genero, genero);
    strcpy(tec->areaAtuacao, areaAt);

    return tec;
}

Tecnico *lerTecnico(){

    char nome[MAX_TAM_NOME_TECNICO];
    char cpf[MAX_TAM_CPF];
    Data * nascimento;
    char telefone[MAX_TAM_TELEF];
    char genero[MAX_TAM_GEN];
    char areaAtuacao[MAX_TAM_AREA_AT];

    int dispoTrab = 0;
    float salario = 0;
    
    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", cpf);
    nascimento = lerData();
    scanf("%[^\n]\n", telefone);
    scanf("%[^\n]\n", genero);
    scanf("%[^\n]\n", areaAtuacao);
    scanf("%d\n", &dispoTrab);
    scanf("%f\n", &salario);

    Tecnico * tec ;
    tec = criaTecnico(nome, cpf, nascimento, telefone, genero, areaAtuacao, dispoTrab, salario);
    return tec;

}

void desalocaTecnico(void *t){
    if(t){
        if(((Tecnico*)t)->data){
            liberaData(((Tecnico*)t)->data);
        }
        free(t);
    }

}

void notificaTecnico(void *dado){
    printf("--------------------\n");
    printf("- Nome: %s\n- CPF: %s\n- Data de Nascimento: ", ((Tecnico*)dado)->nome, ((Tecnico*)dado)->cpf);
    imprimeData(((Tecnico*)dado)->data);
    printf("- Telefone: %s\n- Genero: %s\n- Area de Atuacao: %s\n- Salario: %.2f\n- Disponibilidade: %dh\n- Tempo Trabalhado: %dh\n",((Tecnico*)dado)->telefone, ((Tecnico*)dado)->genero, ((Tecnico*)dado)->areaAtuacao, ((Tecnico*)dado)->salario, ((Tecnico*)dado)->disponibilidadeTrab, ((Tecnico*)dado)->tempoTrabalhado);
}

float getSalarioTecnico(void *dado){
    return (((Tecnico*)dado)->salario);
}

int getDisponibilidadeTrabalhoTecnico(void *dado){
    return (((Tecnico*)dado)->disponibilidadeTrab);
}

int comparaTecnicoECpf(Tecnico * tecnico, char * cpf){
    if(strcmp(tecnico->cpf, cpf) == 0){
        return 1;
    }
    return 0;
}

int comparaDoisTecnicos(Tecnico * tecnico1, Tecnico * tecnico2){
    if(strcmp(tecnico1->cpf, tecnico2->cpf) == 0){
        return 1;
    }
    return 0;
}

int getIdadeTecnico(Tecnico * tecnico){
    Data * dataReferencia;
    dataReferencia = criarData(18, 2, 2025);
    int ano = calcularDiffAnosData(tecnico->data, dataReferencia);
    liberaData(dataReferencia);
    return ano;
}

int getTempoTrabalhadoTecnicos(Tecnico * tecnico){
    return tecnico->tempoTrabalhado;
}

char * getAreaAtuacaoTecnico(Tecnico * tecnico){
    return tecnico->areaAtuacao;
}



int comparaDoisTecnicosRanking1(void * a, void * b){
    
    // Convertendo os ponteiros genéricos para ponteiros para ponteiros de Tecnico
    Tecnico *tec1 = *(Tecnico **)a;
    Tecnico *tec2 = *(Tecnico **)b;

    if (tec1->tempoTrabalhado > tec2->tempoTrabalhado) {
        return -1;
    } else if (tec1->tempoTrabalhado < tec2->tempoTrabalhado) {
        return 1;
    } else {
        // Critério de desempate: ordem alfabética do nome
        return strcmp(tec1->nome, tec2->nome);
    }


}

Tecnico * tecnicoRecebeTicket(Tecnico * tec, Ticket * ticket){
    int desconto = getTempoEstimadoTicket(ticket);
    tec->disponibilidadeTrab -= desconto;
    tec->tempoTrabalhado += desconto;
    return tec;
}

int tecnicoPodePegarTicket(Tecnico * tec, Ticket * ticket){
    char tipoTic = getTipoTicket(ticket);
    int podeAtender = 0;

    if (tipoTic == 'S' && strcmp(getAreaAtuacaoTecnico(tec), "TI") == 0) {
        podeAtender = 1;
    } else if ((tipoTic == 'O' || tipoTic == 'M') && strcmp(getAreaAtuacaoTecnico(tec), "TI") != 0) {
        podeAtender = 1;
    }

    if (podeAtender && getDisponibilidadeTrabalhoTecnico(tec) >= getTempoEstimadoTicket(ticket)) {
        return 1;
    }
    return 0;
}