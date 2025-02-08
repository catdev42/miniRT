/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:50:42 by myakoven          #+#    #+#             */
/*   Updated: 2025/02/08 20:23:42 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDE/minirt.h"

/* HSLa to RGBa*/

uint32_t    hsla_to_rgba(t_hsla hsla)
{
    float chroma = (1 - fabsf(2 * hsla.light / 100 - 1)) * hsla.sat / 100;
    float hue_sector = hsla.hue / 60;
    float secondary = chroma * (1 - fabsf(fmodf(hue_sector, 2) - 1));
    float light_adj = hsla.light / 100 - chroma / 2;
    
    t_rgba color;
	ft_memset(&color, 0, sizeof(t_rgba));
	
    if (hue_sector >= 0 && hue_sector < 1)
        {color.r = chroma; color.g = secondary;}
    else if (hue_sector < 2)
        {color.r = secondary; color.g = chroma;}
    else if (hue_sector < 3)
        {color.g = chroma; color.b = secondary;}
    else if (hue_sector < 4)
        {color.g = secondary; color.b = chroma;}
    else if (hue_sector < 5)
        {color.r = secondary; color.b = chroma;}
    else
        {color.r = chroma; color.b = secondary;}
    
    color.r = (color.r + light_adj) * 255;
    color.g = (color.g + light_adj) * 255;
    color.b = (color.b + light_adj) * 255;
    color.a = hsla.alpha * 255;
    return (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
}