#include "pilha.h"
#include <stdlib.h>

struct pilha * create()
{
	struct llist * l= create_l();
	struct pilha * p = (struct pilha *)malloc(sizeof(struct pilha));
	p->l = l;
	return p;
}

int makenull(struct pilha * p)
{
	destroy_l(p->l);
	return 1;
}

int top(struct pilha * p)
{
	elem * top = (elem *)malloc(sizeof(elem));
	top = get_l(p->l, 1);
	
	if(top == NULL)
		return 0;
		
	return top->val;
}

int pop(struct pilha * p)
{
	delete_l(p->l, NULL);
	return 1;
}

int push(struct pilha * p, int val)
{
	elem * new = (elem *)malloc(sizeof(elem));
	new = create_node(val);
	insert_l(p->l, NULL, new);
	return 1;
}
	
int vazia(struct pilha *p)
{
	return get_l(p->l, 1)
		?0
		:1;
}	
	
void destroy(struct pilha * p)
{
	makenull(p);
	free(p);
}
	
	
