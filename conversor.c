#include <string.h>
#include <math.h>
#include "conversor.h"
const char simbolos[] = "0123456789";
int chartoint(char simbolo){
	for(int i = 0;i<sizeof(simbolos);i++)
		if(simbolo == simbolos[i])
			return i;
	return 0;
}

int stringtoint(char *str){
	int result=0;
	for(int i = strlen(str)-1,exp = 0 ;i>=0;i--,exp++){
		result += chartoint(str[i])*pow(10,exp);
	}
	return result;
}
