/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:55:50 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:42:22 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_SSL_H
# define FT_SSL_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "library/ft_libft/libft.h"
#include "library/Get_Next_Line/get_next_line.h"
#include "library/ft_printf/ft_printf.h"

//funcitons
u_int32_t F(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t G(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t H(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t I(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t rotate_left(u_int32_t x, int s);

//rounds
void round1(u_int32_t ABCD[4], u_int32_t **words, int n);
void round2(u_int32_t ABCD[4], u_int32_t **words, int n);
void round3(u_int32_t ABCD[4], u_int32_t **words, int n);
void round4(u_int32_t ABCD[4], u_int32_t **words, int n);
u_int32_t *rounds(u_int32_t *ABCD, u_int32_t **words);

//process
void switch_order(u_int32_t ABCD[4]);
u_int32_t make_lil(u_int32_t X);
void print_result(u_int32_t ABCD[4]);

//blockmake
unsigned char **block_make(const char *str, int blocknum[1]);
void         fill_block(const char *str, unsigned char **block);

//wordmake
u_int32_t **make_words(int block_num);
void    fill_the_words(u_int32_t **words, unsigned char **block);
void    add_length(const char *str, u_int32_t **words);

//free
void free_block(unsigned char **block);

//md5
u_int32_t	**prepare(const char *str);
void md5_calculation(u_int32_t **words, char *option, char *str);

//error_option
void usage_error(int ac, char **av);
void invalid_option(char x);
int check_option(char x, char *option);
void add_option(char x, char *option);
char *options(char **av, int index[1]);

//parsing
void s_md5(int i, int j, char **argv, char *option);
int parse_option(int argc, char **argv, char *option, int i);
#endif