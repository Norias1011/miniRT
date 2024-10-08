/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   props_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:55:57 by jullopez          #+#    #+#             */
/*   Updated: 2024/09/18 19:53:40 by jullopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	ambient_init(t_scene *scene, char **args)
{
	if (scene->ambient)
		return (parser_error("You cannot provide two ambient lightning"), -1);
	scene->ambient = gc_calloc(sizeof(struct s_ambient));
	if (!scene->ambient)
		return (-1);
	if (ft_strlen2(args) != 3)
		return (parser_error("Bad arguments number ambiant"), -1);
	if (set_ratio(args[1], &scene->ambient->light_ratio) == -1)
		return (parser_error("Bad ratio number ambiant"), -1);
	if (set_rgb(args[2], &scene->ambient->color) == -1)
		return (parser_error("Bad RGB arguments ambiant"), -1);
	return (0);
}

int	camera_init(t_scene *scene, char **args)
{
	if (scene->cam)
		return (parser_error("Scene can't have multiple cameras"), -1);
	scene->cam = gc_calloc(sizeof(struct s_cam));
	if (!scene->cam)
		return (-1);
	if (ft_strlen2(args) != 4)
		return (parser_error("Bad arguments number camera"), -1);
	if (set_vector3d(&scene->cam->pos, args[1]) == -1)
		return (parser_error("Bad coordinate for camera"), -1);
	if (set_normalized_vector3d(&scene->cam->dir, args[2]) == -1)
		return (parser_error("Bad arguments 3D vector camera"), -1);
	if (set_fov(args[3], &scene->cam->fov) == -1)
		return (parser_error("Bad fov for camera"), -1);
	return (0);
}
