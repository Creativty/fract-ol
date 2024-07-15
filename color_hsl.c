/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:44 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 10:58:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static void	color_hsl_internals(
	t_color *color, double rgb[3], double v_interval[2])
{
	double	delta;

	color->x = (v_interval[0] + v_interval[1]) / 2.0;
	color->y = color->y;
	color->z = color->z;
	delta = v_interval[0] - v_interval[1];
	if (color->z > 0.5)
		color->y = delta / (2.0 - delta);
	else
		color->y = delta / color->y;
	if (v_interval[0] == rgb[0])
		color->x = (rgb[1] - rgb[2]) / delta + ((rgb[1] < rgb[2]) * 6.0);
	if (v_interval[0] == rgb[1])
		color->x = (rgb[2] - rgb[0]) / delta + 2.0;
	if (v_interval[0] == rgb[2])
		color->x = (rgb[0] - rgb[1]) / delta + 4.0;
	color->x /= 6.0;
}

static t_color	color_hsl_contrast_less(double luminosity)
{
	t_color	color;

	color.x = 0.0;
	color.y = 0.0;
	color.z = luminosity;
	color.format = COLOR_HSL;
	return (color);
}

t_color	color_hsl(double r, double g, double b)
{
	double		rgb[3];
	double		v_interval[2];
	t_color		color;

	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	v_interval[0] = math_max(rgb, 3);
	v_interval[1] = math_min(rgb, 3);
	if (v_interval[0] == v_interval[1])
		return (color_hsl_contrast_less((v_interval[0] + v_interval[1]) / 2.0));
	color_hsl_internals(&color, rgb, v_interval);
	return ((t_color){color.x, color.y, color.z, COLOR_HSL});
}
