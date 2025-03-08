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
        Ticket * ticketAtual;
       //imprimeFilaTickets(fila);
        int j = 0;
        int k = 0;
        while(j < getQtdTicketsNaFila(fila)){

            ticketAtual = getTicketNaFila(fila, j);
           
            if(getStatusTicket(ticketAtual) != 'A'){
                j++;
                continue;
            }

            char tipoTic = getTipoTicket(ticketAtual);
            int podeAtender = 0;
            int passouPorTodosTec = 0;
            

            while(passouPorTodosTec < VectorSize(listaTec) && k < VectorSize(listaTec)){

                Tecnico * tecAnalise;
                //if(k >= VectorSize(listaTec)){
                  //  break;
               // }
                tecAnalise = VectorGet(listaTec, k);
                
                if (tipoTic == 'S' && strcmp(getAreaAtuacaoTecnico(tecAnalise), "TI") == 0) {
                    podeAtender = 1;
                } else if ((tipoTic == 'O' || tipoTic == 'M') && strcmp(getAreaAtuacaoTecnico(tecAnalise), "TI") != 0) {
                    podeAtender = 1;
                }
                
                passouPorTodosTec++;

                if (podeAtender && getDisponibilidadeTrabalhoTecnico(tecAnalise) >= getTempoEstimadoTicket(ticketAtual)) {

                    int desconto = getTempoEstimadoTicket(ticketAtual);
                    DiminuiDisponibilidadeTecnico(tecAnalise, desconto);
                    incrementaHorasTrabalhadasTecnico(tecAnalise, desconto);
                    finalizaTicket(ticketAtual);
                    //printf("esse cara pegou esse ticket\n\n\n!!!");
                     //   notificaTicket(ticketAtual);
                      //  notificaTecnico(tecAnalise);    
                  //  printf("FIM!!!\n\n\n");
                            
                    k++;
                    break; // Sai do loop porque o ticket foi atribuído
                }
                else{ 
                    k++;
                    if(k >= VectorSize(listaTec) && passouPorTodosTec < VectorSize(listaTec)){
                        k = 0;
                    }
                    else {
                       
                    }
                    
                }

            }

            if(getStatusTicket(ticketAtual) == 'A' && k >= VectorSize(listaTec) ){
                //Chegou ao fim da lista e o ticket continuou em aberto
                k = 0;
                j++;
            }
            else if(getStatusTicket(ticketAtual) == 'F' && k < VectorSize(listaTec)){
                //Conseguiu achar o tecnico e o ticket foi finalizado
                j++;
            }
            else if(getStatusTicket(ticketAtual) == 'F' && k >= VectorSize(listaTec)){
                //Conseguiu achar o tecnico e o ticket foi finalizado, mas esse era o ultimo tecnico da lista, entao iniciamos de novo o loop
                j++;
                k = 0;
            }
            else if(getStatusTicket(ticketAtual) == 'A' && k < VectorSize(listaTec)){
                //isso nao tem como ocorrer pois o loop de cima so eh finalizado quando k >= VectorSize(listaTec) ou quando um ticket é finalizado
                j++;
            }
            // se sair desse segundo while ou significa que conseguiu achar um tecnico para o ticket ou que chegou ao fim dos tecnicos e nenhum resolveu o problema
            

        }
        
    }
    if(strcmp(operacao, "NOTIFICA")==0){
        imprimeFilaTickets(fila);
        
    }
    if(strcmp(operacao, "RANKING TECNICOS")==0){
        imprimeRankingTecnicos(listaTec);
        
    }

    

}

Fila *  operacaoA(Fila  * fila, Vector * listaUsuarios){
    char cpf[MAX_TAM_CPF_USER];
    char tipo[TAM_MAX_OPERACAO];

    scanf("%[^\n]", cpf);
    scanf("%*[\n]");
    scanf("%[^\n]", tipo);
    scanf("%*[\n]");


    // analisar se o cpf existe

    int k = 0;
    
    
    Usuario * pedinte = NULL;
    char * setor ;

    

    for(k = 0; k < VectorSize(listaUsuarios); k++){
        if(comparaUsuariooECpf(VectorGet(listaUsuarios, k), cpf)){
            pedinte = VectorGet(listaUsuarios, k);
            setor = getSetorUsuario(pedinte);
            break;
        }
    }
   


    if(strcmp(tipo, "OUTROS")==0){
        Outros * out;
        out = lerOutros();
        if(pedinte != NULL){
           setTempoEstimadoOutros(out);
            insereTicketFila(fila, cpf, out, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
        }
        else{
            desalocaOutros(out);
        }
        
    }
    else if(strcmp(tipo, "SOFTWARE")==0){
        Software * soft;
        soft = lerSoftware();
        if(pedinte != NULL){
            setTempoEstimadoSoftware(soft);
            //printf("\nsoftware!%d!\n", getTempoEstimadoSoftware(soft));
            insereTicketFila(fila, cpf, soft, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
        }
        else{
            desalocaSoftware(soft);
        }

                
    }
    else if(strcmp(tipo, "MANUTENCAO")==0){
        Manutencao * manutencao;
        manutencao = lerManutencao(setor);
        if(pedinte != NULL){
            setTempoEstimadoManutencao(manutencao);
        //printf("\nmanutencao!%d!\n", getTempoEstimadoManutencao(manutencao));
            insereTicketFila(fila, cpf, manutencao, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
        }
        else {
            desalocaManutencao(manutencao);
        }

                
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