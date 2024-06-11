/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:20:22 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 12:00:44 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H
# define SCREEN 640
# define PALETTE 32
# define ZOOM_MIN 0.5
# define ZOOM_MAX 1024.0
# define ITERATIONS_MIN 1
# define ITERATIONS_MAX 2048
# define XK_SCROLL_UP 4
# define XK_SCROLL_DOWN 5

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_state
{
	t_complex		offset;
	t_complex		params;
	unsigned int	(*render_pixel)(struct s_state *, double, double);
	void			*img;
	void			*mlx;
	void			*win;
	double			zoom;
	int				render;
	int				iterations;
}	t_state;

typedef struct s_mandelbrot
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	x2;
	double	y2;
}	t_mandelbrot;

typedef enum e_color_format
{
	COLOR_RGB,
	COLOR_HSL,
}	t_color_format;

typedef struct s_color
{
	double			x;
	double 			y;
	double 			z;
	t_color_format	format;
}	t_color;

double			atof(const char *a);
double			atof_form_check(const char *a);
int				string_len(const char *str);
int				string_count(const char *str, const char c);
int				string_index(const char *str, const char c);
int				string_match(const char *lhs, const char *rhs);
void			fractol_zoom_in(t_state *state);
void			fractol_zoom_out(t_state *state);
void			*memory_zero(void *region, unsigned int size);
void			*memory_set(void *region, unsigned int size,
					unsigned char byte);
double			complex_mod(t_complex x);
t_complex		complex_new(long double real, long double imag);
t_complex		complex_add(t_complex lhs, t_complex rhs);
t_complex		complex_conjugate(t_complex x);
t_complex		complex_square(t_complex x);
t_state			state_new(void);
int				state_render(t_state *state);
unsigned int	*image_pixel_at(void *img, int x, int y);
unsigned int	render_pixel_julia(t_state *state, double x, double y);
unsigned int	render_pixel_mandelbrot(t_state *state, double x, double y);
void			destroy_mlx(void *mlx);
void			destroy_window(void *mlx, void *win);
void			destroy_image(void *mlx, void *win, void *img);
int				prog_args(const int argc, const char **argv);
int				prog_args_usage(const char *name, int flag);
int				prog_close(t_state *state);
int				prog_keypress(int key, t_state *state);
int				prog_mousepress(int key, int x, int y, t_state *state);
double			math_max(double *list, int elem_count);
double			math_min(double *list, int elem_count);
t_color			color_hsl(double r, double g, double b);
t_color			color_rgb(double h, double s, double l);
unsigned int	color_mlx(t_color in_col);
#endif
