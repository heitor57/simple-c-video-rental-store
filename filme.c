#include "filme.h"
#include "interpretador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char padraosaida[] = "%s,ano %d, locações %d\n";
typedef struct filme{
	char titulo[tn];
	int ano,locacoes;
}filme;
typedef struct locadora{
	size_t qnt,max;
	filme *filmes;
}locadora;

locadora* CriaLocadora(size_t tamanho){
	locadora *l = malloc(sizeof(locadora));
	if(l != NULL){
		l->qnt = 0;
		SetMax(l,tamanho);
	}
	return l;
}
void SetMax(locadora *l,size_t size){
	size_t tamanho =GetTamanho(size);
	l->filmes = malloc(tamanho);
	l->max = tamanho/size;
}
size_t GetTamanho(size_t size){
	return sizeof(filme)*size;
}
void AddFilme(locadora *l,filme f){
	if(l->qnt==l->max || l == NULL)
		return;
	strcpy(l->filmes[l->qnt].titulo,f.titulo);
	l->filmes[l->qnt].ano = f.ano;
	l->filmes[l->qnt++].locacoes = f.locacoes;
}

void AddFilmeAtt(locadora *l,char* titulo,int ano){
	if(l->qnt==l->max || l == NULL)
		return;
	strcpy(l->filmes[l->qnt].titulo,titulo);
	l->filmes[l->qnt].ano = ano;
	l->filmes[l->qnt++].locacoes = 0;
}
filme *CriaFilme(){
	filme *f = malloc(sizeof(filme));
	f->locacoes = 0;
	return f;
}
void SetTitulo(filme *f,char *titulo)
{
	if(!f)
		return;
	strcpy(f->titulo,titulo);
}

char* GetTitulo(filme *f){
	return f->titulo;
}

void SetAno(filme *f,int ano)
{
	if(!f)
		return;
	f->ano=ano;
}

int GetAno(filme *f){
	return f->ano;
}

void SetLocacoes(filme *f,int locacoes){
	f->locacoes=locacoes;
}
int GetLocacoes(filme *f){
	return f->locacoes;
}

locadora* AnoFilme(locadora *l,int ano){
	locadora *lnew=CriaLocadora(linebreaks);
	for(int i = 0; i<l->qnt;i++)
		if(ano == l->filmes[i].ano){
			AddFilme(lnew,l->filmes[i]);
		}
	return lnew;
}
void PrintAnoFilme(locadora *l,int ano){
	locadora *li = AnoFilme(l,ano);
	for(int i = 0; i < li->qnt;i++){
		printf(padraosaida,li->filmes[i].titulo,li->filmes[i].ano,li->filmes[i].locacoes);
	}
	FreeLocadora(li);
}
filme TituloFilme(locadora *l,char *titulo){
	filme f = {"",0,0};
	for(int i = 0; i<l->qnt;i++)
		if(!strcmp(titulo,l->filmes[i].titulo))
			return l->filmes[i];
	return f;
}

void PrintTituloFilme(locadora *l,char *titulo){

	filme f = TituloFilme(l,titulo);
	if(strcmp(f.titulo,""))
	printf(padraosaida,f.titulo,f.ano,f.locacoes);
}
void alugaTitulo(locadora *l,char *fname){
	for(int i = 0;i<l->qnt;i++)
		if(!strcmp(fname,l->filmes[i].titulo)){
			aluga(&(l->filmes[i]));
			break;
		}
}
void aluga(filme *f)
{
	if(f != NULL)
		f->locacoes++;
}
void ranklocacoes(locadora *l){
	filme aux;
	locadora *lsort = CriaLocadora(linebreaks);
	for(int i =0;i<l->qnt;i++)
		AddFilme(lsort,l->filmes[i]);
	for(int i =0;i<lsort->qnt;i++)
		for(int j=i;j<lsort->qnt;j++)
			if(lsort->filmes[i].locacoes <= lsort->filmes[j].locacoes)
			{
				aux = lsort->filmes[i];
				lsort->filmes[i]=lsort->filmes[j];
				lsort->filmes[j]=aux;
			}
	for(int i = 0;i<lsort->qnt;i++)
		printf(padraosaida,lsort->filmes[i].titulo,lsort->filmes[i].ano,lsort->filmes[i].locacoes);
	FreeLocadora(lsort);
}
void FreeLocadora(locadora *l){
	if(l->max>0)
		free(l->filmes);
	free(l);
}
