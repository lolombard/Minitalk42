/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:    mgala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:37:41 by    mgala          #+#    #+#             */
/*   Updated: 2022/11/09 16:10:22 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//ft_putnbr//

void	ft_number(int numb, int *lung)
{
	if (numb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*lung) += 11;
		return ;
	}
	if (numb < 0)
	{
		ft_putchar_lung('-', lung);
		ft_number(numb * -1, lung);
	}
	else
	{
		if (numb > 9)
			ft_number(numb / 10, lung);
		ft_putchar_lung(numb % 10 + '0', lung);
	}
}

//hexa -x o X//

void	ft_hexa(unsigned int x, int *lung, int cap_pella)
{
	if (x >= 16)
	{
		ft_hexa(x / 16, lung, cap_pella);
		x = x % 16;
	}
	if (cap_pella)
	{
		ft_putchar_lung("0123456789ABCDEF"[x], lung);
	}
	else
		ft_putchar_lung("0123456789abcdef"[x], lung);
}

//hexa_pointer

void	ft_hexa_gone(unsigned long x, int *lung)
{
	if (x >= 16)
	{
		ft_hexa_gone(x / 16, lung);
		x = x % 16;
	}
	ft_putchar_lung("0123456789abcdef"[x], lung);
}

//pointer

void	ft_pointer(unsigned long pointer, int *lung)
{
	unsigned long	i;

	i = pointer;
	if (!i)
	{
		write(1, "(nil)", 5);
		*lung += 5;
	}
	else
	{
		write(1, "0x", 2);
		*lung += 2;
		ft_hexa_gone(i, lung);
	}
}

//unsigned int

void	ft_unsigned_int(unsigned int u, int *lung)
{
	if (u > 9)
		ft_unsigned_int(u / 10, lung);
	ft_putchar_lung(u % 10 + '0', lung);
}
