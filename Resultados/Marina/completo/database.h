#ifndef _DATABASE_H
#define _DATABASE_H


typedef struct DataBase DataBase;

DataBase * criaDataBase();
void destroiDataBase(DataBase * base);

Vector * retornaListaTecnicos(DataBase * base);
Vector * retornaListaUsuarios(DataBase * base);
Fila * retornaFila(DataBase * base);

int userJaCadastradoBanco(Vector * usuarios, Usuario * user);
int tecnicoJaCadastradoBanco(Vector * tecnicos, Tecnico * tec);

int calculaMediaIdadePorTipo(Vector * v, FuncaoTipo tipo);
int calculaMediaHorasTrabalhadasTecnicos(Vector * listaTec);




#endif
