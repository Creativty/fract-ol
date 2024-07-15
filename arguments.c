/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:56:04 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 10:42:58 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "library.h"

int	write_string(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	prog_args_usage(const char *name, int flag)
{
	write_string("error: invalid arguments.\n");
	write_string("usages:\n");
	if (flag == 0 || flag & 1)
	{
		write_string("\t");
		write_string(name);
		write_string(" mandelbrot\n");
	}
	if (flag == 0 || flag & 2)
	{
		write_string("\t");
		write_string(name);
		write_string(" julia <real> <imaginary>\n");
	}
	return (0);
}

int	prog_args(const int argc, const char **argv)
{
	int	match_julia;
	int	match_mandelbrot;

	match_mandelbrot = string_match(argv[1], "mandelbrot");
	if (match_mandelbrot && argc == 2)
		return (1);
	match_julia = string_match(argv[1], "julia") << 1;
	if (match_julia && argc == 4)
	{
		if (atof_form_check(argv[2]) && atof_form_check(argv[3]))
			return (2);
	}
	return (prog_args_usage(argv[0], match_mandelbrot | match_julia), 0);
}
