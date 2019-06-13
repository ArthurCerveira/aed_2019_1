#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

struct nodo * inicializa_arvore(int entradas, int * valores) {
    struct nodo * raiz = NULL;// = malloc(sizeof(struct nodo));
    int i;
    if(valores != NULL){
        for(i=0;i<entradas;i++) 
            raiz = insere_nodo(raiz, valores[i]);
        return raiz;
    }
    return NULL;
}

struct nodo * insere_nodo(struct nodo * raiz, int valor) {
    struct nodo * new;
    
    if (raiz == NULL) {        
        new = (struct nodo *)malloc(sizeof(struct nodo));
        new->valor = valor;        
        new->esq = NULL;
        new->dir = NULL;
        return new;
    }
    else {
        if(raiz->valor > valor)
            raiz->esq = insere_nodo(raiz->esq, valor);
        else {
            if (raiz->valor < valor)
                raiz->dir = insere_nodo(raiz->dir, valor);
        }
    }
    return raiz;
}

struct nodo * menor_nodo(struct nodo * raiz) {
    struct nodo * menor = raiz;

    while(menor->esq != NULL)
        menor = menor->esq;
    
    return menor;
}

struct nodo * remove_nodo(struct nodo * raiz, int valor) {
    struct nodo * aux;

    
    if(raiz == NULL) 
        return NULL;
    
    if(raiz->valor > valor)
         raiz->esq = remove_nodo(raiz->esq, valor);
    else {
        if(raiz->valor < valor)
            raiz->dir = remove_nodo(raiz->dir, valor);
        else {
            if(raiz->dir && raiz->esq) {
                aux = menor_nodo(raiz->dir);
                raiz->valor = aux->valor;
                raiz->dir = remove_nodo(raiz->dir, raiz->valor);
            } 
            else {
                if(raiz->esq == NULL)
                    aux = raiz->dir;
                else
                    aux = raiz->esq;
                
                free(raiz); 
                return aux;          
            }
        }
    }
    return raiz;  
}

int altura(struct nodo * raiz) {
    int altura_dir = 0, altura_esq = 0;
    
    if(!raiz)
        return 0;
    else {
		altura_esq = altura(raiz->esq);
		altura_dir = altura(raiz->dir);
		if(altura_dir > altura_esq)
			return altura_dir + 1;
		else
			return altura_esq + 1;
	}
    return 0;
}

struct nodo * busca(struct nodo * raiz, int valor){
    if(raiz) {
        if(raiz->valor == valor)
            return raiz;
        if(raiz->esq && raiz->valor > valor)
            raiz = busca(raiz->esq, valor);
        if(raiz->dir && raiz->valor < valor)
            raiz = busca(raiz->dir, valor);
    }
    return NULL;
    
}

int balanceada(struct nodo * raiz) {
    if(raiz) {
        if(raiz->esq && raiz->dir) {
            return (altura(raiz->esq) >= altura(raiz->dir))
                ?altura(raiz->esq) - altura(raiz->dir)
                :altura(raiz->dir) - altura(raiz->esq);
        }
        if(raiz->esq)
            return altura(raiz->esq);
            
        return altura(raiz->dir);
    }
    return 0;
}


int abrangencia(struct nodo * raiz, int * resultado) {
    static int i = 0, aux;
    struct fila * f = create();
    struct nodo * atual = malloc(sizeof(struct nodo));
    atual->valor = 0;

    if (raiz) {
        enqueue(f, raiz);
        while(!vazia(f)) {
            atual = dequeue(f);
            resultado[i] = atual->valor;
            i++;            
            if(atual->esq) 
                enqueue(f, atual->esq);
            if(atual->dir)
                enqueue(f, atual->dir);
        }
    }

    aux = i;
    i = 0;
    return aux;    
}

int prefix(struct nodo * raiz, int * resultado) {
    static int i = 0;
    static int num_elem = 1;

    //num_elem vai armazenar o numero total de elementos da arvore
    if(num_elem < numero_elementos(raiz))
        num_elem = numero_elementos(raiz);
    //testa raiz é NULL
    if(raiz) {
        resultado[i] = raiz->valor;
        i++;
        prefix(raiz->esq, resultado);
        prefix(raiz->dir, resultado);
    }

    //quando i for igual a ao numero total de elementos, volta a ser 0
    if(num_elem == i) {
        i = 0;
        num_elem = 1;
    }
    return i;
}

int numero_elementos(struct nodo * raiz) {
    int cont = 1;
    if(raiz) {
        if(raiz->esq)
            cont = cont + numero_elementos(raiz->esq);
        if(raiz->dir)
            cont = cont + numero_elementos(raiz->dir);
    }
    
    return cont;
}

int postfix(struct nodo * raiz, int * resultado) {
    static int i = 0;
    static int num_elem = 1;

    //num_elem vai armazenar o numero total de elementos da arvore
    if(num_elem < numero_elementos(raiz))
        num_elem = numero_elementos(raiz);

    //testa raiz é NULL
    if(raiz) {
        if(raiz->esq)
            postfix(raiz->esq, resultado);
        if(raiz->dir)
            postfix(raiz->dir, resultado);
        resultado[i] = raiz->valor;
        i++;        
    }

    //quando i for igual a ao numero total de elementos, volta a ser 0
    if(num_elem == i) {
        i = 0;
        num_elem = 1;
    }
    return i;
}

int infix(struct nodo * raiz, int * resultado) {
    static int i = 0;
    static int num_elem = 1;
    //printf("\tvalor armazenado no resultado: %d\n\ti: %d\n\tnum_elem: %d\n\tnum de nodos da raiz: %d\n\n", resultado[i], i, num_elem, numero_elementos(raiz));

    //num_elem vai armazenar o numero total de elementos da arvore
    if(num_elem < numero_elementos(raiz))
        num_elem = numero_elementos(raiz);

    if(raiz) {
        infix(raiz->esq, resultado);
        resultado[i] = raiz->valor;        
        i++;
        infix(raiz->dir, resultado);
    }

    //quando i for igual a ao numero total de elementos, volta a ser 0
    if(num_elem == i) {
        i = 0;
        num_elem = 1;
    }

    return i;
}

void imprime(int * valores, int tamanho){
    int i, cont = 0;
    printf("\t");
    for(i=0;i<tamanho;i++){
        printf("%d ", valores[i]);
        cont++;
        if(cont == 10) {
            printf("\n\t");
            cont = 0;
        }
    }
    printf("\n");
}

void remove_todos(struct nodo * raiz){
    if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        return;
    }
    else{
        if(raiz->esq)
            remove_todos(raiz->esq);
        if(raiz->dir)
            remove_todos(raiz->dir);
    }
}

