/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:00:40 by joao-oli          #+#    #+#             */
/*   Updated: 2023/11/12 11:00:41 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "Libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_format(va_list arg, char str);
int	print_c(int c);
int	print_s(char *str);
int	print_d(int n, int count);
int	print_u(unsigned int n, int count);
int	print_lower_x(unsigned int n, int count);
int	print_upper_x(unsigned int n, int count);
int	convert_p_to_nmbr(void *pointer);
int	print_p(unsigned long long int ptr, int count);
