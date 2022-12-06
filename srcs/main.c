/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:55:19 by engo              #+#    #+#             */
/*   Updated: 2022/12/06 01:59:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;
	(void)ac;
	(void)av;
	(void)envp;

	// init_struct();
	str = NULL;
	printf("%d\n", tab_count(envp));
	while (1)
	{
		str = readline("mini> ");
		check_builtin(str);
		add_history(str);
	}
}
