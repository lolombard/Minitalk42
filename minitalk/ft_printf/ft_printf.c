/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:    mgala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:56 by    mgala          #+#    #+#             */
/*   Updated: 2022/11/09 16:01:38 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_printf(char s, va_list *args, int *lung, int *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), lung);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), lung);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), lung);
	else if (s == 'x')
		ft_hexa(va_arg(*args, unsigned int), lung, 0);
	else if (s == 'X')
		ft_hexa(va_arg(*args, unsigned int), lung, 1);
	else if (s == 'p')
		ft_pointer(va_arg(*args, unsigned long), lung);
	else if (s == 'c')
		ft_putchar_lung(va_arg(*args, int), lung);
	else if (s == '%')
		ft_putchar_lung('%', lung);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		lung;

	i = 0;
	lung = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_printf(str[i], &args, &lung, &i);
			i++;
		}
		else
		{
			ft_putchar_lung((char)str[i], &lung);
			i++;
		}
	}
	va_end(args);
	return (lung);
}
