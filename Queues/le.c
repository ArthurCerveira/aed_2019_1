#include "le.h"
#include <stdlib.h>

struct llist * create_l()
{
	struct llist * start;
	start = (struct llist *)malloc(sizeof(struct llist));
	start->cabeca = (elem *)malloc(sizeof(elem));
	start->cabeca->next = NULL;
	start->tam = 0;
	start->ultimo = NULL;
	
	return start;	
}

elem * create_node(int val)
{
	elem * new;
	new = (elem *)malloc(sizeof(elem));
	
	new->val = val;	
	new->next = NULL;
	
	return new;
}

int insert_l(struct llist *desc, elem * prev, elem * item)
{
	desc->tam++;
	//NULL se início da lista
	if (prev == NULL)
	{
		item->next = desc->cabeca->next;
		desc->cabeca->next = item;
		//o primeiro elemento inserido sera o ultimo se prev = NULL
		if(desc->tam == 1)
			desc->ultimo = item;
		return 1;
	}
	//prev nodo anterior
	item->next = NULL;
	prev->next = item;
	desc->ultimo = item;
	return 1;
}

int delete_l(struct llist *desc, elem * prev)
{
	elem * aux;
	
	if(prev != NULL)
	{
		for(aux= desc->cabeca->next;aux != NULL;aux=aux->next)
		{
			if(aux == prev)
			{
				aux = prev->next;
				prev->next = aux->next;
				free(prev->next);
				desc->tam--;
				return 1;
			}
		}
	}
	else
	{
		aux = desc->cabeca->next;
		desc->cabeca->next = aux->next;
		free(aux);
		desc->tam--;
		return 1;
	}
	
	return 0;
}
		
	
elem * get_l(struct llist *desc, int pos)
{
	elem * aux = desc->cabeca->next;
	int i;
	
	if((pos > desc->tam) || (pos < 0))
		return NULL;
		
	for(i=1;i<pos;i++)
		aux = aux->next;
	
	return aux;
}	

int set_l(struct llist *desc, int pos, int val)
{
	elem * aux = desc->cabeca->next;
	int i;
	
	if((pos > desc->tam) || (pos < 0))
		return 0;
		
	for(i=1;i < pos;i++)
		aux = aux->next;
		
	aux->val = val;
	
	return 1;
}

elem * locate_l(struct llist *desc, elem * prev, int val)
{
	elem * aux, * aux2;
	//se prev= NULL, vai desde o comeco
	if(prev == NULL)
		prev = desc->cabeca;
		
		
	for(aux = prev->next; aux->next != NULL; aux = aux->next)
	{
		aux2 = aux->next;
		if(aux->val == val)
			return aux;
		if(aux2->val == val)
			return aux2;
	}
	
	return NULL;
}	
			

int length_l(struct llist *desc)
{
	return desc->tam;
}

void destroy_l(struct llist *desc)
{
	int i, tam = desc->tam;
	
	for(i=0;i<tam;i++)
	{
		delete_l(desc, NULL);
	}
	
	free(desc->cabeca);
	free(desc->ultimo);
	free(desc);
}
