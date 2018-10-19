/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:53:32 by kykim             #+#    #+#             */
/*   Updated: 2018/10/17 20:46:43 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t		**sha256_make_words(int block_num)
{
	u_int32_t	**words;
	int			i;

	i = 0;
	words = malloc(sizeof(u_int32_t *) * (block_num + 1));
	while (i < block_num)
	{
		words[i] = malloc(sizeof(u_int32_t) * 64);
		ft_bzero(words[i], 64);
		i++;
	}
	words[block_num] = NULL;
	return (words);
}

void			sha256_fill_the_words(u_int32_t **words, unsigned char **block)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (block[i] != NULL)
	{
		sha256_assign(words, block, i);
		i++;
	}
}

void			sha256_add_length(const char *str, u_int32_t **words)
{
	int				i;
	long long int	len;

	i = 0;
	len = 8 * ft_strlen(str);
	while (words[i] != '\0')
		i++;
	i -= 1;
	words[i][15] = len;
	words[i][14] = (len & 0xffffffff00000000) >> 32;
}

u_int32_t		**expand_words(u_int32_t **words)
{
	int i;
	int j;

	i = 0;
	while (words[i] != '\0')
	{
		j = 16;
		while (j < 64)
		{
			words[i][j] = total_expand(words, i, j);
			j++;
		}
		i++;
	}
	return (words);
}

u_int32_t		**sha256_prepare(const char *str)
{
	u_int32_t		**words;
	unsigned char	**block;
	int				blocknum[1];

	block = block_make(str, blocknum);
	fill_block(str, block);
	words = sha256_make_words(blocknum[0]);
	sha256_fill_the_words(words, block);
	sha256_add_length(str, words);
	expand_words(words);
	free_block(block);
	return (words);
}
