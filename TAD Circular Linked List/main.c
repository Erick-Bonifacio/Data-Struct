
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "list.h"

int criar_dado(int *dado);
void checar_sucesso(int ok);

// funcao principal
int main(void) {
  
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  int opcao, dado, ok, pos, num;
  Lista *li_dois = NULL;

  li_dois = criar_lista();
  ok = inserir_lista_final(li_dois, 1);
  checar_sucesso(ok);
  ok = inserir_lista_final(li_dois, 2);
  checar_sucesso(ok);
  ok = inserir_lista_final(li_dois, 3);
  checar_sucesso(ok);
  ok = inserir_lista_final(li_dois, 4);
  checar_sucesso(ok);
  ok = inserir_lista_final(li_dois, 5);
  checar_sucesso(ok);

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Concatenar listas");
    printf("\n12 - Unir as duas listas (s/ repetição numérica)");
    printf("\n13 - Reverter lista");
    printf("\n14 - Checar ordem da lista");
    printf("\n15 - Imprimir lista");
    printf("\n16 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1: 

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2: 
        
        // liberar lista
        ok = liberar_lista(li);
        li = NULL; 

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        ok = criar_dado(&dado);               
        ok = inserir_lista_inicio(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_lista_final(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        ok = inserir_lista_ordenada(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:    

        // remover elemento do início 
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:    

        // remover elemento do final 
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:    
      
        // remover elemento do meio 
        printf("\n Código a ser removido: ");
        scanf("%d", &dado); 

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 9:
      
        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos); 

        ok = buscar_lista_posicao(li, pos, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:
      
        // busca elemento pelo dado
        printf("\n Código a ser buscado: ");
        scanf("%d", &dado); 

        ok = buscar_lista_dado(li, dado, &pos);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com código %d na lista: ", dado);
          printf("%d", pos);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:

        ok = append_list(li,li_dois);
        li_dois = NULL;
        checar_sucesso(ok);
        printf("\nListas concatenadas!\n");
        
        break;
      
      case 12:

        ok = remove_repeated_numbers(li, li_dois);
        checar_sucesso(ok);
        printf("\nUnião concluída!\n");
        
        break;
      
      case 13:

        ok = reverse_list(li, li_dois);
        checar_sucesso(ok);
        printf("\nLista revertida");
        break;
      
      case 14:

        ok = check_ordering(li);
        
        if(ok == 1){
          printf("\nlista ordenada de forma crescente!\n");
        }
        else if(ok == 2){
          printf("\nlista ordenada de forma decrescente!\n");
        }
        else if(ok == 3){
          printf("\nlista desordenada!\n");
        }
        else if(ok == 4){
          printf("\nLista com apenas um elemento!\n");
        }
        
        break;

      case 15:
        
        printf("Digite qual lista deseja imprimir (1/2 ou 3 p/ ambas): ");
        scanf("%d", &num);
        if(num == 1 || num == 3){
          printf("\n Lista encadeada circular 1: ");
          ok = imprimir_lista(li);  
          checar_sucesso(ok);
        }
        if(num == 2|| num == 3){
          printf("\n Lista encadeada circular 2: ");
          ok = imprimir_lista(li_dois);  
          checar_sucesso(ok);
        }
        if(num != 1 && num != 2 && num != 3) printf("opcao invalida\n");
        break;
      
      case 16:

        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

      default: 
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 16);

  return 0;
}

int criar_dado(int *dado)
{
    printf("\nDigite um valor: ");
    scanf("%d", dado);

    return 1;
}

void checar_sucesso(int ok){

  if(ok !=1){
    printf("Algo de errado não está certo!");
    exit(1);
  }

  
}