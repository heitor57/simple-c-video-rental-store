#ifndef FILME_H
#define FILME_H
#include <stddef.h>
#define tn 50

typedef struct filme filme;
typedef struct locadora locadora;

locadora* CriaLocadora(size_t tamanho);
void SetMax(locadora *l,size_t size);
size_t GetTamanho(size_t size);
void AddFilme(locadora *l,filme f);
void AddFilmeAtt(locadora *l,char* titulo,int ano);
filme *CriaFilme();
void SetTitulo(filme *f,char *titulo);
char* GetTitulo(filme *f);
void SetAno(filme *f,int ano);
int GetAno(filme *f);
void SetLocacoes(filme *f,int locacoes);
int GetLocacoes(filme *f);
locadora* AnoFilme(locadora *l,int ano);
void PrintAnoFilme(locadora *l,int ano);
filme TituloFilme(locadora *l,char *titulo);
void PrintTituloFilme(locadora *l,char *titulo);
void alugaTitulo(locadora *l,char *fname);
void aluga(filme *f);
void ranklocacoes(locadora *l);
void FreeLocadora(locadora *l);
#endif
