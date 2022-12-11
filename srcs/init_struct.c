/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:56:12 by engo              #+#    #+#             */
/*   Updated: 2022/12/11 13:37:49 by vloth            ###   ########.fr       */
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

t_data	*init_parsing(char *str)
{
	t_data	*init;
	
	init = malloc(sizeof(*init));
	if (!init)
		return (NULL);
	init->nbpipe = pipe_or_not(str);
	init->nbcmd = init->nbpipe + 1;
	init->begin = NULL;
	init->end = NULL;
	return (init);
}

void	init_one_cmd(t_data *data, char *str)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return ;
	if (data->nbcmd == 1)
	{
		tmp->cmd = str;
		data->begin = tmp;
		data->end = tmp;
		tmp->back = NULL;
		tmp->next = NULL;
	}
}