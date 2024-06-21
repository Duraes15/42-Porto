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
    else
    	return (n * negative);
}

// test if the input is just numbers
int just_int_numbers(char **argv, int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!ft_atoi_check_l(argv[i]))
            return 0;
        i++;
    }
    return 1;
}

// LInt initializes_list(int x)
// {
//     LInt head;

//     head = malloc(sizeof(struct nodo));
//     head->valor = x;
//     head->prox = NULL;
//     return (head);
// }

// does the stack or linked list
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
        nodo->valor = atoi(argv[i]);
        nodo->prox = malloc(sizeof(struct nodo));
        nodo = nodo->prox;
        i++;
    }
    nodo->valor = atoi(argv[i]);
    nodo->prox = NULL;
    return (head);
}

// esta funcao é para comentar
void print_list(LInt nodo)
{
    while (nodo != NULL)
    {
        printf("%d\n", (nodo->valor));
        nodo = nodo->prox;
    }
}

// free's the given linked list
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

// calculates the number o nodes of the list
int lista_len(LInt nodo)
{
    int i;

    i = 0;
    while (nodo != NULL)
    {
        nodo = nodo->prox;
        i++;
    }
    return (i);
}

// swap the first 2 elems of the given list
LInt ft_swap(LInt nodo)
{
    int i;
    LInt second;

    i = 0;
    if (lista_len(nodo) <= 1)
        return nodo;
    second = nodo->prox;
    nodo->prox = second->prox;
    second->prox = nodo;
    return (second);
}
// ft_printf printf
// used to do the double swap
void ft_double_swap(LInt *n1, LInt *n2)
{
    *n1 = ft_swap(*n1);
    *n2 = ft_swap(*n2);
}

void ft_push(LInt *lista, LInt *l2)
{
    LInt n2;

    n2 = *l2;
    if (*l2 == NULL)
        return;
    if (*lista == NULL)
    {
        // *lista = malloc(sizeof(struct nodo));
        *l2 = (*l2)->prox;
        *lista = n2;
        (*lista)->prox = NULL;
        return ;
    }
    *l2 = (*l2)->prox;
    n2->prox = *lista;
    *lista = n2;
}

LInt ft_rotate(LInt node)
{
    LInt first;
    LInt second;

    first = node;
    if (node == NULL || lista_len(node) == 1)
        return (node);
    second = first->prox;
    first->prox = NULL;
    node = second;
    while (second->prox != NULL)
        second = second->prox;
    second->prox = first;
    return node;
}

void ft_double_rotate(LInt *n1, LInt *n2)
{
    *n1 = ft_rotate(*n1);
    *n2 = ft_rotate(*n2);
}

LInt ft_reverse_rotate(LInt lista)
{
    LInt first;
    LInt nodo;
    LInt temp;

    if (lista == NULL || lista_len(lista) == 1)
        return (lista);
    first = lista;
    nodo = lista;
    while (nodo->prox->prox != NULL)
        nodo = nodo->prox;
    temp = nodo;
    nodo = nodo->prox;
    temp->prox = NULL;
    nodo->prox = first;
    return (nodo);
}

void ft_double_reverse_rotate(LInt *n1, LInt *n2)
{
    *n1 = ft_reverse_rotate(*n1);
    *n2 = ft_reverse_rotate(*n2);
}

void error_function()
{
    printf("Error\n");
    exit(0);
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
            return 1;
        }
        nodo = nodo->prox;
    }
    return 0;
}

int main(int argc, char **argv)
{
    LInt nodo;
    LInt n2;

    if (argc == 1 || !just_int_numbers(argv, argc))
        error_function();
    nodo = do_stack(argv, argc);
    if (there_is_dup_numbers(nodo))
        error_function();
    n2 = NULL; // ao iniciar os processos entre as
               // duas stacks tenho de colocar a segunda a NULL e puxar um elem 
               // da criada pelo argv para esta, usando a funcao ft_push
    ft_push(&n2, &nodo); 
    printf("Depois do push da ll do argv para o criado\n");
    printf("Lista criada:\n");
    print_list(n2); 
    printf("\n");
    printf("Lista do argv:\n");
    print_list(nodo); 
    printf("\n");


    ft_push(&n2, &nodo); 
    printf("Depois do 2nd push da ll do argv para o criado\n");
    printf("Lista criada:\n");
    print_list(n2); 
    printf("\n");
    printf("Lista do argv:\n");
    print_list(nodo); 
    printf("\n");


    ft_double_swap(&nodo, &n2);
    printf("Depois do double swap\n");
    printf("Lista criada:\n");
    print_list(n2); 
    printf("\n");
    printf("Lista do argv:\n");
    print_list(nodo); 
    printf("\n");

    ft_double_rotate(&nodo, &n2);
    printf("Depois do double rotate\n");
    printf("Lista criada:\n");
    print_list(n2); 
    printf("\n");
    printf("Lista do argv:\n");
    print_list(nodo); 
    printf("\n");

    ft_double_reverse_rotate(&nodo, &n2);
    printf("Depois do double reverse rotate\n");
    printf("Lista criada:\n");
    print_list(n2); 
    printf("\n");
    printf("Lista do argv:\n");
    print_list(nodo); 
    printf("\n");

    liberta_lista(nodo); 
    liberta_lista(n2); 
}