#include "le.h"

//funcoes da pilha

struct pilha{
   struct llist * l;
};

struct pilha * create_p();

int pop(struct pilha * p);

int push(struct pilha * p, int val);

int vazia_p(struct pilha *p);

void destroy_p(struct pilha * p);

//funcoes da fila

struct fila{
   struct llist * l;
};

struct fila * create_f();

int dequeue(struct fila * f);

int enqueue(struct fila * f, int val);

elem * enqueue_entrada(struct fila * f, char val);

int enqueue_entrada_nodo(struct fila * f, elem * n);

int vazia_f(struct fila * f);

void destroy(struct fila * f);
