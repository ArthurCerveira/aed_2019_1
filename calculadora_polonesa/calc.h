#include "p_f.h"
//#ifndef _CALC_H_
#define _CALC_H_


#define OK 1
#define MALFORMADA 0


/** Função que recebe uma expressão infix e calcula seu resultado
  * @param expr string terminada por \0 contendo a expressão
  * @param err código de erro
  * @return valor da expressão
  */ 
int calculadora(char * expr, int * err);

/** Definições auxiliares para ajudar na implementação.
  * Seu uso não é obrigatório. Veja o README.md.
  */
//enum operacao {abrepar, fechapar, expon, multip, divisao, resto, adicao, subtracao};

//enum num_ou_op {num, op};

struct fila * infix_to_posfix(struct fila * e);

//int precedencia(

//struct entrada{
//    int numero;
//    enum operacao oper;
//    enum num_ou_op tipo;
//};

//enum num_ou_op n_ou_p();



//#endif _CALC_H_
