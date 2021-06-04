#include "Minishell.h"

int 	ifkey(char c)
{
	if (c == '_' || ft_isalnum(c))
		return 1;
	return 0;
}

char 	*ft_dollar(char *str, int *i, char **env)
{
	int j = *i;
	int z;
	char *tmp;
	char *tmp2;
	char *tmp3;

	while (str[++(*i)])
	{
		if (!ifkey(str[*i]))
			break;
	}
	if (*i == j + 1)
		return (str);

	tmp = ft_substr(str, j + 1, *i - j - 1);
	int k = -1;
	while (env[++k])
	{
		if (strstr(env[k], tmp))
		{

			z = 0;
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp2 = ft_substr(env[k], 0, z);
			if (strcmp(tmp, tmp2) == 0)
				break ;
			printf("tmp2 = %s\n", tmp2);
			printf("NASHEL\n");

		}
	}
	tmp2 = ft_substr(env[k], z + 1, strlen(env[k]) - z);
	printf("tmp2111 = %s\n", tmp2);
	printf("key = %s\n", tmp );

	return (tmp);
}

char 	*ft_slesh(char *str, int *i)
{
	char *tmp;
	char *tmp2;
	while (str[++(*i)])

	tmp = ft_substr(str, 0, *i);
	printf("tmp = %s\n", tmp);
	tmp2 = ft_strdup(str + *i + 1);
	printf("tmp2 = %s\n", tmp2);
	tmp = ft_strjoin(tmp, tmp2);
	free(str);
	++(*i);
//	free;
//	free;
	printf("tmp = %s\n", tmp);
	return (tmp);
}
char	*ft_gap2(char *str, int *i, char **env)
{
	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	while (str[++(*i)])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' ||
		str[*i + 1] == '\\'))
			str = ft_slesh(str, i);
		if (str[*i] == '$')
			ft_dollar(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	printf("tmp = %s\n", tmp );
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	printf("tmp2 = %s\n", tmp2 );
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
//	free;
	tmp = ft_strjoin(tmp, tmp3);
//	free;
	printf("tmp = %s\n", tmp );
	free(str);
	return (tmp);
}
char 	*ft_gap(char *str, int *i)
{

	int j = *i;
	char *tmp;
	char *tmp2;
	char *tmp3;

	while (str[++(*i)])
	{
		if (str[*i] == '\'')
			break;
	}
	tmp = ft_substr(str, 0, j);
	printf("tmp = %s\n", tmp );
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	printf("tmp2 = %s\n", tmp2 );
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
//	free;
	tmp = ft_strjoin(tmp, tmp3);
//	free;
	printf("tmp = %s\n", tmp );
	free(str);
	return (tmp);
}


void 	parser(char *str, char **env)
{
	// "", '', \, $, ;, |, <, >, >>, ' '
	int i;

	printf("\nstr = %s\n\n", str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = ft_gap(str, &i);
		if (str[i] == '\"')
			str = ft_gap2(str, &i, env);
		if (str[i] == '\\')
			str = ft_slesh(str, &i);
		if (str[i] == '$')
			ft_dollar(str, &i, env);
	}
	printf("\nstr = %s\n", str);
}

//int 	preparser(char *str)
//{
//	while (str[++i])
//		do something
//}



int		main(int argc, char **argv, char **env)
{
//	Печать env
//	int i = -1;
//	while(env[++i])
//		printf("%s\n", env[i]);

	char  *str = ft_strdup("com$USER ma'n\\nn'dddd0000'dfdf\"fdfdggf\"\"da");
//	char  *str1 = ft_strdup("ls lol kek; ls kek lol");
//	char **mal = {{"ls", "lol",  "kek"} {"ls", "kek", "lol"}};

	parser(str, env);

//int fd;
//int fd2;
//
//// >NAME
//
//
//	fd = open("NAME", O_CREAT | O_TRUNC, 0644);
//	close(fd);
//	printf("%s\n", strerror(errno));
//// >>NAME
//	fd = open("NAME", O_WRONLY | O_CREAT | O_APPEND, 0644);
//	printf("%s\n", strerror(errno));
//// <NAME
//	fd2 = open("rofl", O_RDONLY, 0644);
//	dup2(fd, 1);
//	dup2(fd2, 0);
//	printf("%s\n", strerror(errno));
}

