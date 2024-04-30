#ifndef ArvAVLORE_AVL_H
#define ArvAVLORE_AVL_H

typedef struct NO* ArvAVL;

ArvAVL* criar_arvore();
void liberar_no(struct NO* no);
void liberar_arvore(ArvAVL* raiz);
int arvore_vazia(ArvAVL *raiz);
int altura_arvore(ArvAVL *raiz);
int total_no_arvore(ArvAVL *raiz);
void preordem_arvore(ArvAVL* raiz);
void emordem_arvore(ArvAVL* raiz);
void posordem_arvore(ArvAVL* raiz);
int inserir_arvore(ArvAVL* raiz, int valor);
int remove_arvoreAVL(ArvAVL *raiz, int valor);
int consultar_arvore(ArvAVL *raiz, int valor);
void destruir_arvore(ArvAVL *raiz);

#endif