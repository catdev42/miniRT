/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:59 by myakoven          #+#    #+#             */
/*   Updated: 2025/02/08 20:02:06 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}			t_vec3;

typedef struct s_point3
{
	float	x;
	float	y;
	float	z;
}			t_point3;

typedef struct s_point2
{
	int		x;
	int		y;
}			t_point2;

// Color HSLA
typedef struct s_hsla
{
	float hue;   // Hue [0-360]
	float sat;   // Saturation [0-100]
	float light; // Lightness [0-100]
	float alpha; // Alpha [0-1]
}			t_hsla;

// Color structures
typedef struct s_rgba
{
	uint8_t r; // Red [0-255]
	uint8_t g; // Green [0-255]
	uint8_t b; // Blue [0-255]
	uint8_t a; // Alpha [0-255]
}			t_rgba;

#endif
