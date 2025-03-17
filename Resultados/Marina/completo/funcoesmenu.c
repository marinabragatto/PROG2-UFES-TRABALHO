#include "funcoesmenu.h"



Vector * operacaoT(Vector * tecnicos){
    Tecnico * tec;
    tec = lerTecnico();
    if(!tecnicoJaCadastradoBanco(tecnicos, tec)){
        VectorPushBack(tecnicos, tec);
    }
    else{
        desalocaTecnico(tec);
    }
    
    return tecnicos;
}

Vector * operacaoU(Vector * usuarios){
    Usuario * user;
    user = lerUsuario();

    if(!userJaCadastradoBanco(usuarios, user)){
        VectorPushBack(usuarios, user);
    }
    else{
        desalocaUsuario(user);
    }

    return usuarios;
}

void operacaoE(Vector * listaTec, Vector * listaUsuarios, Fila * fila){
    char operacao[TAM_MAX_OPERACAO];
    scanf("%[^\n]", operacao);
    scanf("%*[\n]");




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
       
        int j = 0;
        int k = 0;

        for(j = 0; j < getQtdTicketsNaFila(fila); j++){
            ticketAtual = getTicketNaFila(fila, j);
            if(getStatusTicket(ticketAtual) != 'A'){
                continue;
            }
            int passouPorTodosTec = 0; // Conta por quantos técnicos passou um ticket
            for(;passouPorTodosTec<VectorSize(listaTec) && k < VectorSize(listaTec); ){
                Tecnico * tecAnalise;
                tecAnalise = VectorGet(listaTec, k);
                if(tecnicoPodePegarTicket(tecAnalise, ticketAtual)){
                    tecAnalise = tecnicoRecebeTicket(tecAnalise, ticketAtual);
                    finalizaTicket(ticketAtual);         
                    k++;
                    passouPorTodosTec++;
                    break; // Sai do loop porque o ticket foi atribuído
                }
                else{ 
                    passouPorTodosTec++;
                    k++;
                    if(k >= VectorSize(listaTec) && passouPorTodosTec < VectorSize(listaTec)){
                        k = 0;
                    }
                }
            }
            if(getStatusTicket(ticketAtual) == 'F' && k >= VectorSize(listaTec)){
                //Conseguiu achar o tecnico e o ticket foi finalizado, mas esse era o ultimo tecnico da lista, entao iniciamos de novo o loop
                k = 0;
            }
        }
        
    }
    if(strcmp(operacao, "NOTIFICA")==0){
        imprimeFilaTickets(fila);
        
    }
    if(strcmp(operacao, "RANKING TECNICOS")==0){
        imprimeRankingTecnicos(listaTec);
        
    }
    if(strcmp(operacao, "RANKING USUARIOS")==0){
        imprimeRankingUsuarios(listaUsuarios);
    }
    

    

}

Fila *  operacaoA(Fila  * fila, Vector * listaUsuarios){
    char cpf[MAX_TAM_CPF_USER];
    char tipo[TAM_MAX_OPERACAO];

    scanf("%[^\n]", cpf);
    scanf("%*[\n]");
    scanf("%[^\n]", tipo);
    scanf("%*[\n]");
    

    int k = 0;
    
    
    Usuario * pedinte = NULL;
    char setor[MAX_TAM_SETOR_USER];
    setor[0] = '\0'; 

    
    // Analisar se o cpf existe, se pedinte == NULL, o ticket é ignorado
    for(k = 0; k < VectorSize(listaUsuarios); k++){
        if(comparaUsuariooECpf(VectorGet(listaUsuarios, k), cpf)){
            pedinte = VectorGet(listaUsuarios, k);
            incrementaQtdTicketsSolicitados(pedinte);
            strcpy(setor, getSetorUsuario(pedinte));
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
            insereTicketFila(fila, cpf, manutencao, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
        }
        else {
            desalocaManutencao(manutencao);
        }

                
    }
    return fila;

}

/*
           if(getStatusTicket(ticketAtual) == 'A' && k >= VectorSize(listaTec) ){
                //Chegou ao fim da lista e o ticket continuou em aberto
                k = 0;
        
            }
            else if(getStatusTicket(ticketAtual) == 'F' && k < VectorSize(listaTec)){
                //Conseguiu achar o tecnico e o ticket foi finalizado
              
            }
            else if(getStatusTicket(ticketAtual) == 'F' && k >= VectorSize(listaTec)){
                //Conseguiu achar o tecnico e o ticket foi finalizado, mas esse era o ultimo tecnico da lista, entao iniciamos de novo o loop
                k = 0;
            }
            else if(getStatusTicket(ticketAtual) == 'A' && k < VectorSize(listaTec)){
                //isso nao tem como ocorrer pois o loop de cima so eh finalizado quando k >= VectorSize(listaTec) ou quando um ticket é finalizado
            }
            // se sair desse segundo while ou significa que conseguiu achar um tecnico para o ticket ou que chegou ao fim dos tecnicos e nenhum resolveu o problema


*/
