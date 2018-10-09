/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:55:46 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:41:48 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t F(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return ((b & c) | (~b & d));
}

u_int32_t G(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return ((b & d) | (c & ~d));
}

u_int32_t H(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return (b ^ c ^ d);
}

u_int32_t I(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return (c ^ (b | ~d));
}

u_int32_t rotate_left(u_int32_t x, int s)
{
	return ((x << s) | (x >> (32 - s)));
}
