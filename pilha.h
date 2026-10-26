#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char *dados;
    int tamanho_alocado;
    int topo;
} Pilha;

Pilha *pilha_criar(int capacidade);
void   pilha_push(Pilha *p, char valor);
char   pilha_pop(Pilha *p);
int    pilha_vazia(Pilha *p);
void   pilha_liberar(Pilha *p);

#endif
