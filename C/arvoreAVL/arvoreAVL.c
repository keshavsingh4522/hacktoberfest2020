#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

struct NO {
  int info;
  int alt;
  struct NO *esq;
  struct NO *dir;
};

//criando a arvore
ArvAVL* criar_arvore(){
  ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
  if(raiz != NULL){
    *raiz = NULL;
  }
  return raiz;
}

//destruindo arvore
//liberacao de no
void liberar_no(struct NO* no){
  if(no == NULL){
    return;
  }
  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}
//liberacao do no raiz
void liberar_arvore(ArvAVL* raiz){
  if(raiz == NULL){
    return;
  }
  liberar_no(*raiz);
  free(raiz);
}

//retornando a altura do no
int alt_NO(struct NO* no){
  if(no == NULL){
    return -1;
  } else {
    return no->alt;
  }
}

void destruir_arvore(ArvAVL *raiz){
  if(raiz == NULL){
    return;
  }
  //removando a raiz ate que nao exista mais uma na arvore.
  while(!arvore_vazia(raiz)){
    remove_arvoreAVL(raiz, (*raiz)->info);
  }
}

//calculando o fator de balanceamento do no
int balanceamentoNO(struct NO* no){
  return labs(alt_NO(no->esq) - alt_NO(no->dir)); //modulo
}

int maior(int x, int y){
  if(x > y){
    return x;
  } else {
    return y;
  }
}

//verificando se a arvore esta vazia
int arvore_vazia(ArvAVL *raiz){
  if(raiz == NULL){
    return 1;
  }
  if(*raiz == NULL){
    return 1;
  }
  return 0;
}

//retornando a altura da arvore
int altura_arvore(ArvAVL *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz == NULL){
    return 0;
  }

  int alt_esq = altura_arvore(&((*raiz)->esq));
  int alt_dir = altura_arvore(&((*raiz)->dir));

  if(alt_esq > alt_dir){
    return (alt_esq + 1);
  } else {
    return (alt_dir + 1);
  }
}

//contando quantos nos tem na arvore
int total_no_arvore(ArvAVL *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz == NULL){
    return 0;
  }

  int alt_esq = altura_arvore(&((*raiz)->esq));
  int alt_dir = altura_arvore(&((*raiz)->dir));

  return (alt_esq + alt_dir + 1);
}

//percorrendo preordem
void preordem_arvore(ArvAVL* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    printf("%d\n", (*raiz)->info);
    preordem_arvore(&((*raiz)->esq));
    preordem_arvore(&((*raiz)->dir));
  }
}

//percorrendo preordem
void emordem_arvore(ArvAVL* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    emordem_arvore(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emordem_arvore(&((*raiz)->dir));
  }
}

//percorrendo preordem
void posordem_arvore(ArvAVL* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    posordem_arvore(&((*raiz)->esq));
    posordem_arvore(&((*raiz)->dir));
    printf("%d\n", (*raiz)->info);
  }
}

//rotacoes
//ROTACAO LL - Para a direita
void rotacaoLL(ArvAVL *raiz){
  struct NO *no;
  no = (*raiz)->esq;
  (*raiz)->esq = no->dir;
  no->dir = *raiz;

  (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1; 
  
  no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;

  (*raiz) = no;
};

//ROTACAO RR - Para a esquerda
void rotacaoRR(ArvAVL *raiz){
  struct NO *no;
  no = (*raiz)->dir;
  (*raiz)->dir = no->esq;
  no->esq = *raiz;

  (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1; 
  
  no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;

  (*raiz) = no;
};

//rotacao LR - rotacoes duplas, RR e LL
void rotacaoLR(ArvAVL *raiz){
  rotacaoRR(&(*raiz)->esq);
  rotacaoLL(raiz);
}

//rotacao LR - rotacoes duplas, RR e LL
void rotacaoRL(ArvAVL *raiz){
  rotacaoLL(&(*raiz)->dir);
  rotacaoRR(raiz);
}

//inserindo elemento na arvore
int inserir_arvore(ArvAVL* raiz, int valor){
  int res;
  if(*raiz == NULL){ //arvore esta vazia
  struct NO* novo;
  novo = (struct NO*) malloc(sizeof(struct NO));
  if(novo == NULL){
    return 0;
  }

  novo->info = valor;
  novo->alt = 0;
  novo->dir = NULL;
  novo->esq = NULL;

  *raiz = novo;
  return 1;
  }

  struct NO *atual = *raiz;
  if(valor < atual->info){
    if((res=inserir_arvore(&(atual->esq),valor)) == 1){
      if(balanceamentoNO(atual) >= 2){
        if(valor < (*raiz)->esq->info){
          rotacaoLL(raiz);
        } else {
          rotacaoLR(raiz);
        }
      }
    }
  } else {
    if(valor > atual->info){
      if((res=inserir_arvore(&(atual->dir),valor)) == 1){
        if(balanceamentoNO(atual) >= 2){
          if((*raiz)->dir->info < valor){
            rotacaoRR(raiz);
          } else {
            rotacaoRL(raiz);
          }
        }
      }
    } else {
      printf("Valores iguais!\n");
      return 0;
    } 
  }

  atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;

  return res;
}

//trata a remocao de um no com 2 filhos
struct NO* procuraMenor(struct NO* atual){
  struct NO *no = atual;
  struct NO *noAux = atual->esq;
  while(noAux != NULL){
    no = noAux;
    noAux = noAux->esq;
  }
  return no;
}

//procura o elemento a ser removido
int remove_arvoreAVL(ArvAVL *raiz, int valor){
  if(*raiz == NULL){
    printf("Not found!\n");
    return 0;
  }
  int res;
  if(valor < (*raiz)->info){
    if((res=remove_arvoreAVL(&(*raiz)->esq, valor)) == 1){
      if(balanceamentoNO(*raiz) >= 2){
        if(alt_NO(((*raiz)->dir->esq)) <= alt_NO((*raiz)->dir->dir)){
          rotacaoRR(raiz);
        } else {
          rotacaoRL(raiz);
        }
      }
    }
  } 

  if((*raiz)->info < valor){
    if((res=remove_arvoreAVL(&(*raiz)->dir, valor)) == 1){
      if(balanceamentoNO(*raiz) >= 2){
        if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
          rotacaoLL(raiz);
        } else {
          rotacaoLR(raiz);
        }
      }
    }
  }

  if((*raiz)->info == valor){
    if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL){
      struct NO *oldNode = (*raiz);
      if((*raiz)->esq != NULL){
        *raiz = (*raiz)->esq;
      } else {
        *raiz = (*raiz)->dir;
      }
      free(oldNode);
    } else {
      struct NO* temp = procuraMenor((*raiz)->dir);
      (*raiz)->info = temp->info;
      remove_arvoreAVL(&(*raiz)->dir, (*raiz)->info);
      if(balanceamentoNO(*raiz) >= 2){
        if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
          rotacaoLL(raiz);
        } else {
          rotacaoLR(raiz);
        }
      }
    }
    if(*raiz != NULL){
      (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    }
    return 1;
  }
  (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1; 
  return res;
};

//consultando se um elemento se encontra na arvore
int consultar_arvore(ArvAVL *raiz, int valor){
  if(raiz == NULL){
    return 0;
  }
  struct NO* atual = *raiz;
  while(atual != NULL){
    if(valor == atual->info){
      return 1;
    }
    if(valor > atual->info){
      atual = atual->dir;
    } else {
      atual = atual->esq;
    }
  }
  return 0;
}
