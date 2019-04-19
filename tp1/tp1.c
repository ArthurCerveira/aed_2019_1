#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char * nome;
	struct node * prox;
}node;

typedef struct list
{
	node * cabeca;
	node * ultimo;
}lista;

int insere(lista * l);

int main()
{
	node * temp;
	lista * l = malloc(sizeof(lista));
	l->cabeca = malloc(sizeof(node));
	l->ultimo = l->cabeca;
	
	while(insere(l));
	
	for(temp = l->cabeca->prox; temp != NULL; temp = temp->prox)
	{
		printf("%s\n", temp->nome);
		free(temp);
	}
	
	free(l->cabeca);
	free(l->ultimo);
	free(l);
	
	return 0;
}

int insere(lista * l)
{
	node * new = malloc(sizeof(node));
	new->nome = malloc(20 * sizeof(char));
	new->prox = NULL;
	
	printf("Entre um nome: ");
			
	if(scanf("%[^\n]", new->nome) == 1)
	{
		getchar();
		l->ultimo->prox = new;
		l->ultimo = new;
		return 1;
	}
	
	return 0;
}
