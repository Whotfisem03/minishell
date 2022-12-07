/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:22:23 by engo              #+#    #+#             */
/*   Updated: 2022/12/07 01:17:32 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	built_pwd(char *str)
// {
// 	char	*dest;
// }

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
		/*___07/12 : pwd+env+qq bug ___*/
	if (ft_strncmp(str, "pwd", ft_strlen("pwd")) == 0)
	{	
		getcwd(buf, 100);
		printf("%s\n", buf);
	}
	if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		built_env(env);
		/*__________*/
		
}
