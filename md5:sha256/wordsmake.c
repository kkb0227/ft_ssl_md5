/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordsmake.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:38:23 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 11:10:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t	**make_words(int block_num)
{
	u_int32_t	**words;
	int			i;

	i = 0;
	words = malloc(sizeof(u_int32_t *) * (block_num + 1));
	while (i < block_num)
	{
		words[i] = malloc(sizeof(u_int32_t) * 16);
		ft_bzero(words[i], 16);
		i++;
	}
	words[block_num] = NULL;
	return (words);
}

void		assign_block(u_int32_t **words, unsigned char **block, int i)
{
	int	x;
	int	temp;

	x = 0;
	temp = 0;
	while (x < 64)
	{
		if (x % 4 == 3)
			temp += block[i][x] << 24;
		else if (x % 4 == 2)
			temp += block[i][x] << 16;
		else if (x % 4 == 1)
			temp += block[i][x] << 8;
		else if (x % 4 == 0)
			temp += block[i][x];
		if (x % 4 == 3)
		{
			words[i][x / 4] = temp;
			temp = 0;
		}
		x++;
	}
}

void		fill_the_words(u_int32_t **words, unsigned char **block)
{
	int	i;

	i = 0;
	while (block[i] != NULL)
	{
		assign_block(words, block, i);
		i++;
	}
}

void		add_length(const char *str, u_int32_t **words)
{
	int				i;
	long long int	len;

	i = 0;
	len = 8 * ft_strlen(str);
	while (words[i] != '\0')
		i++;
	i -= 1;
	words[i][14] = len;
	words[i][15] = (len & 0xffffffff00000000) >> 32;
}

void		option_q_r(char **argv, int i, int j, int *option)
{
	if (argv[i][j] == 'q')
		option[0] = 1;
	if (argv[i][j] == 'r')
		option[1] = 1;
}
