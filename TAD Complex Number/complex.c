#include <stdio.h>
#include <stdlib.h>
#include "complex.h" //invocação dos protótipos;


//criação da estrutura para armazenar numeros complexos - novo tipo:
struct complex_number{
  float real;
  float imag;
};

//Corpo da função que cria numeros complexos, dinamicamente;
Complex_number* criar_complex(float x, float y){
  Complex_number* num = (Complex_number *)malloc(sizeof(Complex_number));

  if(num != NULL){
    num->real = x;
    num->imag = y;
  }

  return num;
}

//corpo da função que libera memória uma vez alocada:
void free_complex(Complex_number* num)
{
  free(num);
}

//corpo da função que soma complexos e retorna um novo número como resultado:
Complex_number* soma_complex(Complex_number* num1, Complex_number* num2){
  Complex_number* soma = (Complex_number *)calloc(1, sizeof(Complex_number));

  if(soma != NULL){
    float real = num1->real + num2->real;
    float imag = num1->imag + num2->imag;
    soma = criar_complex(real, imag);
  }
  
  return soma;
}

//corpo da função que subtrai complexos e retorna um novo número como resultado:
Complex_number* sub_complex(Complex_number* num1, Complex_number * num2){
  Complex_number* sub = (Complex_number *)calloc(1, sizeof(Complex_number));

  if( sub != NULL){
    float real = num1->real - num2->real;
    float imag = num1->imag - num2->imag;
    sub = criar_complex(real, imag);
  }
  
  return sub;
}

//corpo da função que divide complexos e retorna um novo número como resultado:
Complex_number* div_complex(Complex_number *num1, Complex_number *num2){
  
  float denominador = (num2->real * num2->real) + (num2->imag * num2->imag);
  float real_part = ((num1->real * num2->real) + (num1->imag * num2->imag)) / denominador;
  float imag_part = (num1->imag * num2->real - num1->real * num2->imag) / denominador;
  
  return criar_complex(real_part, imag_part);
}

//corpo da função que multiplica complexos e retorna um novo número como resultado:
Complex_number* mult_complex(Complex_number *num1, Complex_number *num2){
        
  float real = (num1->real * num2->real) - (num1->imag * num2->imag); 
  float imag = (num1->imag * num2->real) + (num1->real * num2->imag);
  
  return criar_complex(real, imag);
}

//corpo da função que imprime complexos corretamente:
void print_complex(Complex_number* num ){

  if(num->imag < 0){
    num->imag = num->imag * -1;
    printf("%.2f - %.2fi\n", num->real, num->imag);
    num->imag = num->imag * -1;
  }
  else if(num->imag >= 0)
    printf("%.2f + %.2fi\n", num->real, num->imag);
}