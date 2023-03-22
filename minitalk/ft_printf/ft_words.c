/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:    mgala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:37:24 by    mgala          #+#    #+#             */
/*   Updated: 2022/11/09 15:33:30 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*char*/

void	ft_putchar_lung(char carattere, int *lung)
{
	write (1, &carattere, 1);
	*lung = *lung + 1;
}

/*stringa*/

void	ft_string(char *str, int *lung)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*lung = *lung + 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_lung(str[i], lung);
		i++;
	}
}
