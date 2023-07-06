/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:20:27 by ggneme            #+#    #+#             */
/*   Updated: 2023/01/17 17:49:23 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*print_char(char *p, int *len, va_list params);
char	*print_percentage(char *p, int *len);
void	put_nbr(unsigned long int nbr, int *len);
char	*print_string(char *p, int *len, va_list params);
void	convert_to_hexa(unsigned long int nbr, int *len, char c);
char	*print_p(char *p, int *len, va_list params);
char	*print_hexa(char *p, int *len, va_list params);
char	*print_di(char *p, int *len, va_list params);
char	*print_u(char *p, int *len, va_list params);
#endif
