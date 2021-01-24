/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:40:52 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 03:25:26 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"

# define ERROR -1
# define SAFE_FREE(ptr) {free(ptr); ptr = NULL;}

typedef struct		s_flags
{
	int		left_justified;
	int		zero_padding;
	int		field_width;
	int		field_width_switch;
	int		precision;
	int		precision_switch;
	int		format_error;
}					t_flags;

int					ft_printf(const char *format, ...);
int					conversion_character(char **format, va_list *args);
t_flags				*get_flags_info(char ***format, va_list *args);
int					format_error(char ***fmt, char **tmp);
int					output_c(char ***format, va_list *args,
					t_flags *current_flags);
int					output_s(char ***format, va_list *args,
					t_flags *current_flags);
int					output_int(char ***fmt, va_list *args, t_flags *flags);
int					output_u_int(char ***fmt, va_list *args, t_flags *flags);
int					output_p(char ***fmt, va_list *args, t_flags *flags);
int					output_hex(char ***fmt, va_list *args, t_flags *flags);
int					output_space_zero(t_flags *flags, int length);
int					output_left_justified(t_flags *flags, char *str,
					int length);
int					output_field_width(t_flags *flags, char *str, int count);

int					convert_num_with_flags_info(t_flags *flags, char **num,
					int negative);
int					convert_num(t_flags *flags, char ***num, int negative,
					bool route);
char				*ft_uitoa(unsigned int num, bool hex, bool upper);
char				*ft_ullitoa(unsigned long long int num, bool hex);

#endif
