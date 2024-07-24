#include "minitalk.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void handle_end(int pid)
{
    int i;
    
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);
        usleep(100);
    }
}

static void     decompose(int pid, char *str)
{

    int     i;
    int     y;
    char c;

    y = 0;
    while (str[y])
    {
        i = 0;
        c = str[y];
        while (i < 8)
        {
            if (c & (1 << i))
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(2500);
            i++;
        }
        y++;
    }
    handle_end(pid);
}

int main(int ac, char **av)
{
    struct sigaction s_sigaction;

    if (ac != 3 || !ft_strlen(av[2]))
        return (1);
    s_sigaction.sa_handler = action;
    sigemptyset(&s_sigaction.sa_mask);
    s_sigaction.sa_flags = 0;
    sigaction(SIGUSR1, &s_sigaction, NULL);
    sigaction(SIGUSR2, &s_sigaction, NULL);
    ft_putstr_fd("Sent :", 1);
    ft_putnbr_fd(ft_strlen(av[2]), 1);
    ft_putchar_fd('\n', 1);
    decompose(ft_atoi(av[1]), av[2]);
    return (0);
}
