/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:32:11 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 12:45:27 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*argv_to_str(int i, int j, char **argv)
{
	char	*str;
	int		x;
	int		len;

	len = 0;
	x = j + 1;
	while (argv[i][x] != '\0')
	{
		x++;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	x = 0;
	while (argv[i][j + 1] != '\0')
	{
		str[x] = argv[i][j + 1];
		x++;
		j++;
	}
	str[x] = '\0';
	return (str);
}

int		s_md5(int i, int j, char **argv, int *option)
{
	char	*str;
	int		len;
	int		x;

	len = 0;
	x = 0;
	if (argv[i][j + 1] == '\0')
	{
		str = ft_strdup(argv[i + 1]);
		i += 1;
	}
	else
		str = argv_to_str(i, j, argv);
	md5_calculation(prepare(str), option, str);
	free(str);
	return (i);
}

void	p_md5(int *option)
{
	char	buff[21];
	char	*str;
	int		x;

	str = ft_strnew(0);
	if (!option[4])
	{
		while ((x = read(0, buff, 20)))
		{
			buff[x] = '\0';
			str = joinandsave(str, buff);
		}
	}
	md5_calculation(prepare(str), option, str);
	free(str);
}

int		parse_option(int argc, char **argv, int option[5], int i)
{
	int j;

	j = 1;
	while (argv[i][j] != '\0')
	{
		invalid_option(argv[i][j]);
		option_q_r(argv, i, j, option);
		if (argv[i][j] == 'p')
			option[2] = 1;
		else if (argv[i][j] == 's')
		{
			if (argv[i][j] == 's' && argv[i][j + 1] == '\0' && argc == i + 1)
				print_error();
			option[3] = 1;
			if (!ft_strcmp(argv[1], "md5"))
				i = s_md5(i, j, argv, option);
			else if (!ft_strcmp(argv[1], "sha256"))
				i = sha256_s_md5(i, j, argv, option);
			break ;
		}
		j++;
	}
	return (i);
}
