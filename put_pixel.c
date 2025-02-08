/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:32:47 by myakoven          #+#    #+#             */
/*   Updated: 2025/02/08 20:22:56 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDE/minirt.h"
#include "./INCLUDE/structs.h"

void	convert_to_screen(mlx_image_t *image, float cx, float cy,
		t_point2 *screen_point)
{
	screen_point->x = image->width / 2 + cx;
	screen_point->y = image->height / 2 + cy;
}

/* Expects image pointer, location of x and y on a canvas (calculate from 3d) and pixel_color */
void	put_pixel(mlx_image_t *image, float cx, float cy, int32_t pixel_color)
{
	t_point2	screen_point;
	size_t pixel_pos;
	convert_to_screen(image, cx, cy, &screen_point);
	pixel_pos = screen_point.y * image->width + screen_point.x;
	image->pixels[pixel_pos] = pixel_color;
}
