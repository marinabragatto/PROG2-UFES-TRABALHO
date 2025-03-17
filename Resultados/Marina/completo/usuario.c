#include "usuario.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct Usuario {
    char nome[MAX_TAM_NOME_USER];
    char cpf[MAX_TAM_CPF_USER];
    Data * data;
    char telefone[MAX_TAM_TELEF_USER];
    char genero[MAX_TAM_GEN_USER]; 
    char setor[MAX_TAM_SETOR_USER];
    int qtdTicketsSolicitados;
};

Usuario *criaUsuario(char *nome, char *cpf, Data * data, char * telefone, char * genero, char * setor){
    Usuario * user;
    user = (Usuario*)malloc(sizeof(Usuario));
    if(user == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    
    strcpy(user->cpf, cpf);
    strcpy(user->nome, nome);
    strcpy(user->telefone, telefone);
    strcpy(user->genero, genero);
    strcpy(user->setor, setor);
    user->data = data;
    user->qtdTicketsSolicitados = 0;
    return user;


}



Usuario *lerUsuario(){
    char nome[MAX_TAM_NOME_USER];
    char cpf[MAX_TAM_CPF_USER];
    Data * nascimento;
    char telefone[MAX_TAM_TELEF_USER];
    char genero[MAX_TAM_GEN_USER];
    char setor[MAX_TAM_SETOR_USER];


    scanf("%*[^0-9a-zA-Z]");
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", cpf);
    nascimento = lerData();
    scanf("%[^\n]\n", telefone);
    scanf("%[^\n]\n", genero);
    scanf("%[^\n]\n", setor);


    Usuario * user;
    user = criaUsuario(nome, cpf, nascimento, telefone, genero, setor);
    return user;

}

void desalocaUsuario(void *u){
    if(u){
        if(((Usuario*)u)->data){
            liberaData(((Usuario*)u)->data);
        }
        free(u);
    }
}

void notificaUsuario(void *dado){
    printf("--------------------\n");
    Usuario * user = ((Usuario*)dado);
    printf("- Nome: %s\n- CPF: %s\n- Data de Nascimento: ", user->nome, user->cpf);
    imprimeData(user->data);
    printf("- Telefone: %s\n- Genero: %s\n- Setor: %s\n- Tickets solicitados: %d\n", user->telefone, user->genero, user->setor, user->qtdTicketsSolicitados);
}

int comparaUsuariooECpf(Usuario * user, char * cpf){
    if(strcmp(user->cpf, cpf) == 0){
        return 1;
    }
    return 0;
}

int comparaDoisUsuarios(Usuario * user1, Usuario * user2){
    // Se os usuarios são iguais retorna 1;
    if(strcmp(user1->cpf, user2->cpf) == 0){
        return 1;
    }
    return 0;
}

int getIdadeUsuarios(Usuario * user){
    Data * dataReferencia;
    dataReferencia = criarData(18, 2, 2025);
    int ano = calcularDiffAnosData(user->data, dataReferencia);
    liberaData(dataReferencia);
    return ano;
}

char * getSetorUsuario(Usuario * user){
    return user->setor;
}

void incrementaQtdTicketsSolicitados(Usuario * user){
    user->qtdTicketsSolicitados++;
}

char * getCpfUsuario(Usuario * user){
    return user->cpf;
}

int comparaDoisUsuariosRanking1(const void * a, const void * b){
    // Convertendo os ponteiros genéricos para ponteiros para ponteiros de Tecnico
    Usuario *us1 = *(Usuario **)a;
    Usuario *us2 = *(Usuario **)b;

    if (us1->qtdTicketsSolicitados > us2->qtdTicketsSolicitados) {
        return -1;
    } else if  (us1->qtdTicketsSolicitados < us2->qtdTicketsSolicitados){
        return 1;
    } else {
        // Critério de desempate: ordem alfabética do nome
        return strcmp(us1->nome, us2->nome);
    }
}