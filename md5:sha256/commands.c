/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:16:13 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 17:34:52 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	command_md5_2(int *option, int i, int argc)
{
	if (option[2] == 1)
	{
		p_md5(option);
		option[4] = 1;
	}
	else if (option[2] == 0 && option[3] == 0
	&& option[4] == 0 && i == argc - 1)
	{
		zero(option);
		p_md5(option);
	}
}

void	command_md5(int argc, char **argv, int option[5])
{
	int i;

	i = 2;
	usage_error(argc, argv);
	if (argc == 2)
		p_md5(option);
	while (i <= argc - 1)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0' && option[4] == 0)
			i = parse_option(argc, argv, option, i);
		else if (option[4] && (argv[i][1] == 's' ||
		argv[i][1] == 'r') && option[3] == 0)
			i = parse_option(argc, argv, option, i);
		else
		{
			without_flag(argv[i], option);
			i++;
			continue;
		}
		command_md5_2(option, i, argc);
		option[2] = 0;
		i++;
	}
}

void	command_sha256_2(int *option, int i, int argc)
{
	if (option[2] == 1)
	{
		sha256_p_md5(option);
		option[4] = 1;
	}
	else if (option[2] == 0 && option[3] == 0
	&& option[4] == 0 && i == argc - 1)
	{
		zero(option);
		sha256_p_md5(option);
	}
}

void	command_sha256(int argc, char **argv, int option[5])
{
	int i;

	i = 2;
	usage_error(argc, argv);
	if (argc == 2)
		sha256_p_md5(option);
	while (i <= argc - 1)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0' && option[4] == 0)
			i = parse_option(argc, argv, option, i);
		else if (option[4] && (argv[i][1] == 's' ||
		argv[i][1] == 'r') && option[3] == 0)
			i = parse_option(argc, argv, option, i);
		else
		{
			sha256_without_flag(argv[i], option);
			i++;
			continue;
		}
		command_sha256_2(option, i, argc);
		option[2] = 0;
		i++;
	}
}

void	free_words(u_int32_t **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
}
