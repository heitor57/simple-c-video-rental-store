#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"
#include "interpretador.h"
int main(){
	int opcao,aux;
	char arqname[tn],str[tn];
	printf("Digite o nome do arquivo para começar. \nArquivo:");
	fgets(arqname,sizeof(arqname),stdin);
	arqname[strcspn(arqname,"\n")] = 0;
	locadora *loc = LeArquivoLocadora(arqname);
	do{
		printf("1-Buscar filmes por ano \n2-Buscar filme por titulo \n3-Rank locações \n4-Aluga \n0- Sair\n");
		scanf("%d",&opcao);
#ifdef __linux__
		system("clear");
#elif WIN32
		system("cls");	
#endif
		switch(opcao){
			case 1:
				printf("Digite o ano:");
				scanf("%d",&aux);
				PrintAnoFilme(loc,aux);
				break;
			case 2:
				setbuf(stdin,NULL);
				printf("Digite o titulo:");
				fgets(str,sizeof(str),stdin);
				str[strcspn(str,"\n")] = 0;
				PrintTituloFilme(loc,str);
				break;
			case 3:
				ranklocacoes(loc);
				break;
			case 4:
				setbuf(stdin,NULL);
				printf("Digite o titulo:");
				fgets(str,sizeof(str),stdin);
				str[strcspn(str,"\n")] = 0;
				alugaTitulo(loc,str);
				break;
		}

	}while(opcao);
	FreeLocadora(loc);
}
