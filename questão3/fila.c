#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *fila_criar(int capacidade) {
    Fila *f = malloc(sizeof(Fila));
    f->dados = malloc(capacidade * sizeof(int));
    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    return f;
}

int fila_enqueue(Fila *f, int valor) {
    if (f->tamanho == f->capacidade)
        return 0;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
    return 1;
}

int fila_dequeue(Fila *f) {
    if (f->tamanho == 0) {
        printf("Fila vazia\n");
        exit(1);
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return valor;
}

int fila_tamanho(Fila *f) {
    return f->tamanho;
}

void fila_liberar(Fila *f) {
    free(f->dados);
    free(f);
}
