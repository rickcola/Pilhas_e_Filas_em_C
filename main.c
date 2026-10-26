#include <stdio.h>
#include <string.h>
#include "pilha.h"

int balanceada(const char *expr) {
    Pilha *p = pilha_criar(8);
    int ok = 1;

    for (int i = 0; expr[i] != '\0' && ok; i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            pilha_push(p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha_vazia(p)) {
                ok = 0;
            } else {
                char topo = pilha_pop(p);
                if ((c == ')' && topo != '(') ||
                    (c == ']' && topo != '[') ||
                    (c == '}' && topo != '{'))
                    ok = 0;
            }
        }
    }

    if (ok && !pilha_vazia(p)) ok = 0;
    pilha_liberar(p);
    return ok;
}

int main() {
    const char *testes[] = {
        "{[()]}",
        "if (a[i] > 0) { x = (a + b) * 2; }",
        "([)]",
        "((3 + 2)",
        ")("
    };
    int n = sizeof(testes) / sizeof(testes[0]);

    printf("=== Casos de teste ===\n");
    for (int i = 0; i < n; i++)
        printf("%-40s -> %s\n", testes[i],
               balanceada(testes[i]) ? "Balanceada" : "Nao balanceada");

    char expr[256];
    printf("\nDigite uma expressao: ");
    if (fgets(expr, sizeof(expr), stdin)) {
        expr[strcspn(expr, "\n")] = '\0';
        printf("%s\n", balanceada(expr) ? "Balanceada" : "Nao balanceada");
    }
    return 0;
}
