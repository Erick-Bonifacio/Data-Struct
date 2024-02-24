typedef struct descritor Fila;

Fila* criarFila();

int liberarFila(Fila *fi);

int tamanhoFila(Fila *fi);

int enfileirar(Fila *fi, int dado);

int desenfileirar(Fila *fi);