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
    scanf("%[^\n]", nome);
    scanf("%*[\n]");
    scanf("%[^\n]", cpf);
    scanf("%*[\n]");
    nascimento = lerData();
    scanf("%[^\n]", telefone);
    scanf("%*[\n]");
    scanf("%[^\n]", genero);
    scanf("%*[\n]");
    scanf("%[^\n]", setor);
    scanf("%*[\n]");



    Usuario * user;
    user = criaUsuario(nome, cpf, nascimento, telefone, genero, setor);
    return user;
/*
U (caractere indicando cadastro de um usuário) 
TAHM KENCH (nome) 
123.932.250-46 (CPF) 
01/09/1955 (data de nascimento) 
(34)96373-7004 (telefone) 
OUTROS (gênero) 
RH (setor) 
*/
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
    printf("- Nome: %s\n- CPF: %s\n- Data de Nascimento: ", ((Usuario*)dado)->nome, ((Usuario*)dado)->cpf);
    imprimeData(((Usuario*)dado)->data);
    printf("- Telefone: %s\n- Genero: %s\n- Setor: %s\n- Tickets solicitados: %d\n", ((Usuario*)dado)->telefone, ((Usuario*)dado)->genero, ((Usuario*)dado)->setor, ((Usuario*)dado)->qtdTicketsSolicitados);
    


    /*
    - Nome: TAHM KENCH
    - CPF: 123.932.250-46
    - Data de Nascimento: 1/9/1955
    - Telefone: (34)96373-7004
    - Genero: OUTROS
    - Setor: RH
    - Tickets solicitados: 0*/
}

int comparaUsuariooECpf(Usuario * user, char * cpf){
    if(strcmp(user->cpf, cpf) == 0){
        return 1;
    }
    return 0;
}

int comparaDoisUsuarios(Usuario * user1, Usuario * user2){
    if(strcmp(user1->cpf, user2->cpf) == 0){
        return 1;
    }
    return 0;
}

int getIdadeUsuarios(Usuario * user){
    Data * dataReferencia;
    //18/02/2025
    dataReferencia = criarData(18, 2, 2025);
    int ano = calcularDiffAnosData(user->data, dataReferencia);
    liberaData(dataReferencia);
    return ano;
}
