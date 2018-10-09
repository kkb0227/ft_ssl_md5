/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:30:07 by kykim             #+#    #+#             */
/*   Updated: 2018/09/29 23:14:09 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void usage_error(int ac, char **av)
{
	if (ac < 2)
	{
		printf("usage: ft_ssl command [command opts] [command args]\n");
		exit(1);
	}
	if ((ft_strcmp(av[1], "md5") != 0) && (ft_strcmp(av[1], "sha256") != 0))
	{
		ft_printf("ft_ssl: Error: \'%s\' is an invaild command.\n\n", av[1]);
		ft_printf("Standard Commands:\n\n");
		ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
		ft_printf("Cipher commands:\n");
		exit(1);
	}
}

void invalid_option(char x)
{
	if (x != 'p' && x != 'q' && x != 'r' && x != 's')
	{
		ft_printf("Error: Invalid oprtion(Valid options : p, q, r, s)\n");
		exit(1);
	}
}

int check_option(char x, char *option)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if(option[i] == x)
			return (0);
		i++;
	}
	return (1);
}

void add_option(char x, char *option)
{
	int i;
	int j;
	
	i = 0;
	j = check_option(x, option);
	if (j)
	{
		while (i < 4)
		{
			if (!option[i])
			{
				option[i] = x;
				break;
			}
			i++;
		}
	}
}

char *options(char **av, int index[1])
{
	int i;
	int j;
	char *option;

	i = 2;
	option = malloc(sizeof(char) * 4);
	ft_bzero(option, 4);
	while (av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			invalid_option(av[i][j]);
			add_option(av[i][j], option);
			if (av[i][j] == 's')
			{
			
			}
			j++;
		}
		i++;
	}
	index[0] = i;
	return (option);
}