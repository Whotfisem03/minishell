/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:37:44 by engo              #+#    #+#             */
/*   Updated: 2022/12/13 00:48:24 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_env(char **envp)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char) * tab_count(envp) + 1);
	while (envp[i])
	{
		dest[i] = envp[i];
		i++;
	}
	return (dest);
}
