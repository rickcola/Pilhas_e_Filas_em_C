#ifndef FILA_H
#define FILA_H

typedef struct {
    int *dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} Fila;

Fila *fila_criar(int capacidade);
int   fila_enqueue(Fila *f, int valor);
int   fila_dequeue(Fila *f);
int   fila_tamanho(Fila *f);
void  fila_liberar(Fila *f);

#endif
