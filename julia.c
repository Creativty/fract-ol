/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:48:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 11:06:49 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_complex	math_julia(double x, double y, double p, double q)
{
	double			real;
	double			imag;
	const double	screen_half = (double)SCREEN / 2.0;

	real = p * (x - screen_half) / screen_half;
	imag = q * (y - screen_half) / screen_half;
	return (complex_new(real, imag));
}

unsigned int	pixel_color_julia(double idx, double max)
{
	double			components[3];
	t_color			col_hsl;

	components[0] = 0.00 + (idx / max);
	components[1] = 1.0 - ease_out_quad(idx / max) / 2;
	components[2] = ease_out_quad(idx / max);
	col_hsl = color_rgb(components[0], components[1], components[2]);
	return (color_mlx(col_hsl));
}

unsigned int	render_pixel_julia(t_state *state, double x, double y)
{
	int				idx;
	int				max;
	t_complex		val;

	idx = 0;
	max = state->iterations;
	val = math_julia(x, y, -2.0, 2.0);
	while (idx < max)
	{
		val = complex_add(complex_square(val), state->params);
		if (complex_mod(val) > 2.0)
			break ;
		idx++;
	}
	return (pixel_color_julia(idx, max));
}
