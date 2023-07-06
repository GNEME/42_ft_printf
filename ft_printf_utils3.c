/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:38:05 by ggneme            #+#    #+#             */
/*   Updated: 2023/01/13 23:38:28 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_di(char *p, int *len, va_list params)
{
	unsigned int	nbr;
	long int		par;

	par = va_arg(params, int);
	if (par < 0)
	{
		write(1, "-", 1);
		*len = *len + 1;
		nbr = -par;
	}
	else
		nbr = par;
	put_nbr(nbr, len);
	p ++;
	return (p);
}

char	*print_u(char *p, int *len, va_list params)
{
	unsigned int	nbr;

	nbr = va_arg(params, unsigned int);
	put_nbr(nbr, len);
	p ++;
	return (p);
}
