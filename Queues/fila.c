#include "fila.h"
#include <stdlib.h>
//#include <stdio.h>

struct fila * create()
{
	struct llist * l= create_l();
	struct fila * f = (struct fila *)malloc(sizeof(struct fila));
	f->l = l;
	return f;
}

int makenull(struct fila * f)
{
	int i, aux = f->l->tam;
	
	for(i=0;i < aux; i++)
	{
		//printf("\tf->l->tam = %d\n\ti = %d", f->l->tam, i);
		delete_l(f->l, NULL);		
	}
	//printf("\tf->l->tam = %d\n", f->l->tam);
	//delete_l(f->l, NULL);
	
	//destroy_l(f->l);	
	return 1;
}

int dequeue(struct fila * f)
{
	elem * aux = get_l(f->l, 1);
	int val;
	
	if(aux == NULL)
		return 0;
	
	val = aux->val;
	
	delete_l(f->l, NULL);
	
	return val;
}

int enqueue(struct fila * f, int val)
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

void destroy(struct fila * f)
{
	makenull(f);
	free(f);
}
