#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pool.h"

typedef struct arquivo{
  char nomeArquivoRecebidoImp[40];
}Arquivo;

typedef struct impressora{
  Arquivo arquivosRecebidos[40];
  int qtdArquivos;
}Impressora;

int main(void) {

  Fila *fi = criarFila();
  Impressora imp[5];
  int qtdArquivos = 0;
  Arquivo copoiaArq;
  char arqRecebido[40];
  int opcao, ok, cont = 0;
  char *nome = (char *)malloc(40 * sizeof(char));

  for(int i = 0; i < 5; i++){
    imp[i].arquivosRecebidos[0].nomeArquivoRecebidoImp[0] = '\0';
    imp[i].qtdArquivos = 0;
  }

  do {
      printf("\nMenu de Opcoes:\n");
      printf("1. Inserir arquivo na fila\n");
      printf("2. Mostrar fila\n");
      printf("3. Mandar o próximo arquivo para impressão\n");
      printf("4. Mostrar historico\n");
      printf("0. Sair\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
          case 1:
            printf("Digite o nome do arquivo: ");
            scanf("%s", arqRecebido);
            ok = enfileirar(fi, arqRecebido);
            if(ok == 0) printf("Sem arquivo!\n");
            else printf("\nArquivo inserido com sucesso!\n");
            break;

          case 2:
            printf("\n>> Fila de arquivos <<\n");
            ok = imprimeFila(fi);
            if(ok == 0) printf("\nFila Vazia!\n");
            else printf("\nFila impressa com sucesso!\n");
            break;

          case 3:
            nome = desenfileirar(fi);
            if(nome == NULL) printf("\nNada para desenfileirar!\n");
            else{
              strcpy(imp[cont].arquivosRecebidos[imp[cont].qtdArquivos].nomeArquivoRecebidoImp, nome);
              imp[cont].qtdArquivos++;
              printf("\nArquivo '%s' enviado para a impressora %d!\n", nome, cont + 1);
              cont++;
              if (cont == 5) cont = 0;
            }
            break;

          case 4:
              printf("\nHistórico de impressões:\n");
              for(int j = 0; j < 5; j++){
                printf("Impressora %d:\n", j + 1);
                if(imp[j].qtdArquivos == 0) printf("Nenhum arquivo enviado!\n");
                else
                  for(int i = 0; i < imp[j].qtdArquivos; i++){
                    printf("- %s\n", imp[j].arquivosRecebidos[i].nomeArquivoRecebidoImp);
                  }
                printf("\n----------------\n\n");
              }
              break;

          case 0:
              printf("Saindo do programa.\n");
              break;

          default:
              printf("\nOpcao invalida. Tente novamente.\n");
      }

  }while(opcao != 0);
  return 0;
}
