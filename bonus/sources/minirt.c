/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:16:38 by jullopez          #+#    #+#             */
/*   Updated: 2024/09/11 17:36:40 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	main(int argc, char *argv[])
{
	t_scene				scene;
	t_threads_container	cont;

	cont.scene = &scene;
	if (argc != 2)
		return (ft_err(ERR_USAGE, 0), 0);
	if (ft_parsing(&scene, argv[1]) == -1)
		return (gc_dump(NULL), 0);
	if (init_mlx_all(&scene) == -1)
		return (gc_dump(NULL), 0);
	if (threads_init(&scene, &cont, 32) == -1)
		return (gc_dump(NULL), 0);
	mlx_hook(scene.mlx.win, 17, 0, close_window, &cont);
	mlx_hook(scene.mlx.win, KeyPress, KeyPressMask, key_press, &cont);
	mlx_hook(scene.mlx.win, KeyRelease, KeyReleaseMask, key_release, &cont);
	mlx_loop_hook(scene.mlx.mlx, &render_scene, &cont);
	mlx_loop(scene.mlx.mlx);
	return (0);
}
