#include "minitalk.h"

static void message_end(int client_pid)
{
    kill(client_pid, SIGUSR2);
    client_pid = 0;
    return;
}

static void recreate_msg(int sig, siginfo_t *info, void *context)
{
    static int i = 0;
    static pid_t client_pid = 0;
    static unsigned char c = 0;

    (void)context;

    if (client_pid == 0)
        client_pid = info->si_pid;

    if (sig == SIGUSR2)
        c |= (1 << i);
    i++;

    if (i == 8)
    {
        i = 0;
        if (c == '\0')
            message_end(client_pid);
        ft_putchar_fd(c, 1);
        c = 0;
        kill(client_pid, SIGUSR1);
    }
}

int main()
{
    struct sigaction s_sigaction;

    ft_putstr_fd("server pid : ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n\n", 1);

    s_sigaction.sa_sigaction = recreate_msg;
    s_sigaction.sa_flags = SA_SIGINFO;
    sigemptyset(&s_sigaction.sa_mask);

    sigaction(SIGUSR1, &s_sigaction, NULL);
    sigaction(SIGUSR2, &s_sigaction, NULL);

    while (1)
        pause();

    return (0);
}

