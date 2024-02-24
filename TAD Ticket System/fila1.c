#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila1.h"

struct elementoSenha{
  char senha[4];
  struct elementoSenha *prox;
};

typedef struct elementoSenha ElementoSenha;

struct descritor2 {
  ElementoSenha *inicio;
  ElementoSenha *fim;
  int quantidade;
};

Fila2* criarFila2(){

  Fila2 *fi = (Fila2*)malloc(sizeof(Fila2));

  if(fi != NULL) {
    fi->fim = NULL;
    fi->inicio = NULL;
    fi->quantidade = 0;
  };

  return fi;
}

int liberarFila2(Fila2*fi){

  if(fi == NULL) return 0;

  ElementoSenha *atual;

  while(fi->inicio != NULL){
    atual = fi->inicio;

    fi->inicio = fi->inicio->prox;
    fi->quantidade--;

    free(atual);
  }

  free(fi);

  return 1;
}

int tamanhoFila2(Fila2 *fi){

  if(fi == NULL) return 0;

  return fi->quantidade;
}

ElementoSenha* criarElemento2(){
  return (ElementoSenha*)malloc(sizeof(ElementoSenha));
}

int enfileirar2(Fila2 *fi, char senha[]){
  if(fi == NULL) return 0;

  ElementoSenha *novo = criarElemento2();

  if(novo == NULL) return 0;

  strcpy(novo->senha, senha);
  novo->prox = NULL;

  if(fi->fim == NULL) fi->inicio = novo;

  else fi->fim->prox = novo;

  fi->fim = novo;
  fi->quantidade++;
  return 1;
}

int desenfileirar2(Fila2*fi, char senha[]){

  if(fi == NULL) return 0;

  if(fi->inicio == NULL) return 0;

  strcpy(senha, fi->inicio->senha);

  ElementoSenha *atual = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quantidade--;

  free(atual);

  return 1;
}