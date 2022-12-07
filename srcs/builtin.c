/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:22:23 by engo              #+#    #+#             */
/*   Updated: 2022/12/07 04:52:12 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_echo(char *str)
{
	int i;
	int n;

	i = 5;
	n = 0;
	while (str[i])
	{
		n++;
		i++;
	}
	return n;
}

void	built_echo(char *str)
{
	char *line;
	char *grand_line;
	int y = count_echo(str);
	line = ft_substr(str, 5, y);
	grand_line = ft_strtrim(line, " ");
	printf("%s\n", grand_line);
}

void	built_cd(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = &str[i + 3];
	if (chdir(dest) != 0)
		printf("mini: cd: %s: No such file or directory \n", dest);
}

void	built_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}

void	check_builtin(char *str, char **env)
{
	char buf[100];//same
	if (ft_strncmp(str, "cd", ft_strlen("cd")) == 0)
		built_cd(str);
		/*___07/12 : pwd+env+unn de echo mais vite fais + qq bug ___*/
	else if (ft_strncmp(str, "pwd", ft_strlen("pwd")) == 0)
	{	
		getcwd(buf, 100);
		printf("%s\n", buf);
	}
	else if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		built_env(env);
	else if (ft_strncmp(str, "echo", ft_strlen("echo")) == 0)
		built_echo(str);
		/*__________*/
		
}
