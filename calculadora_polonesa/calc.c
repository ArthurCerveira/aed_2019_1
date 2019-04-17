#include "calc.h"
#include <stdlib.h>
#include <stdio.h>

int calculadora(char * expr, int * err)
{
	int i = 0, ans = 0;
	struct fila * in_f;//, * pos_f;
	elem * test_node;
	
	in_f = create_f();
	
	printf("\tcriou in_f\n");
	if(expr != NULL)
	{
		printf("\tentrou no if\n");
		//insere os caracteres da string na fila infix
		while(expr[i] != '\0')
		{
			//printf("\tentrou no while\n");
			//se o numero eh impar, o caractere deve ser espaço
			if((i % 2) != 0)
			{
				//se nao for espaco, eh mal formada
				if(expr[i] != ' ')
				{
					* err = MALFORMADA;
					return 0; 
				}		
			}		
			
			//printf("\tchegou aqui 2\n");
			test_node = enqueue_entrada(in_f, expr[i]);	
			
			//se o caractere eh invalido, eh mal formada
			if(test_node->e->oper == invalido)
			{
				* err = MALFORMADA;
				return 0;
			}
			i++;
		}
	}
	printf("\tnao entrou no while\n");
	//pos_f recebe a expressao pos-fixada
	//pos_f = infix_to_posfix(in_f);
	
		
	if(expr == NULL)
		*err = MALFORMADA;
		
	if(* err == MALFORMADA)
		return 0;
		
	return ans;
}

struct fila * infix_to_posfix(struct fila * e)
{
	struct pilha * p = create_p();
	struct fila * s = create_f();
	elem * aux;//, * aux_p;//, * aux_s;
	
	//Para cada elemento x retirado de E:
	for(aux = e->l->cabeca; aux != NULL; aux = aux->next)
	{	
    //Caso x for:
		//operando: Coloque em S
		if(aux->e->tipo == num)
			enqueue_entrada_nodo(s, aux); 			
		else {
		// ( : coloque em P
			if(aux->e->oper == abrepar)
				push(p, aux->e->oper);
			
		// ) : tire operadores de P até encontrar (, adicionando-os a S
			if(aux->e->oper == fechapar)
			{
				while(get_l(p->l, 1) != abrepar)
				{
					enqueue_entrada_nodo(s, get_l(p->l, 1));
					pop(p);
				}
			}			
		    //operador: tire operadores de S enquanto topo de P tiver precedência maior ou igual a x ou (, coloque em S
		    //testa a precedencia
			while(precedencia(get_l(p->l, 1), aux->e->oper))
			{
				if(get_l(s->l, 1)->e->tipo == op)
				{
					dequeue(s);
					
				}
				
			}	
				
		}	
	}
					
			//coloque x em P

	//Tire todos os operandos de P e coloque em S
	return s;
}

//int precedencia(elem * e1, elem * e2)
//{
	//int e_v1, e_v2;
	
	
//}
