/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:56:04 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 10:57:10 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "library.h"

int	prog_args_usage(const char *name, int flag)
{
	printf("error: invalid arguments.\n");
	printf("usages:\n");
	if (flag == 0 || flag & 1)
		printf("\t%s mandelbrot\n", name);
	if (flag == 0 || flag & 2)
		printf("\t%s julia <real> <imaginary>\n", name);
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
	if (match_julia && argc == 4 && atof_form_check(argv[2]) && atof_form_check(argv[3]))
		return (2);
	return (prog_args_usage(argv[0], match_mandelbrot | match_julia), 0);
}
