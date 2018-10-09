/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:32:11 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:18:57 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void s_md5(int i, int j, char **argv, char *option)
{
	char *str;
	int len;
	int x;

	len = 0;
	x = 0;
	if (argv[i][j + 1] == '\0')
		str = ft_strdup(argv[i + 1]);
	else
	{
		x = j + 1;
		while (argv[i][x] != '\0')
		{
			x++;
			len++;
		}
		str = malloc(sizeof(char) * (len + 1));
		x = 0;
		while (argv[i][j+ 1] != '\0')
		{
			str[x] = argv[i][j + 1];
			x++;
			j++;	
		}
		str[x] = '\0';
	}
	md5_calculation(prepare(str), option, str);	
}

void p_md5(char *option)
{
	char buff[21];
	int buffsize;
	char *str;
	int x;

	buffsize = 20;
	while ((x = read(0, buff, 20)))
	{
		str = ft_strnew(0);
		buff[x] = '\0';
		str = joinandsave(str, buff);
	}
	md5_calculation(prepare(str), option, str);	
}

int parse_option(int argc, char **argv, char *option, int i)
{
	int j;

	j = 0;
	if (argv[i][j] == '-')
	{
		j++;
		while (argv[i][j] != '\0')
		{
			invalid_option(argv[i][j]);
			if (argv[i][j] == 'q' || argv[i][j] == 'r')
				add_option(argv[i][j], option);
			if (argv[i][j] == 'p')
			{
				add_option(argv[i][j], option);
				p_md5(option);
				exit(1);
			}
			if (argv[i][j] == 's' && argv[i][j + 1] == '\0' && argc == i + 1)	
			{
				ft_printf("Error : \'s\' option needs [string]\n");
				break;
			}
			if (argv[i][j] == 's')
			{
				s_md5(i, j, argv, option);
				break;
			}
			j++;
		}
	}
	return (i + 1);
}
