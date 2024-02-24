#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elementoNumerico{
  int dado;
  struct elementoNumerico *prox;
};

typedef struct elementoNumerico ElementoNumerico;

struct descritor {
  ElementoNumerico *inicio;
  ElementoNumerico *fim;
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

  ElementoNumerico *atual;

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

ElementoNumerico* criarElemento(){
  return (ElementoNumerico*)malloc(sizeof(ElementoNumerico));
}

int enfileirar(Fila *fi, int dado){
  if(fi == NULL) return 0;

  ElementoNumerico *novo = criarElemento();

  if(novo == NULL) return 0;
  
  novo->dado = dado;
  novo->prox = NULL;

  if(fi->fim == NULL) fi->inicio = novo;

  else fi->fim->prox = novo;

  fi->fim = novo;
  fi->quantidade++;
  return 1;
}

int desenfileirar(Fila *fi){

  if(fi == NULL) return 0;

  if(fi->inicio == NULL) return 0;

  int dado = fi->inicio->dado;
  
  ElementoNumerico *atual = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quantidade--;

  free(atual);

  return dado;
}

