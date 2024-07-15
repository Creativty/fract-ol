/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:47:29 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 11:07:37 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

// mandelbrot f(x, y) where xE[-2.00, 0.47] and ye[-1.12, 1.12];
t_mandelbrot	mandelbrot_context_new(double px_x, double px_y)
{
	t_mandelbrot	ctx;

	memory_zero(&ctx, sizeof(ctx));
	ctx.x0 = ((px_x / (double)SCREEN) * 2.48) - 2.01;
	ctx.y0 = ((px_y / (double)SCREEN) * 2.48) - 1.24;
	return (ctx);
}

unsigned int	pixel_color_mandelbrot(double idx, double max)
{
	double			components[3];
	t_color			col_hsl;

	components[0] = 0.00 + (idx / max);
	components[1] = 1.0 - ease_out_quad(idx / max) / 2;
	components[2] = ease_out_quad(idx / max);
	col_hsl = color_rgb(components[0], components[1], components[2]);
	return (color_mlx(col_hsl));
}

unsigned int	render_pixel_mandelbrot(t_state *state, double x, double y)
{
	int				idx;
	t_mandelbrot	ctx;
	int				max;

	idx = 0;
	max = state->iterations;
	ctx = mandelbrot_context_new(x, y);
	while (ctx.x2 + ctx.y2 <= 4.0 && idx < max)
	{
		ctx.y = (ctx.x + ctx.x) * ctx.y + ctx.y0;
		ctx.x = ctx.x2 - ctx.y2 + ctx.x0;
		ctx.x2 = ctx.x * ctx.x;
		ctx.y2 = ctx.y * ctx.y;
		idx++;
	}
	if (idx == max)
		return (0x00000000);
	return (pixel_color_mandelbrot(idx, max));
}
