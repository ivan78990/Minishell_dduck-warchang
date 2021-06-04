#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H

#include <unistd.h>

#include <stdlib.h>
#include <term.h>
#include <termios.h>
#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "libft/libft.h"

//Parser
int 	ifkey(char c);
char 	*ft_dollar(char *str, int *i, char **env);
char 	*ft_slesh(char *str, int *i);
char	*ft_gap2(char *str, int *i, char **env);
char 	*ft_gap(char *str, int *i);
void 	parser(char *str, char **env);
//Utils
//int		ft_putchar(char c);
//int		ft_putstr(char *str);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);
//int		ft_strlen(const char *s);
//char	*ft_strrchr(const char *s, int c);

#endif //MINISHELL_MINISHELL_H
