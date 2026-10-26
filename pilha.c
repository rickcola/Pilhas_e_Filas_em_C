#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *pilha_criar(int capacidade) {
    if (capacidade <= 0) capacidade = 1;
    Pilha *p = malloc(sizeof(Pilha));
    p->dados = malloc(capacidade * sizeof(char));
    p->tamanho_alocado = capacidade;
    p->topo = 0;
    return p;
}

void pilha_push(Pilha *p, char valor) {
    if (p->topo == p->tamanho_alocado) {
        p->tamanho_alocado *= 2;
        p->dados = realloc(p->dados, p->tamanho_alocado * sizeof(char));
    }
    p->dados[p->topo] = valor;
    p->topo++;
}

char pilha_pop(Pilha *p) {
    if (p->topo == 0) {
        printf("Pilha vazia\n");
        exit(1);
    }
    p->topo--;
    return p->dados[p->topo];
}

int pilha_vazia(Pilha *p) {
    return p->topo == 0;
}

void pilha_liberar(Pilha *p) {
    free(p->dados);
    free(p);
}
