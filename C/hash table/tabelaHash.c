#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabelaHash.h" //incluindo a interface

// //tipo do hash
// struct hash {
//   int qtd, TABLE_SIZE;
//   struct Pessoa **itens;
// };

// Hash* criar_hash(int TABLE_SIZE){
//   Hash *ha = (Hash*) malloc(sizeof(Hash)); //criando o ponteiro da tabela completa
//   if(ha != NULL){
//     ha->TABLE_SIZE = TABLE_SIZE;//salvando o tamanho da tabela
//     //criando as linhas da tabela, do tipo PESSOA ponteiro para ponteiro, com o espaço de cada estrutura Pessoa multiplicado pelo tamanho da tabela.
//     ha->itens = (struct Pessoa **)malloc(TABLE_SIZE * sizeof(struct Pessoa*));
//     if(ha->itens == NULL){
//       //caso de erro a alocação das linhas da tabela
//       free(ha);
//       return NULL;
//     }
//     //deixando todos os valores de cada linha vazios
//     for(int i = 0; i<TABLE_SIZE; i++){
//       ha->itens[i] = NULL;
//     }
//     ha->qtd = 0;
//   }

//   return ha;
// }; 

// int destruir_hash(Hash *ha){
//   if(ha == NULL){
//     return 0; //verificando se a tabela existe
//   }
//   for(int i = 0; i < ha->TABLE_SIZE; i++){
//     free(ha->itens[i]); //limpando cada celula da tabela
//   }
//   free(ha->itens); //destruindo o array
//   free(ha); //destruindo a tabela
//   return 1;
// };

// //FUNCOES DE CALCULO DO HASH
// int chaveDivisao(int chave, int TABLE_SIZE){
//   return (chave & 0x7FFFFFFF) % TABLE_SIZE; //retirando o sinal de negativo, caso tenha, do numero e dividindo pelo tamanho total da tabela
// };
// int chaveMultiplicacao(int chave, int TABLE_SIZE){
//   float Constante = 0.1337331; //a constante precisa estar entre 0 e 1 para que a multiplicacao final, pelo tamanho da tabela, gere uma posicao valida
//   float value = chave * Constante;
//   value = value - (int) value; //pegando a parte fracionaria do resultado
//   return (int) (TABLE_SIZE * value);
// };
// int chaveDobra(int chave, int TABLE_SIZE){
//   int dobra = 10;
//   int parte1 = chave >> dobra;
//   int parte2= chave & (TABLE_SIZE-1);
//   return (parte1 ^ parte2);
// };
// int valorString(char *str){
//   int valor = 7;
//   int tamanho = strlen(str);
//   for(int i = 0; i < tamanho; i++){
//     valor = 31 * valor + (int) str[i];
//     //31 é um dos melhores valores a se usar de acordo com alguns estudos
//   }
//   return valor;
// }

// int inserir_hash_semColisao(Hash *ha, struct Pessoa p1){
//   if (ha == NULL || ha->qtd == ha->TABLE_SIZE){
//     return 0; //insercao nao aconteceu, a tabela nao existe ou esta cheia
//   }

//   int chave = p1.cpf;
//   int pos = chaveDivisao(chave, ha->TABLE_SIZE);

//   struct Pessoa *p2;
//   p2 = (struct Pessoa *) malloc(sizeof(struct Pessoa));
//   if(p2 == NULL){
//     return 0; //espaco nao alocado
//   }

//   *p2 = p1; //copiando valor
//   ha->itens[pos] = p2; //armazenando a nova pessoa na tabela
//   ha->qtd++;
//   return 1;
// };

// int buscar_hash_semColisao(Hash *ha, int cpf, struct Pessoa *p1){
//   if (ha == NULL){
//     return 0; //tabela nao existe
//   } 
//   int pos = chaveDivisao(cpf, ha->TABLE_SIZE);

//   if (ha->itens[pos] != NULL){
//     *p1 = *ha->itens[pos];
//     return 1;
//   } else { 
//     return 0; //elemento nao existe na tabela
//   }
// };

// //enderecamento aberto
// //sondagem linear (apenas incrementando novas posicoes ate achar uma vaga no array)
// int sondagem_linear(int pos, int i, int TABLE_SIZE){
//   return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
// };

// //sondagem quadratica (funciona semelhante a sondagem, mas agora espalha os elementos com uma equacao do segundo grau)
// int sondagem_quadratica(int pos, int i, int TABLE_SIZE){
//   int c1 = 2;
//   int c2 = 5;
//   return ((pos + (c1 * i) + (c2 * i*i)) & 0x7FFFFFFF) % TABLE_SIZE;
// };
// //duplo hash (utiliza de duas funcoes de hashing para espalhar os elementos )
// int duplo_hash(int H1, int chave, int i, int TABLE_SIZE){
//   int H2 = chaveDivisao(chave, TABLE_SIZE - 1) + 1; //o +1 impede que a posicao retornada seja 0, por isso o table_size eh diminuido em 1 tambem.
//   // int H2 = chaveDobra(chave,TABLE_SIZE - 1) + 1;
//   // int H2 = chaveMultiplicacao(chave,TABLE_SIZE - 1) + 1;
//   return ( (H1 + H2*i) & 0x7FFFFFFF) % TABLE_SIZE;
// };

// int inserir_endAberto(Hash *ha, struct Pessoa p1){
//   if (ha == NULL || ha->qtd == ha->TABLE_SIZE){
//     return 0; //sem exito ao inserir elemento
//   }
//   int chave = p1.cpf;
//   int pos = chaveDivisao(chave, ha->TABLE_SIZE); //primeiro hash. poderia ser qualquer outro, como multiplicacao ou dobra.
//   int newPos;
//   for(int i = 0; i < ha->TABLE_SIZE; i++){
//     newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
//     // newPos = duplo_hash(pos, chave, i, ha->TABLE_SIZE);
//     if (ha->itens[newPos] == NULL){ //se a nova posicao conter elementos, entao verifique a proxima posicao vinda do duplo hash
//       struct Pessoa *p2;
//       p2 = (struct Pessoa*) malloc(sizeof(struct Pessoa));
//       if(p2 == NULL){
//         return 0; //falha ao alocar espaco
//       } 
//       *p2 = p1;
//       ha->itens[newPos] = p2;
//       ha->qtd++;
//       return 1; //operacao funcionou
//     }
//   }
//   return 0;
// };

// int buscar_hash_endAberto(Hash *ha, int cpf, struct Pessoa *p1){
//   if (ha == NULL){
//     return 0; //sem exito ao inserir elemento
//   }
//   int pos = chaveDivisao(cpf, ha->TABLE_SIZE);
//   int newPos;
//   for(int i = 0; i<ha->TABLE_SIZE; i++){
//     newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
//     if(ha->itens[newPos]->cpf == cpf){
//       *p1 = *ha->itens[newPos];
//       return 1; //encontrou
//     }
//     if(ha->itens[newPos] == NULL){
//       return 0; //se esta nulo, o elemento nao esta na tabela, pois se estiver nulo significa que ainda nao chegaram informacoes ate esta posicao.
//     }
//   }  
//   return 0; //not found
// };


// int mostrar_tabela(Hash *ha){
//   if(ha == NULL){
//     printf("Esta tabela não existe!\n");
//     return 1;
//   }
//   printf("\n**Mostrando tabela:**\n");
//   for(int i = 0; i < ha->TABLE_SIZE; i++){
//     printf("%d\n", ha->itens[i]->cpf);
//   }
//   return 1;
// }



//tipo do hash endSeparado
struct hash {
  int qtd, TABLE_SIZE;
  struct elemento **itens;
};


//tipo do elemento na lista
struct elemento {
  struct Pessoa dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

//TABELA COM ENCADEAMENTO SEPARADO:

Hash* criar_hash(int TABLE_SIZE){
  Hash *ha = (Hash*) malloc(sizeof(Hash)); //criando o ponteiro da tabela completa
  if(ha != NULL){
    ha->TABLE_SIZE = TABLE_SIZE;//salvando o tamanho da tabela
    //criando as linhas da tabela, do tipo PESSOA ponteiro para ponteiro, com o espaço de cada estrutura Pessoa multiplicado pelo tamanho da tabela.
    ha->itens = (struct elemento **)malloc(TABLE_SIZE * sizeof(struct Lista*));
    if(ha->itens == NULL){
      //caso de erro a alocação das linhas da tabela
      free(ha);
      return NULL;
    }
    //deixando todos os valores de cada linha vazios
    for(int i = 0; i<TABLE_SIZE; i++){
      ha->itens[i] = NULL;
    }
    ha->qtd = 0;
  }

  return ha;
}; 

//FUNCOES DE CALCULO DO HASH
int chaveDivisao(int chave, int TABLE_SIZE){
  return (chave & 0x7FFFFFFF) % TABLE_SIZE; //retirando o sinal de negativo, caso tenha, do numero e dividindo pelo tamanho total da tabela
};

Lista* criar_lista(){
  Lista *li = (Lista *) malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
};

int inserir_listaEncad_inicio(Lista *li, struct Pessoa p1){
  if(li == NULL){
    return 0;
  }
  Elem *no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  no->dados = p1;
  if(*li == NULL){
    no->prox = NULL;
    *li = no;
    return 1;
  }
  no->prox = *li;
  *li = no;
  return 1;
};

int inserir_encadSeparado(Hash *ha, struct Pessoa p1){
  if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
    return 0; //a insercao nao funcionou
  }

  int chave = p1.cpf;
  int pos = chaveDivisao(chave, ha->TABLE_SIZE);

  struct Pessoa *p2;
  p2 = (struct Pessoa *) malloc(sizeof(struct Pessoa));
  if(p2 == NULL){
    return 0;
  }

  *p2 = p1;

  if(ha->itens[pos] == NULL){
    Lista *newList = criar_lista();
    inserir_listaEncad_inicio(newList, *p2);
    ha->itens[pos] = *newList;
  } else {
    Lista *newList = &ha->itens[pos];

    inserir_listaEncad_inicio(newList, *p2);
  }
  return 1;
}


int mostrar_tabela_encadSep(Hash *ha){
  if(ha == NULL){
    printf("Esta tabela não existe!\n");
    return 1;
  }
  printf("\n**Mostrando tabela:**\n");
  for(int i = 0; i < ha->TABLE_SIZE; i++){
    if(ha->itens[i] == NULL){
      printf("posicao %d = vazia\n", i);
      continue;
    }
    printf("posicao %d = %d\n", i, ha->itens[i]->dados.cpf);
    printf("  Pertencentes a pos %d: ", i);
    Elem *aux = ha->itens[i]->prox;
    while(aux != NULL){
      printf("%d ", aux->dados.cpf);
      aux = aux->prox;
    }
    printf("\n");
  }
  return 1;
}

int buscar_hash_encadSep(Hash *ha, int cpf, struct Pessoa *p1){
  if (ha == NULL){
    return 0; //sem exito ao inserir elemento
  }
  int pos = chaveDivisao(cpf, ha->TABLE_SIZE);

    if(ha->itens[pos] == NULL){
      return 0; //não encontrou encontrou
    } else {
      for(int i = 0; i < ha->TABLE_SIZE; i++){
      Elem *aux = ha->itens[i];
      while (aux != NULL){
        if(aux->dados.cpf == cpf){
          *p1 = aux->dados;
          return 1;
        } 
        aux = aux->prox;
      }
    }
    }
    return 0;
};

//Excluindo lista
void destruir_lista(Lista li){
  if(li != NULL){
    Elem* no;
    while((li) != NULL){
      no = li;
      li = (li)->prox;
      free(no);
    }
    free(li);
  }
}

int destruir_hash(Hash *ha){
  if(ha == NULL){
    return 0; //verificando se a tabela existe
  }
  for(int i = 0; i < ha->TABLE_SIZE; i++){
    destruir_lista(ha->itens[i]);
    //limpando cada celula da tabela
  }
  free(ha->itens); //destruindo o array
  free(ha); //destruindo a tabela
  return 1;
};


