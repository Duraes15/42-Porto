#include "push_swap.h"

int	ft_atoi_check_l(const char *nptr)
{
	long	n;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			n = (n * 10) + (nptr[i] - 48);
		else
			break ;
		i++;
	}
    if (n * negative > 2147483647 || n * negative < -2147483648)
        return 0;
	return (n * negative);
}

void error_function()
{
    printf("ERROR\n");
    exit(0);
}

LInt do_stack(char **argv, int argc)
{
    int i;
    LInt head;
    LInt nodo;

    i = 2;
    head = malloc(sizeof(struct nodo));
    head->valor = atoi(argv[1]);
    if (argc == 2)
    {
        head->prox = NULL;
        return head;
    }
    nodo = malloc(sizeof(struct nodo));
    head->prox = nodo;
    while (i < argc - 1)
    {
        nodo->valor = ft_atoi_check_l(argv[i]);
        nodo->prox = malloc(sizeof(struct nodo));
        nodo = nodo->prox;
        i++;
    }
    nodo->valor = atoi(argv[i]);
    nodo->prox = NULL;
    return (head);
}

void liberta_lista(LInt nodo)
{
    LInt ant;

    while (nodo != NULL)
    {
        ant = nodo;
        nodo = nodo->prox;
        free(ant);
    }
}

int existe_na_lista(int x, LInt nodo)
{
    while (nodo != NULL)
    {
        if (nodo->valor == x)
            return 1;
        nodo = nodo->prox;
    }
    return 0;
}

int there_is_dup_numbers(LInt nodo)
{
    LInt inicio;

    inicio = nodo;
    while (nodo->prox != NULL)
    {
        if (existe_na_lista(nodo->valor, nodo->prox))
        {
            liberta_lista(inicio);
            error_function();
        }
        nodo = nodo->prox;
    }
    return 0;
}

int main(int argc, char **argv)
{
    LInt nodo = do_stack(argv, argc);
    printf("%d\n", there_is_dup_numbers(nodo));
    liberta_lista(nodo);
}