typedef struct descritor Fila;

Fila* criarFila();

int liberarFila(Fila *fi);

int tamanhoFila(Fila *fi);

int enfileirar(Fila *fi, char nomeRecebido[]);

char* desenfileirar(Fila *fi);

int imprimeFila(Fila *fi);