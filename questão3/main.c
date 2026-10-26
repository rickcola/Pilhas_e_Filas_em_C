#include <stdio.h>
#include "fila.h"

int main() {
    int n, k;
    printf("Numero de criancas (N): ");
    scanf("%d", &n);
    printf("Passos da batata (K): ");
    scanf("%d", &k);

    if (n < 1 || k < 1) {
        printf("N e K devem ser maiores que 0\n");
        return 1;
    }

    Fila *f = fila_criar(n);
    for (int i = 1; i <= n; i++)
        fila_enqueue(f, i);

    printf("Ordem de eliminacao:");
    while (fila_tamanho(f) > 1) {
        for (int i = 0; i < k - 1; i++)
            fila_enqueue(f, fila_dequeue(f));
        printf(" %d", fila_dequeue(f));
    }
    printf("\nVencedora: crianca %d\n", fila_dequeue(f));

    fila_liberar(f);
    return 0;
}
