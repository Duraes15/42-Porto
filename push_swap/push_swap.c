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

// does the stack or linked list
t_lint do_stack(char **argv, int argc) // stay
{
    int i;
    t_lint head;
    t_lint nodo;

    i = 2;
    head = malloc(sizeof(struct double_nodo));
    head->valor = ft_atoi_check_l(argv[1]);
    if (argc == 2)
    {
        head->prox = NULL;
        return head;
    }
    nodo = malloc(sizeof(struct double_nodo));
    head->prox = nodo;
    while (i < argc - 1)
    {
        nodo->valor = ft_atoi_check_l(argv[i]);
        nodo->prox = malloc(sizeof(struct double_nodo));
        nodo = nodo->prox;
        i++;
    }
    nodo->valor = atoi(argv[i]);
    nodo->prox = NULL;
    return (head);
}

// esta funcao é para comentar
void print_list(t_lint nodo) // stay
{
    while (nodo != NULL)
    {
        printf("%d\n", (nodo->valor));
        nodo = nodo->prox;
    }
}

// free's the given linked list
void liberta_lista(t_lint nodo) // stay
{
    t_lint ant;

    while (nodo != NULL)
    {
        ant = nodo;
        nodo = nodo->prox;
        free(ant);
    }
}

// calculates the number o nodes of the list
int lista_len(t_lint nodo) // stay
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
t_lint ft_swap(t_lint nodo, int flag) // stay
{
    int i;
    t_lint second;

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
void ft_double_swap(t_lint *n1, t_lint *n2) // stay
{
    *n1 = ft_swap(*n1, 2);
    *n2 = ft_swap(*n2, 2);
    printf("ss\n");
}

// push the first elem of l2 to the top of lista
void ft_push(t_lint *lista, t_lint *l2, int flag) // stay
{
    t_lint n2;

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

t_lint ft_rotate(t_lint node, int flag) // stay
{
    t_lint first;
    t_lint second;

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

void ft_double_rotate(t_lint *n1, t_lint *n2) // stay
{
    *n1 = ft_rotate(*n1, 2);
    *n2 = ft_rotate(*n2, 2);
    printf("rr\n");
}

t_lint ft_reverse_rotate(t_lint lista, int flag) // stay
{
    t_lint first;
    t_lint nodo;
    t_lint temp;

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

void ft_double_reverse_rotate(t_lint *n1, t_lint *n2) // stay
{
    *n1 = ft_reverse_rotate(*n1, 2);
    *n2 = ft_reverse_rotate(*n2, 2);
    printf("rrr\n");
}

int existe_na_lista(int x, t_lint nodo) // stay
{
    while (nodo != NULL)
    {
        if (nodo->valor == x)
            return 1;
        nodo = nodo->prox;
    }
    return 0;
}

int there_is_dup_numbers(t_lint nodo) // stay
{
    t_lint inicio;

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

int is_sorted(t_lint nodo) // stay
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

void sort_two(t_lint *stack, int flag) // stay
{
    if ((*stack)->valor > (*stack)->prox->valor)
        *stack = ft_swap(*stack, flag);
}

int is_max(t_lint *lista, int x) // stay
{
    t_lint nodo;

    nodo = *lista;
    while (nodo != NULL)
    {
        if (x < nodo->valor)
            return 0;
        nodo = nodo->prox;
    }
    return 1;
}

int is_min(t_lint *lista, int x)
{
    t_lint nodo;

    nodo = *lista;
    while (nodo != NULL)
    {
        if (x > nodo->valor)
            return 0;
        nodo = nodo->prox;
    }
    return 1;
}

// if (is_sorted(*stack))
    //     return ;
    // else if (is_max(stack, (*stack)->prox->valor))
    // {
    //     if (is_min(stack, (*stack)->prox->prox->valor))
    //         (*stack) = ft_reverse_rotate((*stack), 0);
    //     else
    //     {
    //         (*stack) = ft_reverse_rotate((*stack), 0);
    //         (*stack) = ft_swap((*stack), 0);
    //     }
    // }
    // else if (is_min(stack, (*stack)->prox->valor))
    // {
    //     if (is_max(stack, (*stack)->valor))
    //     {
    //         (*stack) = ft_reverse_rotate((*stack), 0);
    //         (*stack) = ft_reverse_rotate((*stack), 0);
    //     }
    //     else
    //         (*stack) = ft_swap((*stack), 0);
    // }
    // else
    // {

    // }
void edge_case_three_sort(t_lint *stack)
{
    if (is_max(stack, (*stack)->prox->valor))
        (*stack) = ft_reverse_rotate((*stack), 0);
    else
        (*stack) = ft_swap((*stack), 0);
}

void sort_three(t_lint *stack, int flag)
{
    if (is_min(stack, (*stack)->valor))
    {
        if (!is_sorted(*stack))
        {
            (*stack) = ft_reverse_rotate((*stack), flag);
            (*stack) = ft_swap((*stack), flag);
        }
    }
    else if (is_max(stack, (*stack)->valor))
    {
        if (is_min(stack, (*stack)->prox->valor))
        {
            (*stack) = ft_reverse_rotate((*stack), flag);
            (*stack) = ft_reverse_rotate((*stack), flag);
        }
        else
        {
            (*stack) = ft_swap((*stack), flag);
            (*stack) = ft_reverse_rotate((*stack), flag);
        }
    }
    else
        edge_case_three_sort(stack);
}

void after_separation(t_lint *stack_a, t_lint *stack_b)
{
    if (stack_b)
}

void sort_five(t_lint *stack_a, t_lint *stack_b)
{
    ft_push(stack_b, stack_a, 1);
    ft_push(stack_b, stack_a, 1);
    sort_two(stack_b, 1);
    sort_three(stack_a, 0);
    atfer_separation(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_lint nodo;
    t_lint n2;

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
    sort_three(&nodo, 0);
    printf("After sort\n");
    print_list(nodo);
    liberta_lista(nodo);
    liberta_lista(n2);
}