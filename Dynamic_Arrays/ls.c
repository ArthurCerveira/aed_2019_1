#include "ls.h"
#include <stdlib.h>

/* Aqui devem ser implementadas as funções definidas em ls.h */

struct list * create(int max)
{
	//alocacao do struct list
	struct list * lista = (struct list *)malloc(sizeof(struct list));
	
	if(max>0)
	{
		lista->capacidade = max;
		lista->ultimo = 0;
		lista->arm = malloc(sizeof(int));
		return lista;
	}
	else
		return NULL;
};

int insert(struct list *desc, int pos, elem item)
{
	int i;
	if((desc->ultimo == desc->capacidade) || (pos > desc->capacidade) || (pos<0))
		return 0;

	for(i=pos;i < desc->ultimo;i++)
	{
		desc->arm[i] = desc->arm[i+1];
	}

	desc->arm[pos] = item;
	
	if(pos > desc->ultimo)
		desc->ultimo = pos;
		
	return 1;
}

int removel(struct list *desc, int pos)
{
	int i;
	
	
	if((pos > desc->ultimo) || (pos<0))
		return 0;
		
	//desc->arm[pos] = 0;
	
	for(i = pos;i < desc->ultimo;i++)
		desc->arm[i] = desc->arm[i+1];
		
	desc->ultimo--;
	
	//se a posicao era a ultima, procura nova ultima posicao
	//if(pos == desc->ultimo)
	//{
	//	desc->ultimo = 0;
	//	for(i = 0;i <= desc->capacidade;i++)
	//	{
	//		if(desc->arm[i] != 0)			
	//			desc->ultimo = i;
	//	}
	//}	
	return 1;
}

elem get(struct list *desc, int pos)
{
	if((pos > desc->ultimo) || (pos < 1))
		return 0;
		
	return desc->arm[pos];
}

int set(struct list *desc, int pos, elem item)
{
	if((pos > desc->ultimo) || (pos < 1))
		return 0;
	
	desc->arm[pos] = item;
	return 1;
}

int locate(struct list *desc, int pos, elem item)
{
	int i;
	if((pos > desc->ultimo) || (pos < 1))
		return 0;
	
	for(i=pos;i <= desc->ultimo;i++)
		if(desc->arm[i] == item)
			return i;
			
	return 0;
}

int length(struct list *desc)
{
	return desc->ultimo;
}

int max(struct list *desc)
{
	return desc->capacidade;
}

int full(struct list *desc)
{
	if(max(desc) == length(desc))
		return 1;
	
	return 0;
}

void destroy(struct list *desc)
{
	free(desc);
}
