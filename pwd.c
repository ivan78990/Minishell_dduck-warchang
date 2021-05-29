#include <stdio.h>
#include <unistd.h>
#include "Minishell.h"

int main(void)
{
	char *dir;
	int i;

	dir = NULL;
	dir = getcwd(dir, 0);
//	i = chdir(dir);
	printf("\033[32m" "➜  Minishell " "\033[0m" "%s\n", dir);
	free(dir);
	return 0;
}

