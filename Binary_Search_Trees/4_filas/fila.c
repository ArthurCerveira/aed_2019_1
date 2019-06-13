#include "fila.h"
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

elem * create_node(struct nodo * val)
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


//======================================================================


struct fila * create()
{
	struct llist * l= create_l();
	struct fila * f = (struct fila *)malloc(sizeof(struct fila));
	f->l = l;
	return f;
}

struct nodo * dequeue(struct fila * f)
{
	elem * aux = get_l(f->l, 1);
	struct nodo * val;
	
	if(aux == NULL)
		return 0;
	
	val = aux->val;
	
	delete_l(f->l, NULL);
	
	return val;
}

int enqueue(struct fila * f, struct nodo * val)
{
	elem * node;
	node = create_node(val);
	
	if(vazia(f))
	{
		insert_l(f->l, NULL, node);	
		f->l->ultimo = node;
		return 1;
	}
	
	insert_l(f->l, f->l->ultimo, node);
	f->l->ultimo = node;
		
	return 1;
}

int vazia(struct fila * f)
{
	return get_l(f->l, 1)
		?0
		:1;
}

int makenull(struct fila * f)
{
	int i, aux = f->l->tam;
	
	for(i=0;i < aux; i++)
		delete_l(f->l, NULL);		
	
	
	return 1;
}
