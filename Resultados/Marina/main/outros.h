#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_LOC_OUTROS 100
#define MAX_TAM_DESC 500


/**
 * Estrutura de um Ticket Outros contendo os parametros especificos de um ticket do tipo Outros
 */
typedef struct Outros Outros;

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param nome Nome do Outros
 * @param nivelDif Nivel de dificuldade do Outros
 * @param descricao Descricao do chamado
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *nome, char * descricao, int nivelDif);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros();

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Outros.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Outros
 */
void setTempoEstimadoOutros(Outros *o);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros();

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param s  Ticket do tipo Outros
 */
void desalocaOutros(void *o);

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado);

#endif
/*

OUTROS
RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO
PASSARELA DA INFORMATICA
5


- Tipo: Outros
- Descricao: RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO
- Local: PASSARELA DA INFORMATICA
- Nivel de Dificuldade: 5
- Tempo Estimado: 5h
- Status: Finalizado


● OUTROS: ticket que será solicitado para situações em que as demais 
categorias não cobrem ou não se encaixa perfeitamente. É necessário 
informar: 
○ Descrição (string com no máximo 500 caracteres) 
○ Local (string com no máximo 100 caracteres) 
○ Nível de dificuldade que o usuário acredita que será necessário para 
solucionar o problema (valor inteiro iniciando de 1) 

*/