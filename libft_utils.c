#include "minitalk.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return ((size_t)i);
}

void    ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return;
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int nb, int fd)
{
    if (nb < 0)
        nb = -nb;
    if (nb >= 10)
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putnbr_fd(nb % 10, fd);
    }
    else
        ft_putchar_fd(nb + '0', fd);
}

void    ft_putstr_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

int	ft_atoi(const char *str)
{
	int		nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}