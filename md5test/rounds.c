/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:57:38 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:41:49 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const int hash[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

const int shift[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,};

void round1(u_int32_t ABCD[4], u_int32_t **words, int n)
{
	int i;
	u_int32_t x;

	i = 0;
	while (i < 16)
	{
		x = (ABCD[0] + F(ABCD[1], ABCD[2], ABCD[3]) + words[n][i] + hash[i]);
		x = rotate_left(x, shift[i]);
		ABCD[0] = ABCD[1] + x;
		switch_order(ABCD);
		i++;
	}
}

void	round2(u_int32_t ABCD[4], u_int32_t **words, int n)
{
	int i;
	u_int32_t x;

	i = 16;
	while (i < 32)
	{
		x = (ABCD[0] + G(ABCD[1], ABCD[2], ABCD[3]) + words[n][((i * 5 + 1) % 16)] + hash[i]);
		x = rotate_left(x, shift[i]);
		ABCD[0] = ABCD[1] + x;
		switch_order(ABCD);
		i++;
	}
}

void	round3(u_int32_t ABCD[4], u_int32_t **words, int n)
{
	int i;
	u_int32_t x;

	i = 32;
	while (i < 48)
	{
		x = (ABCD[0] + H(ABCD[1], ABCD[2], ABCD[3]) + words[n][((i * 3 + 5) % 16)] + hash[i]);
		x = rotate_left(x, shift[i]);
		ABCD[0] = ABCD[1] + x;
		switch_order(ABCD);
		i++;
	}
}

void	round4(u_int32_t ABCD[4], u_int32_t **words, int n)
{
	int i;
	u_int32_t x;

	i = 48;
	while (i < 64)
	{
		x = (ABCD[0] + I(ABCD[1], ABCD[2], ABCD[3]) + words[n][((i * 7) % 16)] + hash[i]);
		x = rotate_left(x, shift[i]);
		ABCD[0] = ABCD[1] + x;
		switch_order(ABCD);
		i++;
	}
}

u_int32_t *rounds(u_int32_t *ABCD, u_int32_t **words)
{
	u_int32_t temp[4];
	int i;
		
	i = 0;
	while (words[i])
	{
		temp[0] = ABCD[0];
		temp[1] = ABCD[1];
		temp[2] = ABCD[2];
		temp[3] = ABCD[3];
		round1(temp, words, i);
		round2(temp, words, i);
		round3(temp, words, i);
		round4(temp, words, i);
		ABCD[0] += temp[0];
		ABCD[1] += temp[1];
		ABCD[2] += temp[2];
		ABCD[3] += temp[3];
		i++;
	}
	return (ABCD);
}