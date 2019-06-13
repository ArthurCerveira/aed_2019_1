struct nodo {
	int valor; 
	struct nodo * dir, * esq;
};

typedef struct elem{
  struct nodo * val;
  /* aqui vai o ponteiro para o próximo elemento */
  struct elem * next;
} elem;

struct llist{
  elem * ultimo;
  elem * cabeca;
  int tam;
};

struct llist * create_l();

elem * create_node(struct nodo * val);

int insert_l(struct llist *desc, elem * prev, elem * item);

int delete_l(struct llist *desc, elem * prev);

elem * get_l(struct llist *desc, int pos);

//=====================================================
/** Descritor da fila
  */
struct fila{
   struct llist * l;
};

// typedef elem int;

/** Cria uma fila
 * @return  um descritor ou NULL
 */
struct fila * create();

/** Apaga todos elementos da fila
 * @param p descritor da fila
 * @return 1 se OK, 0 se erro
 */
int makenull(struct fila * f);

/* Retorna o elemento mais antigo da fila ou zero se não existir
 * @param p descritor da fila
 * @return o elemento ou 0
 */
struct nodo * dequeue(struct fila * f);

/* Insere um elemento no fim da fila
 * @param p descritor de fila
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int enqueue(struct fila * f, struct nodo * val);

/* Retorna se a fila está vazia ou não
 * @param p descritor de fila
 * @return 1 se vazia, 0 se não
 */
 int vazia(struct fila * f);
/** Desaloca toda a fila
  * @param p descritor da fila
  */
void destroy(struct fila * f);
