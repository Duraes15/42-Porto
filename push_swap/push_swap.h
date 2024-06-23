#include <stdlib.h>
#include <stdio.h>
#include "libft_printf/libft.h"

typedef struct nodo
{
    int valor;
    struct nodo *prox;
} *LInt; // vai ser para apagar

typedef struct double_nodo
{
    int valor;
    struct double_nodo *prox;
    int index;
    int sa;
    int sb;
    int ra;
    int rb;
    int rra;
    int rrb;
}   *t_lint;

typedef struct menor_valor
{
    int valor;
    int posicao;
}   t_menor_data;

enum Moves{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
};