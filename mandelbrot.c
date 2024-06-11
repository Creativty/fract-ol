/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:47:29 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 11:20:52 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_mandelbrot	mandelbrot_context_new(double px_x, double px_y)
{
	t_mandelbrot	ctx;

	memory_zero(&ctx, sizeof(ctx));
	ctx.x0 = ((px_x / (double)SCREEN) * 2.48) - 2.01; // [-2.00, 0.47] x
	ctx.y0 = ((px_y / (double)SCREEN) * 2.48) - 1.24; // [-1.12, 1.12] y
	return (ctx);
}

unsigned int	render_pixel_mandelbrot(t_state *state, double x, double y)
{
	int				idx;
	t_mandelbrot	ctx;
	unsigned int	col;
	int				max;

	idx = 0;
	col = 0;
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
	col |= (127 + (int)(((double)idx / (double)max) * 127.0)) << (8 * 0);
	col |= (127 + (int)(((double)idx / (double)max) * 127.0)) << (8 * 1);
	col |= ((127 + (int)(((double)idx / (double)max) * 234.0)) % 255) << (8 * 2);
	return (col);
}
