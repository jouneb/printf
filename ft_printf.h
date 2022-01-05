/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 05:35:54 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/05 12:02:43 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_putchar(int c);
size_t	ft_putstr(char *str);
size_t	ft_putnbrhexa(unsigned int nb);
size_t	ft_puthexap(unsigned long int nb);
size_t	ft_puthexamaj(unsigned int nb);
size_t	ft_putunsignednbr(unsigned int nb);
size_t	ft_putnbr(int nb);
size_t	ft_printarg(char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_count(int nb);
int		ft_ucount(unsigned int nb);

#endif
