/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:03:05 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/03 13:03:07 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

size_t	ft_putchar(char c)
{
	size_t	t;

	t = 0;
	write (1, &c, 1);
	t++;
	return (t);
}

size_t ft_putstr(char *str)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		t++;
		i++;
	}
	return(t);
}
size_t	ft_putnbrhexa(unsigned long int nb)
{
	unsigned int nbr;
	char	*base;
	size_t	t;

	t = 0;
	base = "0123456789abcdef";
	nbr = nb;
	if (nb <= 15)
		t = t + ft_putchar(base[nb]);
	if(nb > 15)
	{
		ft_putnbrhexa(nb / 16);
		t = t + ft_putchar(base[nb % 16]);
	}
	return (t);
}

size_t	ft_putnbr(int nb)
{
	size_t		i;
	size_t		t;
	long int	nbr;

	i = 0;
	t = 0;
	nbr = nb;
	if (nbr < 0)
	{
		t = t + ft_putchar('-');
		nb = nb * -1;
	}
	if (nbr > 0 && nbr <= 9)
		t = t + ft_putchar(nb + '0');
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		t = t + ft_putchar(nb % 10 + '0');
	}
	return (t);
}

size_t ft_printarg(char c, va_list args)
{
	size_t	t;

	t = 0;
	if( c == 'c')
		t = ft_putchar(va_arg(args, int));
	if(c == 's')
		t = ft_putstr(va_arg(args, char *));
	if(c == 'p')
		t = ft_puthexap(va_arg(args, unsigned long int));
	if(c == 'd')
		t = ft_putnbr(va_arg(args, long int));
	if(c == 'i')
		t = ft_putnbr(va_arg(args, long int));
	if(c == 'u')
		ft_putunsignednbr(va_arg(args, unsigned int));
	if(c == 'x')
		t = ft_putnbrhexa(va_arg(args, unsigned int));
	if(c == 'X')
		t = ft_puthexamaj(va_arg(args, unsigned int));
	if (c == '%')
		t = write (1, "%", 1);
	return(t);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int flag;
	va_list args;
	size_t t;

	va_start(args, str);
	i = 0;
	flag = 0;
	t = 0;
	while (str[i])
	{

		if (str[i] == '%' && flag == 0)
		{
			flag = 1;
			i++;
		}
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'u' || str[i] == 'i' || str[i] == 'x' || str[i] == 'X'
			)
		{
			if (flag == 1)
			{
				t = t + ft_printarg(str[i], args);
				i++;
			}
			flag = 0;
		}
		t = t + write (1, &str[i], 1);
		i++;
	}
	va_end (args);
	return (t);
}

int main ()
{
	int p[] = {1232};
	printf(" %s\n", "jesuiscorrect");
	ft_printf(" %s\n", "jesuiscorrect");
	printf("%p\n", p);
	ft_printf("%p\n", p);
	ft_printf("c = %c\n",'a');
	printf("c = %c\n",'a');
	ft_printf(" %d\n", 1789);
	printf(" %d", 1789);
	ft_printf(" %i\n", 1984);
	printf(" %i\n", 1984);
	ft_printf("%%\n");
	printf("%%\n");
}
