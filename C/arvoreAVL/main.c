#include <stdio.h>
#include "arvoreAVL.h"

int main(void) {
  ArvAVL* arvore = criar_arvore();
  //inserindo elementos
  inserir_arvore(arvore, 60);
  inserir_arvore(arvore, 45);
  inserir_arvore(arvore, 42);
  inserir_arvore(arvore, 83);
  inserir_arvore(arvore, 69);
  inserir_arvore(arvore, 58);
  inserir_arvore(arvore, 70);
  inserir_arvore(arvore, 55);
  inserir_arvore(arvore, 39);
  inserir_arvore(arvore, 71);
  
  remove_arvoreAVL(arvore, 45);
  remove_arvoreAVL(arvore, 83);
  remove_arvoreAVL(arvore, 39);
  remove_arvoreAVL(arvore, 60);

  inserir_arvore(arvore, 77);
  inserir_arvore(arvore, 85);
  inserir_arvore(arvore, 44);
  inserir_arvore(arvore, 83);
  inserir_arvore(arvore, 11);
  inserir_arvore(arvore, 20);
  
  posordem_arvore(arvore);

  // int x = consultar_arvore(arvore, 42);
  // printf("42 esta na arvore: %d\n", x);

  // printf("Preordem:\n");
  // preordem_arvore(arvore);
  // printf("Posordem:\n");
  // posordem_arvore(arvore);
  // printf("emordem:\n");
  // emordem_arvore(arvore);  

  // int w = altura_arvore(arvore);
  // printf("Altura da arvore: %d\n", w);

  // destruir_arvore(arvore);


  return 0;
}