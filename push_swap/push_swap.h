#include <stdlib.h>
#include <stdio.h>
#include "libft_printf/libft.h"

typedef struct nodo
{
    int valor;
    struct nodo *prox;
} *LInt;

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