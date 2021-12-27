#include <stdlib.h>
#include "filme.h"
#include "interpretador.h"
#include "conversor.h"
#include <stdio.h>
size_t linebreaks=0;
const char SEPARATOR = ',';
locadora* LeArquivoLocadora(char *fname){
	FILE *f = fopen(fname,"r");
	size_t strsize=0;
	char str[tn],c;
	if(!f){
		fprintf(stderr,"Arquivo não encontrado");
		exit(1);
	}
	while(!feof(f)){
		c=fgetc(f);
		if(c == '\n')
			linebreaks++;
	}
	locadora *l = CriaLocadora(linebreaks);
	fseek(f,0L,SEEK_SET);

	filme *film = CriaFilme();
	while(!feof(f))
	{
		c = fgetc(f);
		if(c=='\n'){
			str[strsize]='\0';
			strsize = 0;
			SetAno(film,stringtoint(str));
			AddFilmeAtt(l,GetTitulo(film),GetAno(film));
		}else if(c==SEPARATOR){
			str[strsize]='\0';
			SetTitulo(film,str);
			strsize = 0;
		}else{
			str[strsize++] = c;
		}
	}
	fclose(f);
	return l;
}
