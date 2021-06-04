#include "Minishell.h"

char    buf[100];
char    *buffer;

int ft_putint(int c)
{
	return (write(1, &c, 1));
}
void	termcap()
{
	char str[2000];
	int l;
	struct termios term;
	char *term_name = "xterm-256color";

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
//	term.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	write(1, "➜  Minishell $ ", 17);

	memset(str, '\0', 2000);
	while (strcmp(str, "\4"))
	{

		tputs(save_cursor, 1, ft_putint);
		do
		{
			l = read(0, str, 100);
			// Нажатие стрелка вверх
			if (!strcmp(str, "\e[A"))
			{
				memset(str, '\0', l);
				tputs(restore_cursor, 1, ft_putint);
				tputs(tigetstr("ed"), 1, ft_putint);
				write(1, "previous", 8);
			}
				// Нажатие стрелка вниз
			else if (!strcmp(str, "\e[B"))
			{
				memset(str, '\0', l);
				tputs(restore_cursor, 1, ft_putint);
				tputs(tigetstr("ed"), 1, ft_putint);
				write(1, "next", 4);
			}
				// Нажатие Backspace
			else if (!strcmp(str, "\177"))
			{
				memset(str, '\0', l);
				tputs(cursor_left, 1, ft_putint);
				tputs(tigetstr("ed"), 1, ft_putint);
			}

				// Нажатие Enter (при нажатии Enter запускается парсер)
//			else if (!strcmp(str, "\n"))
//			{
//				parser(str, env);
//			}
			else
				write(1, str, l);
		} while (strcmp(str, "\n"));
	}
	write(1, "\n", 1);

}

int main(int argc, char *argv[], char const *env[])
{
	termcap();
	return 0;
}