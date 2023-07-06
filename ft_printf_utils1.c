/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:35:28 by ggneme            #+#    #+#             */
/*   Updated: 2023/01/13 23:35:58 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_strr(char *str, int *len)
{
	if (str == 0)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		*len = *len + 1;
		str++;
	}
}

char	*print_string(char *p, int *len, va_list params)
{
	char	*str;

	str = va_arg(params, char *);
	put_strr(str, len);
	p ++;
	return (p);
}

void	convert_to_hexa(unsigned long int nbr, int *len, char c)
{
	char			*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (0 <= nbr && nbr <= 15)
	{
		write(1, &hexa[nbr], 1);
		*len = *len + 1;
	}
	else
	{
		convert_to_hexa(nbr / 16, len, c);
		convert_to_hexa(nbr % 16, len, c);
	}
}

char	*print_p(char *p, int *len, va_list params)
{
	void				*par;
	unsigned long int	nbr;

	par = va_arg(params, void *);
	nbr = (unsigned long int)par;
	write(1, "0x", 2);
	*len = *len + 2;
	convert_to_hexa(nbr, len, 'x');
	p ++;
	return (p);
}

char	*print_hexa(char *p, int *len, va_list params)
{
	unsigned int	nbr;

	nbr = va_arg(params, unsigned int);
	convert_to_hexa(nbr, len, *p);
	p++;
	return (p);
}
