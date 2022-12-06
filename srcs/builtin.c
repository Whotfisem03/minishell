/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:22:23 by engo              #+#    #+#             */
/*   Updated: 2022/12/06 01:49:13 by engo             ###   ########.fr       */
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
	{
		ft_putstr_fd("mini: cd: ", 2);
		ft_putstr_fd(dest, 2);
		ft_putstr_fd(": No such file or directory \n", 2);
	}
}

void	check_builtin(char *str)
{
	if (ft_strncmp(str, "cd", ft_strlen("cd")) == 0)
		built_cd(str);
}

