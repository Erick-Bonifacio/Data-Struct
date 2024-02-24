#include "fila.h"
#include "fila1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int gerarRandAtendimento() {
    return rand() % 2 + 0; // 0 ou 1
}

int main() {

  int n, op, i, cont1 = 0, ok = 0;
  char tipo, perfil;
  int contadorClientePreferencial = 1;
  int clientesChamados = 0; 
  int senhasRetiradas = 0;

  Fila *fi = criarFila();
  Fila2 *fi_xp = criarFila2();
  Fila2 *fi_xc = criarFila2();
  Fila2 *fi_np = criarFila2();
  Fila2 *fi_nc = criarFila2();

  printf("Quantos atendimentos?\n");
  scanf("%d", &n);
  printf("\n");

  for(i = 1; i <= n; i++){
    ok = enfileirar(fi, i);
  }


  do{
    printf("\nQual menu deseja acessar?\n");
    printf("1 - Retirar senha\n");
    printf("2 - Chamar senha\n");
    scanf("%d", &op);
    printf("\n");
  
    switch(op){
      case 1:  
        if(senhasRetiradas < n){
          printf("____________________ MENU DE RETIRADA ____________________\n\n");
          printf("Digite o tipo de atendimento (X/N) e o perfil (P/C): ");
          scanf(" %c %c", &tipo, &perfil);
    
          int dado_recebido = 0;
          if(tipo == 'x' || tipo == 'n') tipo = toupper(tipo);
          if(perfil == 'p' || perfil == 'c') perfil = toupper(perfil);
          if(tipo != 'X' && tipo != 'N'){
            printf("Tipo invalido!\n");
            cont1 = 1;
          }
          if(perfil != 'P' && perfil != 'C'){
            printf("Perfil invalido!\n");
            cont1 = 1;
          }
          if(cont1 == 0){
            dado_recebido = desenfileirar(fi);
            char senha[10];
            snprintf(senha, sizeof(senha), "%c%c%d", tipo, perfil, dado_recebido);
            if(tipo == 'X' && perfil == 'P') enfileirar2(fi_xp, senha);
            else if(tipo == 'X' && perfil == 'C') enfileirar2(fi_xc, senha);
            else if(tipo == 'N' && perfil == 'P') enfileirar2(fi_np, senha);
            else if(tipo == 'N' && perfil == 'C') enfileirar2(fi_nc, senha);
  
            printf("\n\t\t\t\t\tSENHA: %s\n", senha);
  
            senhasRetiradas++;
            
          }
        }
        else printf("***************** Número máximo atingido *****************\n\n");
  
        break;
      case 2:
        printf("____________________ Senha ____________________\n\n");

        if(clientesChamados < n && clientesChamados < senhasRetiradas){
          
          srand(time(NULL));
          char senhaRetirada[4];

          int tipoAtendimento = gerarRandAtendimento();
          
          if(contadorClientePreferencial < 3){
            if(tipoAtendimento == 0){
              if(tamanhoFila2(fi_xp) != 0){
                desenfileirar2(fi_xp, senhaRetirada);
                printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                clientesChamados++;
              }
              else tipoAtendimento = 1;
            }
            
            if(tipoAtendimento == 1){
              if(tamanhoFila2(fi_np) != 0){
                desenfileirar2(fi_np, senhaRetirada);
                printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                clientesChamados++;
              }
              else contadorClientePreferencial = 3;
            }
            
          }
          
          if(contadorClientePreferencial >= 3){
            if(tipoAtendimento == 0){
              if(tamanhoFila2(fi_xc) != 0){
                desenfileirar2(fi_xc, senhaRetirada);
                printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                clientesChamados++;
                }
              else tipoAtendimento = 1;
              }
            
            if(tipoAtendimento == 1){
              if(tamanhoFila2(fi_nc) != 0){
                desenfileirar2(fi_nc, senhaRetirada);
                printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                clientesChamados++;
              }
              else{ 
                if(tamanhoFila2(fi_xp) != 0){
                  desenfileirar2(fi_xp, senhaRetirada);
                  printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                  clientesChamados++;
                }
                else{
                  if(tamanhoFila2(fi_xc) != 0){
                    desenfileirar2(fi_xc, senhaRetirada);
                    printf("\n\t\t\t\t\tSENHA: %s\n\n", senhaRetirada);
                    clientesChamados++;
                    }
                }
                }
              }
            }
            
            contadorClientePreferencial = 1;
          }

          if (contadorClientePreferencial < 3) contadorClientePreferencial++;
        
            
      if(senhasRetiradas < n && clientesChamados == senhasRetiradas){
          printf("****** Não há mais senhas a serem chamadas!! ******\n");
        }
        
          break;
        
      default:
        printf("Opção inválida!\n");
        break;
    
    }
  }while(clientesChamados < n && senhasRetiradas <= n);

  printf("\nTodas as senhas cadastradas foram chamadas!\n");
  return 0;
}