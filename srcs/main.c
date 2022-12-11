/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:55:19 by engo              #+#    #+#             */
/*   Updated: 2022/12/11 18:35:05 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	(void)ac;
	(void)av;
	(void)env;
	t_data	*data;
	t_cmd *caca;

	str = NULL;
	while (1)
	{
		str = readline("mini> ");
		data = init_parsing(str);
		init_struct(str, data);
		
		caca = data->begin;
		while (caca)
		{
			printf("%s\n", caca->cmd);
			caca = caca->next;
		}
		free_list(data);
		add_history(str);
		free(str);
	}
}
