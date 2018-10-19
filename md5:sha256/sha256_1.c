/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:51:32 by kykim             #+#    #+#             */
/*   Updated: 2018/10/17 20:32:02 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t	rotate_right(u_int32_t x, int s)
{
	return ((x >> s) | (x << (32 - s)));
}

u_int32_t	expand1(u_int32_t **words, int i, int j)
{
	return ((rotate_right(words[i][j - 15], 7)) ^
	(rotate_right(words[i][j - 15], 18)) ^ (words[i][j - 15] >> 3));
}

u_int32_t	expand2(u_int32_t **words, int i, int j)
{
	return ((rotate_right(words[i][j - 2], 17)) ^
	(rotate_right(words[i][j - 2], 19)) ^ (words[i][j - 2] >> 10));
}

u_int32_t	total_expand(u_int32_t **words, int i, int j)
{
	return (words[i][j - 16] + expand1(words, i, j)
	+ words[i][j - 7] + expand2(words, i, j));
}
