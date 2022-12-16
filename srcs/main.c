/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:55:19 by engo              #+#    #+#             */
/*   Updated: 2022/12/16 20:57:31 by vloth            ###   ########.fr       */
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
		add_history(str);
		data = init_parsing(str);
		init_struct(str, data);
		caca = data->begin;
		while(caca != NULL)
		{
			printf("nb de commande = %d\n", data->nbcmd);
			printf("%s\n", caca->cmd);
			caca = caca->next;
		}
		//check_builtin(str, env);
		free_list(data);
		free(str);
	}
	rl_clear_history();
}
