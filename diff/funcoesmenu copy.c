#include "funcoesmenu.h"



Vector * operacaoT(Vector * tecnicos){
    Tecnico * tec;
    tec = lerTecnico();
    VectorPushBack(tecnicos, tec);
    return tecnicos;
}

Vector * operacaoU(Vector * usuarios){
    Usuario * user;
    user = lerUsuario(usuarios, user);
    VectorPushBack(usuarios, user);
    return usuarios;
}

void operacaoE(Vector * listaTec, Vector * listaUsuarios, Fila * fila){
    char operacao[TAM_MAX_OPERACAO];
    scanf("%[^\n]", operacao);
    scanf("%*[\n]");

    int tamanho = 0, i = 0;


    if(strcmp(operacao, "USUARIOS")==0){
        imprimeBancoUsuarios(listaUsuarios);
    }
    if(strcmp(operacao, "TECNICOS")==0){
        imprimeBancoTecnicos(listaTec);
    }
    
    if(strcmp(operacao, "RELATORIO")==0){
        imprimeRelatorio(listaTec, listaUsuarios, fila);
    }
    if(strcmp(operacao, "DISTRIBUI")==0){
        int j = 0;
        Ticket * ticketAtual;
    
        int jaPassouPorTodos = 0;
        for(int k = 0, j = 0; ;k++){
            if(k >= VectorSize(listaTec)){
                if(getQtdTicketsPorStatusNaFila(fila, 'A') > 0 && jaPassouPorTodos == 0){
                    k = 0;
                    jaPassouPorTodos = 1;
                }
                else{
                    break;
                }

            }
            char tipoTic = 'a';
            if(j < getQtdTicketsNaFila(fila)){

            }
            else if(j >= getQtdTicketsNaFila(fila)){
                break;
            }
            ticketAtual = getTicketNaFila(fila, j);
            tipoTic = getTipoTicket(ticketAtual);
            
            Tecnico * tecAnalise;
            tecAnalise = VectorGet(listaTec, k);
            
            if(getStatusTicket(ticketAtual) == 'A'){
                if(tipoTic  == 'S'){
                    if(strcmp(getAreaAtuacaoTecnico(tecAnalise), "TI")==0){
                        if(getDisponibilidadeTrabalhoTecnico(tecAnalise) >= getTempoEstimadoTicket(ticketAtual)){
                            int desconto = getTempoEstimadoTicket(ticketAtual);
                            DiminuiDisponibilidadeTecnico(tecAnalise, desconto);
                            finalizaTicket(ticketAtual);
                            if(j < getQtdTicketsNaFila(fila)){
                                j++;
                            }
                            else{
                                break;
                            }
                            
                        }
                    }
                }
                else if(tipoTic== 'O' || tipoTic == 'M'){
                    if(strcmp(getAreaAtuacaoTecnico(tecAnalise), "TI") != 0){
                        if(getDisponibilidadeTrabalhoTecnico(tecAnalise) >= getTempoEstimadoTicket(ticketAtual)){
                            int desconto = getTempoEstimadoTicket(ticketAtual);
                            DiminuiDisponibilidadeTecnico(tecAnalise, desconto);
                            finalizaTicket(ticketAtual);
                            if(j < getQtdTicketsNaFila(fila)){
                                j++;
                            }
                            else{
                                break;
                            }
                        }
                    }
                    
                
                }
            }
            else{
                if(j < getQtdTicketsNaFila(fila)){
                    j++;
                }
                else{
                    break;
                }

            }
        }
        
    }
    if(strcmp(operacao, "NOTIFICA")==0){
        imprimeFilaTickets(fila);
    }
    if(strcmp(operacao, "RANKING TECNICOS")==0){
        
    }

    /*
    E
DISTRIBUI
E
NOTIFICA
E
RANKING TECNICOS
E
RELATORIO
    
    */
    

}

Fila *  operacaoA(Fila  * fila){
    char cpf[MAX_TAM_CPF_USER];
    char tipo[TAM_MAX_OPERACAO];

    scanf("%[^\n]", cpf);
    scanf("%*[\n]");
    scanf("%[^\n]", tipo);
    scanf("%*[\n]");

    if(strcmp(tipo, "OUTROS")==0){
        Outros * out;
        out = lerOutros();
        insereTicketFila(fila, cpf, out, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
    }
    else if(strcmp(tipo, "SOFTWARE")==0){
        Software * soft;
        soft = lerSoftware();
        insereTicketFila(fila, cpf, soft, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
                
    }
    else if(strcmp(tipo, "MANUTENCAO")==0){
        Manutencao * manutencao;
        manutencao = lerManutencao();
        insereTicketFila(fila, cpf, manutencao, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
        
                
    }
    return fila;

}

/*

        scanf("%*[^A-Za-z0-9]");
        scanf("%c\n", &op);
        if(op == 'F'){
            break;
        }
        if(op == 'T'){
            Tecnico * tec;
            tec = lerTecnico();
            VectorPushBack(listaTec, tec);
        }
        if(op == 'U'){
            Usuario * user;
            user = lerUsuario(listaUsuarios, user);
            VectorPushBack(listaUsuarios, user);
        }
        if(op == 'E'){
            char operacao[TAM_MAX_OPERACAO];
            scanf("%[^\n]",operacao);
            scanf("%*[\n]");

            int tamanho = 0, i = 0;
            if(strcmp(operacao, "USUARIOS")==0){
                printf("----- BANCO DE USUARIOS -----\n");
                tamanho  = VectorSize(listaUsuarios);
                for(i = 0; i < tamanho; i++){
                    imprimeElementoVetorDeIdx(listaUsuarios, notificaUsuario, i);
                }
                printf("----------------------------\n");

            }
            if(strcmp(operacao, "TECNICOS")==0){
                printf("----- BANCO DE TECNICOS -----\n");
                tamanho = VectorSize(listaTec);
                for(i = 0; i < tamanho; i++){
                    imprimeElementoVetorDeIdx(listaTec, notificaTecnico, i);
                }
                printf("----------------------------\n");
            }
            
            if(strcmp(operacao, "RELATORIO")==0){
                int mediaIdadeTec = 0, mediaIdadeUser = 0;
                mediaIdadeTec = calculaMediaIdadePorTipo(listaTec, TECNICO);
                mediaIdadeUser = calculaMediaIdadePorTipo(listaUsuarios, USUARIO);

                printf("----- RELATORIO GERAL -----\n");
                
                printf("- Qtd tickets: %d\n- Qtd tickets (A): %d\n- Qtd tickets (F): %d\n", getQtdTicketsNaFila(fila), getQtdTicketsPorStatusNaFila(fila, 'A'), getQtdTicketsPorStatusNaFila(fila, 'F'));
                
                printf("- Qtd usuarios: %d\n- Md idade usuarios: %d\n- Qtd tecnicos: %d\n- Md idade tecnicos: %d\n- Md trabalho tecnicos: %d\n---------------------------\n", VectorSize(listaUsuarios), mediaIdadeUser, VectorSize(listaTec),mediaIdadeTec, 0);
            }
         

            
            
        }
        if(op == 'A'){
            char cpf[MAX_TAM_CPF_USER];
            char tipo[TAM_MAX_OPERACAO];

            scanf("%[^\n]", cpf);
            scanf("%*[\n]");
            scanf("%[^\n]", tipo);
            scanf("%*[\n]");

            if(strcmp(tipo, "OUTROS")==0){
                Outros * out;
                out = lerOutros();
                insereTicketFila(fila, cpf, out, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                
               // notificaTicket(getTicketNaFila(fila, 0));
            }
            else if(strcmp(tipo, "SOFTWARE")==0){
                
            }
            else if(strcmp(tipo, "MANUTENCAO")==0){
                
            }

        
        }


*/