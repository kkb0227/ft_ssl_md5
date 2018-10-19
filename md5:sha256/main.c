/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:57:09 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 17:33:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	main(int argc, char **argv)
{
	int i;
	int option[5];

	i = 2;
	usage_error(argc, argv);
	zero(option);
	if (!ft_strcmp(argv[1], "md5"))
		command_md5(argc, argv, option);
	else if (!ft_strcmp(argv[1], "sha256"))
		command_sha256(argc, argv, option);
	return (0);
}
