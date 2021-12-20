/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:27:24 by jbouyer           #+#    #+#             */
/*   Updated: 2021/12/20 17:10:08 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_putnbrhexa(unsigned int nb)
{
	unsigned int nbr;
	char	*base;

	base = "0123456789abcdef";
	nbr = nb;
	if (nb <= 15)
		ft_putchar(base[nb]);
	if(nb > 15)
	{
		ft_putnbrhexa(nb / 16);
		ft_putchar(base[nb % 16]);
	}
}

void	ft_putnbr(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb <= 9)
		ft_putchar(nb);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10);
	}
}

void ft_printarg(char conv, char *str)
{
	va_list args;

	va_start(args, str);
	if( conv == 'c')
		ft_putchar(va_arg(args, int));
	if(conv == 's')
		ft_putstr(va_arg(args, char *));
	if(conv == 'p')
		ft_putnbrhexa(va_arg(args, int));
//	if(conv == 'd')
//		ft_putdecimalnb(va_arg(args, int));
	if(conv == 'i')
		ft_putnbr(va_arg(args, int));
//	if(str[i] == u)
//		ft_putunsignednb(va_arg(args, unsigned int));
	if(conv == 'x')
		ft_putnbrhexa(va_arg(args, unsigned long));
//	if(str[i] == X)
//	va_arg(args, unsigned int);
	if (conv == '%')
		write (1, "%", 1);
	va_end (args);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{

		if (str[i] == '%')
			flag = 1;
		else if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' 
				 || str[i] == 'u' || str[i] == 'i' || str[i] == 'x' || str[i] == 'X'
				 || str[i] == '%' )
		{
			if (flag == 1)
				ft_printarg(str[i], str);
			flag = 0;
		}
		write (1, &str[i], 1);
		i++;
	}
}

int main ()
{
	printf("%s\n", "jesuiscorrect");
	ft_printf("%s\n", "jesuiscorrect");
	printf("%p\n", 123);
	ft_printf("%p\n", 123);
	printf("%%");
	ft_printf("%%");
}


to do ; 
a faire : il faut remettre dans la artie printf less histoires de args avec la definition et tout et ensuite envoyer a printarg, sinon ca le prend pas forcementt en compte> noter que i et d sont les memes, et les seules subtilites sont en terme de type majoritairement. et c'est ce a quoi il faut faire attention.
