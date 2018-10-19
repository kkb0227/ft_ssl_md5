/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:55:50 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 11:37:12 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "library/ft_libft/libft.h"
# include "library/Get_Next_Line/get_next_line.h"
# include "library/ft_printf/ft_printf.h"

unsigned char	**block_make(const char *str, int blocknum[1]);
void			fill_block(const char *str, unsigned char **block);
void			usage_error(int ac, char **av);
void			invalid_option(char x);
int				check_option(char x, char *option);
void			add_option(char x, char *option);
void			free_block(unsigned char **block);
void			zero(int option[5]);
void			print_error(void);
void			without_flag(char *str, int option[5]);
void			sha256_assign(u_int32_t **words, unsigned char **block, int i);
u_int32_t		f_function(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t		g_function(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t		h_function(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t		i_function(u_int32_t b, u_int32_t c, u_int32_t d);
u_int32_t		rotate_left(u_int32_t x, int s);
void			switch_order(u_int32_t abcd[4]);
u_int32_t		make_lil(u_int32_t x);
void			print_result(u_int32_t abcd[4]);
void			round1(u_int32_t abcd[4], u_int32_t **words, int n);
void			round2(u_int32_t abcd[4], u_int32_t **words, int n);
void			round3(u_int32_t abcd[4], u_int32_t **words, int n);
void			round4(u_int32_t abcd[4], u_int32_t **words, int n);
u_int32_t		*rounds(u_int32_t *abcd, u_int32_t **words);
u_int32_t		**make_words(int block_num);
void			assign_block(u_int32_t **words, unsigned char **block, int i);
void			fill_the_words(u_int32_t **words, unsigned char **block);
void			add_length(const char *str, u_int32_t **words);
void			option_q_r(char **argv, int i, int j, int *option);
char			*argv_to_str(int i, int j, char **argv);
int				s_md5(int i, int j, char **argv, int *option);
void			p_md5(int *option);
int				parse_option(int argc, char **argv, int option[5], int i);
u_int32_t		**prepare(const char *str);
void			option_neg_one(int *option, u_int32_t *checksum, char *str);
void			option_three(int *option, u_int32_t *checksum, char *str);
void			option_two_three(int *option, u_int32_t *checksum, char *str);
void			md5_calculation(u_int32_t **words, int *option, char *str);
u_int32_t		rotate_right(u_int32_t x, int s);
u_int32_t		expand1(u_int32_t **words, int i, int j);
u_int32_t		expand2(u_int32_t **words, int i, int j);
u_int32_t		total_expand(u_int32_t **words, int i, int j);
u_int32_t		s0(u_int32_t a);
u_int32_t		s1(u_int32_t e);
u_int32_t		ch(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		maj(u_int32_t a, u_int32_t b, u_int32_t c);
u_int32_t		**sha256_make_words(int block_num);
void			sha256_fill_the_words(u_int32_t **words, unsigned char **block);
void			sha256_add_length(const char *str, u_int32_t **words);
u_int32_t		**expand_words(u_int32_t **words);
u_int32_t		**sha256_prepare(const char *str);
void			sha256_shift(u_int32_t abcd[8],
u_int32_t temp1, u_int32_t temp2);
void			copy_abcd(u_int32_t origabcd[8], u_int32_t abcd[8]);
u_int32_t		*sha256_rounds(u_int32_t abcd[8], u_int32_t *word);
void			sha256(u_int32_t **words, int *option, char *str);
void			sha256_print(u_int32_t *abcd);
void			sha256_option_three(int *option, u_int32_t *abcd, char *str);
void			sha256_option_neg_one(int *option, u_int32_t *abcd, char *str);
void			sha256_option_two_three(int *option,
u_int32_t *abcd, char *str);
void			sha256_p_md5(int *option);
void			sha256_without_flag(char *str, int option[5]);
int				sha256_s_md5(int i, int j, char **argv, int *option);
void			sha256_abcd_init(u_int32_t abcd[8]);
void			command_md5_2(int *option, int i, int argc);
void			command_md5(int argc, char **argv, int option[5]);
void			command_sha256_2(int *option, int i, int argc);
void			command_sha256(int argc, char **argv, int option[5]);
void			free_words(u_int32_t **words);
#endif
