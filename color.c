/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:40:20 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 12:03:37 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static double	color_hue_to_rgb(double p, double q, double t)
{
	if (t < 0.0)
		t += 1.0;
	if (t > 1.0)
		t -= 1.0;
	if (t < 1.0 / 6.0)
		return (p + (q - p) * 6.0 * t);
	if (t < 1.0 / 2.0)
		return (q);
	if (t < 2.0 / 3.0)
		return (p + (q - p) * (2.0 / 3.0 - t) * 6.0);
	return (p);
}

t_color	color_rgb(double h, double s, double l)
{
	double		q;
	double		p;
	t_color	color;

	if (s == 0.0)
		return ((t_color){l, l, l, COLOR_RGB});
	else
	{
		if (l < 0.5)
			q = l * (1.0 + s);
		else
			q = l + s - l * s;
		p = 2.0 * l - q;
		color.x = color_hue_to_rgb(p, q, h + 0.333333);
		color.y = color_hue_to_rgb(p, q, h);
		color.z = color_hue_to_rgb(p, q, h - 0.333333);
		color.format = COLOR_RGB;
	}
	return (color);
}

t_color color_hsl(double r, double g, double b)
{
	double		v_max;
	double		v_min;
	double		delta;
	t_color color;

	v_max = math_max((double[]){ r, g, b }, 3);
	v_min = math_min((double[]){ r, g, b }, 3);
	color.x = (v_max + v_min) / 2.0;
	color.y = (v_max + v_min) / 2.0;
	color.z = (v_max + v_min) / 2.0;
	if (v_max == v_min)
		return ((t_color){0.0, 0.0, color.z, COLOR_HSL});
	delta = v_max - v_min;
	if (color.z > 0.5)
		color.y = delta / (2.0 - delta);
	else
		color.y = delta / color.y;
	if (v_max == r)
		color.x = (g - b) / delta + ((g < b) * 6.0);
	if (v_max == g)
		color.x = (b - r) / delta + 2.0;
	if (v_max == b)
		color.x = (r - g) / delta + 4.0;
	color.x /= 6.0;
	return ((t_color){color.x, color.y, color.z, COLOR_HSL});
}

unsigned int	color_mlx(t_color in_col)
{
	unsigned int	out_col;

	if (in_col.format == COLOR_HSL)
		in_col = color_rgb(in_col.x, in_col.y, in_col.z);
	out_col = 0;
	out_col |= (unsigned int)(in_col.x * 255.0) << (8 * 2);
	out_col |= (unsigned int)(in_col.y * 255.0) << (8 * 1);
	out_col |= (unsigned int)(in_col.z * 255.0) << (8 * 0);
	return (out_col);
}
