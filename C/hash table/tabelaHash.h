#ifndef TABELA_HASH_H
#define TABELA_HASH_H

struct Pessoa {
  int cpf;
  char nome[30];
  int idade;
};
typedef struct hash Hash;
typedef struct elemento* Lista;


Hash* criar_hash(int TABLE_SIZE);
int destruir_hash(Hash *ha);
int buscar_hash_encadSep(Hash *ha, int cpf, struct Pessoa *p1);
int inserir_encadSeparado(Hash *ha, struct Pessoa p1);
int mostrar_tabela_encadSep(Hash *ha);
// int inserir_endAberto(Hash *ha, struct Pessoa p1);
// int buscar_hash_endAberto(Hash *ha, int cpf, struct Pessoa *p1);
// int mostrar_tabela(Hash *ha);
// int inserir_hash_semColisao(Hash *ha, struct Pessoa p1);
// int buscar_hash_semColisao(Hash *ha, int cpf, struct Pessoa *p1);
// int valorString(char *str);



#endif