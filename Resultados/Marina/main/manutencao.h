#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOC 100
#define MAX_TAM_ESTADO 40
#define MAX_TAM_PED 40

#define TEMPO_ESTIMADO_RUIM 3
#define TEMPO_ESTIMADO_REGULAR 2
#define TEMPO_ESTIMADO_BOM 1

#define FATOR_MULT_RH 2
#define FATOR_MULT_FINANC 3
#define FATOR_MULT_PED 1
#define FATOR_MULT_VENDAS 1
#define FATOR_MULT_MARK 1




/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo MANUTENCAO
 */
typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome do Manutencao
 * @param categoria Categoria do Manutencao
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao * criaManutencao(char *nome, char * estado, char * localizacao, char * setor);
//PORTA DE ENTRADA (nome do item) 
//RUIM (estado de conservação) 
//SALA 22 BLOCO B (localização) 

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao * lerManutencao(char * setor);

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param m  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m);

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado);

#endif


/*MANUTENCAO: ticket que será solicitado para realizar manutenção de algum 
equipamento em geral. É necessário informar: 
○ Nome do item a ser executado a manutenção (string com no máximo 
100 caracteres) 
○ O estado do item (RUIM, REGULAR ou BOM) 
○ O local exato onde se encontra o item (string com no máximo 100 
caracteres) */