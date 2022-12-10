/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:56:12 by engo              #+#    #+#             */
/*   Updated: 2022/12/10 17:44:54 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_or_not(char *str)
{
	int	i;
	int pipe;

	pipe = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '|')
		{
			if (str[i + 1] == 0)
				return (-1);
			if (str[i + 1] == '|')
			{
				if (str[i + 1] == 0)
					return (-1);
				i++;
			}
			pipe++;
		}
	}
	return (pipe);
}

t_data	init_parsing(char *str)
{
	t_data	init;
	
	init.nbpipe = pipe_or_not(str);
	init.nbcmd = init.nbpipe + 1;
	return (init);
}