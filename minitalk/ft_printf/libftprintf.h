/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   mgala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:54 by   mgala           #+#    #+#             */
/*   Updated: 2022/11/08 16:50:30 by   mgala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_number(int numb, int *lung);
void	ft_hexa(unsigned int x, int *lung, int cap_pella);
void	ft_hexa_gone(unsigned long x, int *lung);
void	ft_pointer(unsigned long pointer, int *lung);
int		ft_printf(const char *str, ...);
void	ft_putchar_lung(char carattere, int *lung);
void	ft_string(char *str, int *lung);
void	ft_unsigned_int(unsigned int u, int *lung);

#endif
