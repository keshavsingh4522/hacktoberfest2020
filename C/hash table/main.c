#include <stdio.h>
#include "tabelaHash.h"
//sem tratamento de colisoes
int main(void) {
  Hash *ha = criar_hash(7);
  //criando pessoas com os cpf.
  struct Pessoa pessoa1;
  pessoa1.cpf = 2341;
  struct Pessoa pessoa2;
  pessoa2.cpf = 4234;
  struct Pessoa pessoa3;
  pessoa3.cpf = 2839;
  struct Pessoa pessoa4;
  pessoa4.cpf = 430;
  struct Pessoa pessoa5;
  pessoa5.cpf = 22;
  struct Pessoa pessoa6;
  pessoa6.cpf = 397;
  struct Pessoa pessoa7;
  pessoa7.cpf = 3920;

  inserir_encadSeparado(ha, pessoa1);
  inserir_encadSeparado(ha, pessoa2);
  inserir_encadSeparado(ha, pessoa3);
  inserir_encadSeparado(ha, pessoa4);
  inserir_encadSeparado(ha, pessoa5);
  inserir_encadSeparado(ha, pessoa6);
  inserir_encadSeparado(ha, pessoa7);

  mostrar_tabela_encadSep(ha);
  destruir_hash(ha);
  mostrar_tabela_encadSep(ha);


  // if(buscar_hash_encadSep(ha, 2342, &alguem)){
  //   printf("\nPessoa buscada, CPF: %d \n", alguem.cpf);
  // } else {
  //   printf("\nNão encontrado \n");
  // };

  
  
  // printf("\n");
  // buscar_hash_endAberto(ha, 2341, &alguem);
  // printf("CPF da pessoa consultada: %d\n", alguem.cpf);
  // destruir_hash(ha);

  

  // mostrar_tabela(ha);

  return 0;
}