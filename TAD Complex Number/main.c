// invocação da nova "biblioteca" criada e começo da interface do TAD;
#include "complex.h"
#include <stdio.h>

// função principal:
int main(void) {

  float e, b, c, d;
  Complex_number *num1, *num2;
  Complex_number *soma, *sub, *div, *mult;

  // leitura das partes de 2 númeos complexos:
  printf("Digite a parte real e a parte imaginária do 1° número: ");
  scanf("%f %f", &e, &b);
  printf("Digite a parte real e a parte imaginária do 2° número: ");
  scanf("%f %f", &c, &d);
  printf("\n");

  // criação dos números:
  num1 = criar_complex(a, b);
  num2 = criar_complex(c, d);

  // impressão dos números criados
  printf("Números criados:\n");
  printf("------------\n");
  print_complex(num1);
  print_complex(num2);
  printf("------------\n");

  // invocação das funções operantes de números complexos:
  soma = soma_complex(num1, num2);
  sub = sub_complex(num1, num2);
  div = div_complex(num1, num2);
  mult = mult_complex(num1, num2);

  // impressão dos resultados na tela:
  printf("\nSOMA: ");
  print_complex(soma);
  printf("\nSUBTRAÇÃO: ");
  print_complex(sub);
  printf("\nDIVISÃO: ");
  print_complex(div);
  printf("\nMULTIPLICAÇÃO: ");
  print_complex(mult);

  // liberação da memória alocada dinamicamente:
  free_complex(num1);
  free_complex(num2);
  free_complex(soma);
  free_complex(sub);
  free_complex(mult);
  free_complex(div);

  printf("\n\n");
  printf(" U   U   N   N   I  FFFFF  EEEEE  I  \n");
  printf(" U   U   NN  N   I  F      E      I  \n");
  printf(" U   U   N N N   I  FFF    EEEE   I  \n");
  printf(" U   U   N  NN   I  F      E      I  \n");
  printf("  UUU    N   N   I  F      EEEEE  I  \n");
  printf("\n\n");

  return 0; // retorna sucesso ao S.O.;
}
