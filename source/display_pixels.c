/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:21:11 by vrichese          #+#    #+#             */
/*   Updated: 2019/12/10 17:51:39 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			pixel_put(t_mlx_var *mlx_var, int x, int y, int color)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= mlx_var->screen.width || y >= mlx_var->screen.heigh)
		return ;
	mlx_var->array[mlx_var->screen.width * y + x] = color;
}

int				get_color(int f_col, int s_col, int length, int i)
{
	int			r;
	int			g;
	int			b;

	r = F_RED + (S_RED - F_RED) * i / length;
	g = F_GREEN + (S_GREEN - F_GREEN) * i / length;
	b = F_BLUE + (S_BLUE - F_BLUE) * i / length;
	return ((r << 16) | (g << 8) | b);
}

void			display_line(t_mlx_var *mlx_var, int x1, int y1, int i)
{
	int			delta[2];
	int			sign[2];
	int			err[2];
	int			length;

	delta[X] = abs((int)mlx_var->maps->x_scaled - x1);
	delta[Y] = abs((int)mlx_var->maps->y_scaled - y1);
	sign[X] = x1 < (int)mlx_var->maps->x_scaled ? 1 : -1;
	sign[Y] = y1 < (int)mlx_var->maps->y_scaled ? 1 : -1;
	err[0] = delta[X] - delta[Y];
	length = (int)sqrt(delta[X] * delta[X] + delta[Y] * delta[Y]);
	pixel_put(mlx_var, mlx_var->maps->x_scaled,
	mlx_var->maps->y_scaled, mlx_var->maps->color);
	while (x1 != (int)mlx_var->maps->x_scaled ||
	y1 != (int)mlx_var->maps->y_scaled)
	{
		pixel_put(mlx_var, x1, y1, get_color(mlx_var->rear->color, mlx_var->maps->color, length, i++));
		err[1] = err[0] * 2;
		if (err[1] > -delta[Y] && ((err[0] -= delta[Y]) >= 0 || err[0] < 0))
			x1 += sign[X];
		if (err[1] < delta[X] && ((err[0] += delta[X]) >= 0 || err[0] < 0))
			y1 += sign[Y];
	}
}

void			draw_line(t_mlx_var *mlx_var, int x1, int y1, int x2, int y2)
{
	int xx1 = x1;
	int yy1 = y1;

	x1 = 0;
	y1 = 0;
	x2 -= xx1;
	y2 -= yy1;

	float sample = (float)y2 / (float)x2;

	while (x1 != x2 || y1 != y2)
	{
		float right_top	= fabs(sample - ((float)(y1 + 1) / (float)(x1 + 1)));
		float right		= fabs(sample - ((float)y1 / (float)(x1 + 1)));
		float top		= fabs(sample - ((float)(y1 + 1) / (float)x1));
		if (right_top < right && right_top < top)
		{
			x1 += 1;
			y1 += 1;
		}
		else if (right < right_top && right < top)
			x1 += 1;
		else
			y1 += 1;
		pixel_put(mlx_var, x1 + xx1, y1 + yy1, 0x580ead);
	}
}

void		draw_circle4(t_mlx_var *mlx_var, int x1, int y1, float r)
{
	pixel_put(mlx_var, x1, y1, 0x580ead);
	int xx1 = x1;
	int yy1 = y1;
	x1 = -(int)r;
	y1 = 0;
	while (x1 != -1)
	{
		float one = fabs(r - sqrtf(powf(x1 + 1, 2.0f) + powf(y1, 2.0f)));
		float two = fabs(r - sqrtf(powf(x1 + 1, 2.0f) + powf(y1 - 1, 2.0f)));
		float three = fabs(r - sqrtf(powf(x1, 2.0f) + powf(y1 - 1, 2.0f)));
		if (one <= two && one <= three)
			x1 += 1;
		else if (two <= one && two <= three)
		{
			x1 += 1;
			y1 -= 1;
		}
		else if (three <= one && three <= two)
			y1 -= 1;
		pixel_put(mlx_var, x1 + xx1, y1 + yy1, 0x580ead);
	}
}

void 		draw_circle3(t_mlx_var *mlx_var, int x1, int y1, float r)
{
	pixel_put(mlx_var, x1, y1, 0x580ead);
	int xx1 = x1;
	int yy1 = y1;
	x1 = -(int)r;
	y1 = 0;
	while (x1 != -1)
	{
		float one = fabs(r - sqrtf(powf(x1, 2.0f) + powf(y1 + 1, 2.0f)));
		float two = fabs(r - sqrtf(powf(x1 + 1, 2.0f) + powf(y1 + 1, 2.0f)));
		float three = fabs(r - sqrtf(powf(x1 + 1, 2.0f) + powf(y1, 2.0f)));
		if (one <= two && one <= three)
			y1 += 1;
		else if (two <= one && two <= three)
		{
			x1 += 1;
			y1 += 1;
		}
		else if (three <= one && three <= two)
			x1 += 1;
		pixel_put(mlx_var, x1 + xx1, y1 + yy1, 0x580ead);
	}
}

void		draw_circle2(t_mlx_var *mlx_var, int x1, int y1, float r)
{
	pixel_put(mlx_var, x1, y1, 0x580ead);
	int xx1 = x1;
	int yy1 = y1;
	x1 = (int)r;
	y1 = 0;
	while (x1 != 1)
	{
		float one = fabs(r - sqrtf(powf(x1 - 1, 2.0f) + powf(y1, 2.0f)));
		float two = fabs(r - sqrtf(powf(x1 - 1, 2.0f) + powf(y1 + 1, 2.0f)));
		float three = fabs(r - sqrtf(powf(x1, 2.0f) + powf(y1 + 1, 2.0f)));
		if (one <= two && one <= three)
			x1 -= 1;
		else if (two <= one && two <= three)
		{
			x1 -= 1;
			y1 += 1;
		}
		else if (three <= one && three <= two)
			y1 += 1;
		pixel_put(mlx_var, x1 + xx1, y1 + yy1, 0x580ead);
	}
}

void		draw_circle(t_mlx_var *mlx_var, int x1, int y1, float r)
{
	pixel_put(mlx_var, x1, y1, 0x580ead);
	int xx1 = x1;
	int yy1 = y1;
	x1 = (int)r;
	y1 = 0;
	while (x1 != 1)
	{
		float one = fabs(r - sqrtf(powf(x1, 2.0f) + powf(y1 - 1, 2.0f)));
		float two = fabs(r - sqrtf(powf(x1 - 1, 2.0f) + powf(y1 - 1, 2.0f)));
		float three = fabs(r - sqrtf(powf(x1 - 1, 2.0f) + powf(y1, 2.0f)));
		if (one <= two && one <= three)
			y1 -= 1;
		else if (two <= one && two <= three)
		{
			x1 -= 1;
			y1 -= 1;
		}
		else if (three <= one && three <= two)
			x1 -= 1;
		pixel_put(mlx_var, x1 + xx1, y1 + yy1, 0x580ead);
	}
	draw_circle2(mlx_var, xx1, yy1, r);
	draw_circle3(mlx_var, xx1, yy1, r);
	draw_circle4(mlx_var, xx1, yy1, r);
}

void	some_fun(t_mlx_var *mlx_var)
{
	vec2	test;

	test.data[LA_X] = mlx_var->linear_algebra.vectors.x;
	test.data[LA_Y] = mlx_var->linear_algebra.vectors.y;
	//test.data[LA_Z] = mlx_var->linear_algebra.vectors.z;
	//test.data[LA_W] = mlx_var->linear_algebra.vectors.w;

	scalar_product_of_vectors(mlx_var);
}

void			display_pixels(t_mlx_var *mlx_var)
{
	mlx_var->iterator = mlx_var->maps->prev->count + 1;
	memset(mlx_var->array, 35, mlx_var->screen.width * mlx_var->screen.heigh * 4);
	while (mlx_var->iterator--)
	{
		some_fun(mlx_var);
		mlx_var->maps->x_scaled = mlx_var->screen.width / 2
		+ mlx_var->linear_algebra.vectors.x;
		mlx_var->maps->y_scaled = mlx_var->screen.heigh / 2
		+ mlx_var->linear_algebra.vectors.y;
		if (mlx_var->maps->prev->x < mlx_var->maps->x)
		{
			mlx_var->rear = mlx_var->maps->prev;
			display_line(mlx_var, mlx_var->maps->prev->x_scaled,
			mlx_var->maps->prev->y_scaled, 1);
		}
		if (mlx_var->maps->upper && (mlx_var->rear = mlx_var->maps->upper))
		{
			display_line(mlx_var, mlx_var->maps->upper->x_scaled,
			mlx_var->maps->upper->y_scaled, 1);
		}
		mlx_var->maps = mlx_var->maps->next;
	}
	mlx_put_image_to_window(mlx_var->io, mlx_var->window, mlx_var->image, 0, 0);
	mlx_var->flags.hint ? add_hint(mlx_var) : 0;
}
