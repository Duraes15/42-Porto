#include "push_swap.h"

void error_function() // stay
{
    printf("Error\n");
    exit(0);
}

int	ft_atoi_check_l(const char *nptr) // stay
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
        error_function();
    return (n * negative);
}

// test if the input is just numbers
int just_int_numbers(char **argv, int argc) // stay
{
    int i;

    i = 1;
    while (i < argc)
    {
        ft_atoi_check_l(argv[i]);
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
LInt do_stack(char **argv, int argc) // stay
{
    int i;
    LInt head;
    LInt nodo;

    i = 2;
    head = malloc(sizeof(struct nodo));
    head->valor = ft_atoi_check_l(argv[1]);
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

// esta funcao é para comentar
void print_list(LInt nodo) // stay
{
    while (nodo != NULL)
    {
        printf("%d\n", (nodo->valor));
        nodo = nodo->prox;
    }
}

// free's the given linked list
void liberta_lista(LInt nodo) // stay
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
int lista_len(LInt nodo) // stay
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
LInt ft_swap(LInt nodo, int flag) // stay
{
    int i;
    LInt second;

    i = 0;
    if (lista_len(nodo) <= 1)
        return nodo;
    second = nodo->prox;
    nodo->prox = second->prox;
    second->prox = nodo;
    if (flag == 0)
        printf("sa\n");
    else if (flag == 1)
        printf("sb\n");
    return (second);
}
// ft_printf printf
// used to do the double swap
void ft_double_swap(LInt *n1, LInt *n2) // stay
{
    *n1 = ft_swap(*n1, 2);
    *n2 = ft_swap(*n2, 2);
    printf("ss\n");
}

// push the first elem of l2 to the top of lista
void ft_push(LInt *lista, LInt *l2, int flag) // stay
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
    if (flag == 0)
        printf("pa\n");
    else
        printf("pb\n");
}

LInt ft_rotate(LInt node, int flag) // stay
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
    if (flag == 0)
        printf("ra\n");
    else if (flag == 1)
        printf("rb\n");
    return node;
}

void ft_double_rotate(LInt *n1, LInt *n2) // stay
{
    *n1 = ft_rotate(*n1, 2);
    *n2 = ft_rotate(*n2, 2);
    printf("rr\n");
}

LInt ft_reverse_rotate(LInt lista, int flag) // stay
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
    if (flag == 0)
        printf("rra\n");
    else if (flag == 1)
        printf("rrb\n");
    return (nodo);
}

void ft_double_reverse_rotate(LInt *n1, LInt *n2) // stay
{
    *n1 = ft_reverse_rotate(*n1, 2);
    *n2 = ft_reverse_rotate(*n2, 2);
    printf("rrr\n");
}

int existe_na_lista(int x, LInt nodo) // stay
{
    while (nodo != NULL)
    {
        if (nodo->valor == x)
            return 1;
        nodo = nodo->prox;
    }
    return 0;
}

int there_is_dup_numbers(LInt nodo) // stay
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
// esta funcao vai sempre receber uma lista com mais do que um elemento
int is_sorted(LInt nodo) // stay
{
    if (nodo == NULL || lista_len(nodo) == 1)
        return 1;
    while (nodo->prox != NULL)
    {
        if (nodo->valor > nodo->prox->valor)
            return 0;
        nodo = nodo->prox;
    }
    return 1;
}

void procura_menor(LInt nodo, t_menor_data *menor) // stay
{
    int i;

    i = 1;
    menor->valor = nodo->valor;
    menor->posicao = 0;
    nodo = nodo->prox;
    while (nodo != NULL)
    {
        if (menor->valor > nodo->valor)
        {
            menor->valor = nodo->valor;
            menor->posicao = i;
        }
        nodo = nodo->prox;
        i++;
    }
}

int diff_dist_check(LInt *stack_a, t_menor_data *menor, int total_elems)
{
    if (total_elems - menor->posicao < menor->posicao)
    {
        *stack_a = ft_reverse_rotate(*stack_a, 0);
        return 1;
    }
    else if (total_elems - menor->posicao > menor->posicao)
    {
        *stack_a = ft_rotate(*stack_a, 0);
        return 1;
    }
    else
        return 0;
}

int is_maximo(LInt *lista, int x) // stay
{
    LInt nodo;

    nodo = *lista;
    while (nodo != NULL)
    {
        if (x < nodo->valor)
            return 0;
        nodo = nodo->prox;
    }
    return 1;
}

// this function will search for the elem that is right bigger than the "menor"
// and do the respoective rotate
// if the distance remains the same, it means that the 2nd lowest elem is next to the lowest, so I'll sort
void rotates_based_next_lowest(LInt *stack_a, LInt *stack_b, t_menor_data *menor, int t_elems)
{
    t_menor_data prox_menor;
    int i;
    LInt nodo;

    prox_menor.valor = (*stack_a)->valor;
    prox_menor.posicao = 0;
    nodo = (*stack_a)->prox;
    i = 0;
    while (nodo != NULL)
    {
        if (prox_menor.valor > nodo->valor && nodo->valor > menor->valor)
        {
            prox_menor.valor = nodo->valor;
            prox_menor.posicao = i++;
        }
        nodo = nodo->prox;
    }
    if (is_maximo(stack_a, prox_menor.valor))
        ft_push(stack_b, stack_a, 1);
    else if (!diff_dist_check(stack_a, &prox_menor, t_elems))
    {
        menor->valor = prox_menor.valor;
        menor->posicao = prox_menor.posicao;
        rotates_based_next_lowest(stack_a, stack_b, menor, t_elems);
    }
}

void sort_two(LInt *stack) // stay
{
    if ((*stack)->valor > (*stack)->prox->valor)
        *stack = ft_swap(*stack, 0);
}

void retorna_para_stack_a(LInt *stack_a, LInt *stack_b)
{
    while (*stack_b)
    {
        ft_push(stack_a, stack_b, 0);
    }
}

// (total_elems - menor.posicao) corresponde ao numero de moves roda para baixo;
// menor.posicao corresponde ao numero de moves rodapara cima
void sort_stacks(LInt *stack_a, LInt *stack_b)
{
    t_menor_data menor;
    int total_de_elems;

    total_de_elems = lista_len(*stack_a);
    if (total_de_elems == 1)
        return ;
    if (total_de_elems == 2)
    {
        sort_two(stack_a);
        return ;
    }
    while (!is_sorted(*stack_a))
    {
        procura_menor(*stack_a, &menor);
        if (menor.posicao == 0)
            ft_push(stack_b, stack_a, 1);
        else if (total_de_elems - menor.posicao < menor.posicao)
            *stack_a = ft_reverse_rotate(*stack_a, 0);
        else if (total_de_elems - menor.posicao > menor.posicao)
            *stack_a = ft_rotate(*stack_a, 0);
        else
            rotates_based_next_lowest(stack_a, stack_b, &menor, total_de_elems);
    }
    retorna_para_stack_a(stack_a, stack_b);
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
    // printf("Before sort\n");
    // print_list(nodo);
    sort_stacks(&nodo, &n2);
    // printf("After sort\n");
    // print_list(nodo);
    liberta_lista(nodo);
    liberta_lista(n2);
}