/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 05:35:54 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/04 16:21:36 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

size_t	ft_putchar(int c);
size_t	ft_putstr(char *str);
size_t	ft_putnbrhexa(unsigned int nb);
size_t	ft_puthexap(unsigned long int);
size_t	ft_puthexamaj(unsigned int nb);
size_t	ft_putunsignednbr(unsigned int nb);
size_t	ft_putnbr(int nb);
size_t	ft_printarg(char c, va_list args);
int		ft_printf(const char *str, ...);
int	ft_count(int nb);
int	ft_ucount(unsigned int nb);


#endif
