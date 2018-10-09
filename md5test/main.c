/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:57:09 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:13:47 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void md5(char **av)
{
	int index[1];
	char *option;

	option = options(av, index);
	if (!check_option('s', option))
		md5_calculation(prepare(av[index[0]]), option, av[index[0]]);
}

int main(int argc, char **argv)
{
	char *option;

	
	option = malloc(sizeof(char) * 4);
	ft_bzero(option, 4);
	usage_error(argc, argv);
	parse_option(argc, argv, option, 2);
	// md5(argv);
	
	return (0);
}