/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:52:40 by kykim             #+#    #+#             */
/*   Updated: 2018/10/17 20:32:59 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t	s0(u_int32_t a)
{
	return (rotate_right(a, 2) ^ rotate_right(a, 13) ^ rotate_right(a, 22));
}

u_int32_t	s1(u_int32_t e)
{
	return (rotate_right(e, 6) ^ rotate_right(e, 11) ^ rotate_right(e, 25));
}

u_int32_t	ch(u_int32_t x, u_int32_t y, u_int32_t z)
{
	return ((x & y) ^ (~x & z));
}

u_int32_t	maj(u_int32_t a, u_int32_t b, u_int32_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}
