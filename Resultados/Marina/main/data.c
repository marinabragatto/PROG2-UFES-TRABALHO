#include "data.h"

struct Data {
    int dia,mes,ano;
};

Data *lerData(){
    Data * d;
    d = (Data*)malloc(sizeof(Data));
    if(d == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }
    scanf("%*[^0-9]");
    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);

    
    return d;
}

void imprimeData(Data *d){
    printf("%d/%d/%d\n",d->dia,d->mes,d->ano);

}


int comparaData(Data *d1, Data *d2){
    if(d1->dia == d2->dia && d1->ano == d2->ano && d1->mes == d2->mes){
        return 1;
    }
    else {
        return 0;
    }
}


int calcularDiffAnosData(Data *inicio, Data *fim){
    int anos = 0;
    anos = fim->ano - inicio->ano;
    if( ((inicio->mes > fim->mes) || (inicio->mes == fim->mes && inicio->dia > fim->dia))){
        anos--;
    }
   
    return  anos;
}


void liberaData(Data *d){
    if(d){
        free(d);
    }
}

Data * criarData(int dia, int mes, int ano){
    Data * d;
    d = (Data*)malloc(sizeof(Data));
    d->ano = ano;
    d->dia = dia;
    d->mes = mes;
    return d;
}