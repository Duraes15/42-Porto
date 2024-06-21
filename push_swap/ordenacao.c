#include "push_swap.h"

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
}