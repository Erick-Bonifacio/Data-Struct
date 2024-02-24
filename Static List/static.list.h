
typedef struct produto Produto;
typedef struct lista Lista;

Lista* criar_lista(void); //cria a lista;

int full_list(Lista *li); //verifica se a lista está cheia;

int create_product(Produto **product); //cria um produto modificando uma variavel do tipo Produto na main;

int product_register(Lista *li, Produto *x); //registra um produto na lista;

void low_price(Lista *li); //encontra o menor preço dos produtos inseridos na lista;

int remove_elements(Lista *li, int n); //remove n elementos do fim da lista;

int change_pos(Lista *li, int pos1, int pos2); //troca dois elemntos de posição, de acordo com o usuário;

int print_list(Lista *li); //imprime a lista na tela;

void free_list(Lista *li, Produto *product); // libera a lista;
