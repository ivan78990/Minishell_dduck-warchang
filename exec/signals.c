#include "../minishell.h"

void	ctrl_c(int signo)
{
	if (signo == SIGINT)
	{
		g_global.recieved = 1;
		rl_on_new_line();
		rl_redisplay();
		write (2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ctrl_slash(int signo)
{
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "", 1);
	}
}

void	conrol_d(void)
{
	write(2, "\033[3;1m", 7);
	write(2, "\e[1A\e[11Cexit\n", 15);
	g_global.recieved = 0;
	exit(0);
}

void	signal_normal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void signals_ign(int signo)
{
	if (signo)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

//signal(SIGINT, SIG_DFL);