#include <stdio.h>
#include <stdlib.h>
#include "static.list.h"

#define MAX 100

struct produto{
  int codigo;
  char nome[30];
  float preco;
  int quantidade; 
};

struct lista{
  struct produto *dados[MAX];
  int qtd;
};

Lista* criar_lista(void){

  Lista *li = (Lista *)malloc(sizeof(Lista));

  if (li != NULL) li->qtd = 0;
  
  return li;
}

int full_list(Lista *li){

  // verifica se houve problema na criação da lista
	// ou seja, 'li' não é uma lista válida
  if(li == NULL) return -1;

  // verifica se a lista esta cheia
	if (li->qtd == MAX) 
  {
		return 1;
	}

  // se não estiver cheia, retorna 0
	return 0;
}

int create_product(Produto **product){

  *product = (Produto*)malloc(sizeof(Produto));
  
  if(*product == NULL) return 0;
  
  printf("\nDigite o código do produto: ");
  scanf("%d", &(*product)->codigo);
  printf("Digite o nome do produto: ");
  scanf(" %[^\n]", (*product)->nome);
  printf("Digite o preço do produto: ");
  scanf("%f", &(*product)->preco);
  printf("Digite a quatidade do produto em estoque: ");
  scanf("%d", &(*product)->quantidade);

  return 1;
}

int product_register(Lista *li, Produto *x){ //Recebe a lista e um produto 

  if(li == NULL || x == NULL) return 0;

  if(full_list(li)) return 0;

  li->dados[li->qtd] = x;

  li->qtd++;

  return 1;
}

void low_price(Lista *li){

  int i, idx = 0;
  float menor = li->dados[0]->preco;
  
  if(li == NULL)
  {
    printf("ERR0!\n");
  }
  
  for(i = 1; i < li->qtd; i++)
    if(li->dados[i]->preco < menor){ 
      menor = li->dados[i]->preco;
      idx = i;
    }

  printf("\nCódigo: %d\n", li->dados[idx]->codigo);
  printf("Nome: %s\n", li->dados[idx]->nome);
  printf("Preco: %.2f\n", li->dados[idx]->preco);
  printf("Em estoque: %d\n", li->dados[idx]->quantidade);
}

int remove_elements(Lista *li, int n){
  if (li == NULL)
  {
    return 0;
  }

  li->qtd = li->qtd - n;
  
  return 1;
}

int change_pos(Lista *li, int pos1, int pos2){

  pos1 = pos1 - 1;
  pos2 = pos2 - 1;
  
  if (li == NULL)
  {
    return 0;
  }
  if((pos1 > pos2 && li->qtd-1 < pos1) || (pos2 > pos1 && li->qtd-1 < pos2))
  {
    return 0;
  }

  Produto *temp = li->dados[pos1];
  li->dados[pos1] = li->dados[pos2];
  li->dados[pos2] = temp;

  return 1;
  
}

int print_list(Lista *li) {
	// verifica se a lista foi criada corretamente
	if (li == NULL) {
		return 0;
	}

	for (int i = 0; i < li->qtd; i++) {
		printf("\nCódigo: %d\n", li->dados[i]->codigo);
    printf("Nome: %s\n", li->dados[i]->nome);
    printf("Preço: %.2f\n", li->dados[i]->preco);
    printf("Em estoque: %d\n", li->dados[i]->quantidade);
	}

	return 1;
}

void free_list(Lista *li, Produto *product) {
  
  free(product);
	free(li->dados);
  li -> qtd = 0;
}