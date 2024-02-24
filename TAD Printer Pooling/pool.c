#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pool.h"

struct elemento{
  char nome[40];
  struct elemento *prox;
};

typedef struct elemento Elemento;

struct descritor {
  Elemento *inicio;
  Elemento *fim;
  int quantidade;
};

Fila* criarFila(){

  Fila *fi = (Fila*)malloc(sizeof(Fila));

  if(fi != NULL) {
    fi->fim = NULL;
    fi->inicio = NULL;
    fi->quantidade = 0;
  };

  return fi;
}

int liberarFila(Fila *fi){

  if(fi == NULL) return 0;

  Elemento *atual;

  while(fi->inicio != NULL){
    atual = fi->inicio;

    fi->inicio = fi->inicio->prox;
    fi->quantidade--;

    free(atual);
  }

  free(fi);

  return 1;
}

int tamanhoFila(Fila *fi){

  if(fi == NULL) return 0;

  return fi->quantidade;
}

Elemento* criarElemento(){
  return (Elemento*)malloc(sizeof(Elemento));
}

int enfileirar(Fila *fi, char nomeRecebido[]){
  if(fi == NULL) return 0;

  Elemento *novo = criarElemento();

  if(novo == NULL) return 0;

  strcpy(novo->nome,nomeRecebido);
  novo->prox = NULL;

  if(fi->fim == NULL) fi->inicio = novo;

  else fi->fim->prox = novo;

  fi->fim = novo;
  fi->quantidade++;
  return 1;
}

char* desenfileirar(Fila *fi){

  if(fi == NULL) return 0;

  if(fi->inicio == NULL) return 0;

  char *nome = (char *)malloc(40 * sizeof(char));
  strcpy(nome, fi->inicio->nome);

  Elemento *atual = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quantidade--;

  free(atual);

  return nome;
}

int imprimeFila(Fila *fi){

  if(fi == NULL) return 0;

  if(fi->inicio == NULL) return 0;

  Elemento *atual = fi->inicio;

  int i = 1;
  while(atual != NULL){
    printf("%d° - %s\n", i, atual->nome);
    i++;
    atual = atual->prox;
  }
  
  return 1;
}