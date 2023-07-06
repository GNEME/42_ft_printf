/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:32:41 by ggneme            #+#    #+#             */
/*   Updated: 2023/01/13 23:33:06 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(char *p, int *len, va_list params)
{
	char	c;

	c = va_arg(params, int);
	write(1, &c, 1);
	*len = *len + 1;
	p++;
	return (p);
}

char	*print_percentage(char *p, int *len)
{
	write(1, "%", 1);
	*len = *len + 1;
	p++;
	return (p);
}

void	put_nbr(unsigned long int nbr, int *len)
{
	char	*base;

	base = "0123456789";
	if (0 <= nbr && nbr <= 9)
	{
		write(1, &base[nbr], 1);
		*len = *len + 1;
	}
	else
	{
		put_nbr(nbr / 10, len);
		put_nbr(nbr % 10, len);
	}
}

static char	*handle_selectorr(char *p, int *len, va_list params)
{
	if (*p == 'c' || *p == 's'
		|| *p == 'p' || *p == '%')
	{
		if (*p == 'c')
			p = print_char(p, len, params);
		else if (*p == '%')
			p = print_percentage(p, len);
		else if (*p == 's')
			p = print_string(p, len, params);
		else
			p = print_p(p, len, params);
	}
	else if (*p == 'd' || *p == 'i' || *p == 'u'
		|| *p == 'x' || *p == 'X')
	{
		if (*p == 'x' || *p == 'X')
			p = print_hexa(p, len, params);
		else if (*p == 'd' || *p == 'i')
			p = print_di(p, len, params);
		else
			p = print_u(p, len, params);
	}
	else
		p = "";
	return (p);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	char	*p;
	va_list	params;

	len = 0;
	p = (char *)str;
	va_start(params, str);
	while (*p)
	{
		if (*p == '%')
		{
			p ++;
			p = handle_selectorr(p, &len, params);
		}
		else
		{
			write(1, p, 1);
			len ++;
			p ++;
		}
	}
	va_end(params);
	return (len);
}
