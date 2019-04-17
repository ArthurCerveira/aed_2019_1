#include "p_f.h"
#include <stdlib.h>

//funcoes da pilha

struct pilha * create_p()
{
	struct llist * l= create_l();
	struct pilha * p = (struct pilha *)malloc(sizeof(struct pilha));
	p->l = l;
	return p;
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
	
int vazia_p(struct pilha *p)
{
	return get_l(p->l, 1)
		?0
		:1;
}	
	
void destroy_p(struct pilha * p)
{
	destroy_l(p->l);
	free(p);
}

//funcoes da fila

struct fila * create_f()
{
	struct llist * l= create_l();
	struct fila * f = (struct fila *)malloc(sizeof(struct fila));
	f->l = l;
	return f;
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
	elem * aux;	
	node = create_node(val);
	
	if(vazia_f(f))
	{
		insert_l(f->l, NULL, node);	
		return 1;
	}
	
	//encontra o fim
	for(aux = f->l->cabeca; aux->next != NULL; aux = aux->next);
		
	insert_l(f->l, aux, node);		
	return 1;
}

elem * enqueue_entrada(struct fila * f, char val)
{
	elem * node;
	elem * aux;
	
	
	node = (elem *)malloc(sizeof(elem));
	node->e = (struct entrada *)malloc(sizeof(struct entrada));	
	
	//testa se val eh numero
	if(val > 47 && val < 58)
	{
		node->e->numero = val - 48;
		node->e->tipo = num;
	}
	else
	{
		//senao, eh operacao
		node->e->tipo = op;
		switch(val)
		{
			case '(':
				node->e->oper = abrepar;
				break;
			case ')':
				node->e->oper = fechapar;
				break;
			case '^':
				node->e->oper = expon;
				break;
			case '*':
				node->e->oper = multip;
				break;
			case '/':
				node->e->oper = divisao;
				break;
			case '%':
				node->e->oper = resto;
				break;
			case '+':
				node->e->oper = adicao;
				break;
			case '-':
				node->e->oper = subtracao;
				break;
			default:
				node->e->oper = invalido;
		}
	}
		
	node->next = NULL;
	
	if(vazia_f(f))
	{
		insert_l(f->l, NULL, node);	
		return node;
	}
	
	for(aux = f->l->cabeca; aux->next != NULL; aux = aux->next);
		
	insert_l(f->l, aux, node);		
	return node;
}

int enqueue_entrada_nodo(struct fila * f, elem * n)
{
	elem * aux;
	n->next = NULL;
	
	if(vazia_f(f))
	{
		insert_l(f->l, NULL, n);	
		return 1;
	}
	for(aux = f->l->cabeca; aux->next != NULL; aux = aux->next);
		
	insert_l(f->l, aux, n);
	return 1;
}

int vazia_f(struct fila * f)
{
	return get_l(f->l, 1)
		?0
		:1;
}

void destroy(struct fila * f)
{
	int i, aux = f->l->tam;
	
	for(i=0;i < aux; i++)
	{
		delete_l(f->l, NULL);		
	}
	
	free(f);
}
