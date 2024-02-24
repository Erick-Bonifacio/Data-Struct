#include <stdio.h>
#include "static.list.h"

void error_test(int ok);

int main(){
  
  Lista *li = NULL;
  Produto *product = NULL;
  int ok, op, n;
  int pos1, pos2;

  li = criar_lista();
  
  if(li != NULL) printf("\n\tJá criamos uma lista pra você!\n");
  else printf("\n Lista não criada!");

  do{
    printf("\nO que deseja fazer?\n");
    printf("\n1 - Liberar lista");
    printf("\n2 - Inserir Produto");;
    printf("\n3 - Remover n produtos do final da lista");
    printf("\n4 - Buscar produto de menor preço");
    printf("\n5 - Trocar dois produtos de posição");
    printf("\n6 - Imprimir lista");
    printf("\n7 - Sair");
    printf("\nOpção: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        free_list(li, product);
        break;
      case 2:
        ok = create_product(&product); 
        ok = product_register(li, product);
        error_test(ok);
        break;
      case 3:
        printf("Digite a quantidade prudutos a serem removidos: ");
        scanf("%d", &n);
        ok = remove_elements(li, n);
        error_test(ok);
        break;
      case 4:
        low_price(li);
        break;
      case 5:
        printf("Digite as posições de troca (1 para o primeiro, 2 para o segundo...): ");
        scanf("%d %d", &pos1, &pos2);
        ok = change_pos(li, pos1, pos2);
        error_test(ok);
        break;
      case 6:
        ok = print_list(li);
        error_test(ok);
        break;
      case 7:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida!");
        break;
    }
  }while(op != 7);

  
  
  return 0;
}

void error_test(int ok){

  if(ok) printf("\nSucesso!\n");
  else printf("\nFalha!\n");
  
}
