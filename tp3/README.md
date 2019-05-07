# Algoritmos e Estrutura de Dados 1 – Trabalho 3

## Calculadora Polonesa

A notação inversa polonesa  ́e uma notação  matemática posfix, diferente da notaçao matemática infix com a qual estamos acostumados. Ao  inves  do operador estar posicionado entre os operandos, ele est́a posicionado depois.
Por exemplo, na notação polonesa, a expressão
	3 + 5 
é expressa como
	3 5 +
Na prática, uma calculadora que utiliza a notação polonesa  ́e implementada utilizando uma pilha. Toda vez que um numero ́e informado a calculadora, o seu valor  ́e empilhado. Toda vez que uma operaçao  ́e informada, o numero necessario de operandos ́e retirado do topo da pilha, a operação é executada sobre esses operandos e o resultado da operação ́e armazenado na pilha. 
Neste trabalho vocês irão implementar partes de uma calculadora simples(executa operações de adição, subtração, multiplicação e divisão), bem como  partes  das  operaçoes  de  pilha  necessarias  para  que  a  calculadora  execute corretamente.

## Implementação e Execução

A implementação incompleta da calculadora se encontra no arquivo tp3.c e vocês devem completar as seguintes funções:
1.  int isEmpty(Pilha  *  pilha)  :  retorna  1  se  a  pilha  está  vazia,  0  caso contŕario.
2.  void pop(Pilha * pilha) :  remove o elemento do topo da pilha, mas não o retorna.
3.  void soma(Pilha * calculadora) :  caso exista operandos o suficiente na calculadora,  remove  os  dois  elementos  do  topo,  realiza  a  soma  entre esses elementos e armazena o resultado no topo
4.  void divisao(Pilha * calculadora) :  caso exista operandos o suficientena calculadora e o divisor seja válido (diferente de zero), remove os dois elementos do topo, realiza a divisão entre esses elementos e armazenao resultado no topo da pilha.

## Funcionamento

E importante ressaltar que a ordem dos operandos e extremamente importante para a execução.  Os operandos são empilhados na ordem em que se deseja que sejam operados,  ou seja,  o topo da pilha é o segundo operando em uma operação e o segundo elemento da pilha  ́e o primeiro operando da operação.
O funcionamento da calculadora se dá da seguinte maneira: ela se mantém em loop de  entrada  de  dados,  onde  pode  receber  como  entrada  qualquer número em ponto flutuante,  bem como os operadores +,  -,  *,  / e =.  Todo número informado é empilhado e todo operador executa sua operação sobre os operandos na pilha e armazena o resultado, exceto pelo operador =.  Nesse caso, o loop ́e encerrado e o topo da pilha é retornado como resultado, mesmo que hajam mais números empilhados abaixo.

## Avaliação

A função main fornecida a vocês executa uma sequência de testes pré-definida.Porém, nem todas as funcionalidades possíveis são testadas e passar em todos os testes fornecidos não garante nota máxima na avaliação
