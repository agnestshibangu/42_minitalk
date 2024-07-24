#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft_utils_bonus.c"

size_t  ft_strlen(const char *s);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *str, int fd);
int	ft_atoi(const char *str);

#endif