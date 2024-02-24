
typedef struct complex_number Complex_number;

Complex_number* criar_complex(float a, float b); //protótipo da função que cria números complexos a partir de 2 números reais;

void free_complex(Complex_number* num); //protótipo da função que libera memória dos números complexos criados;

Complex_number* soma_complex(Complex_number* num1, Complex_number* num2); //soma de 2 complexos;

Complex_number* sub_complex(Complex_number* num1, Complex_number* num2); //subtração de 2 complexos;

Complex_number* div_complex(Complex_number* num1, Complex_number* num2); //divisão de 2 complexos;

Complex_number* mult_complex(Complex_number* num1, Complex_number* num2); //multiplicação de 2 complexos;

void print_complex(Complex_number* num); // impressão de números complexos;