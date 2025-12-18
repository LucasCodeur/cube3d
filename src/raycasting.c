/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:05:29 by lud-adam          #+#    #+#             */
/*   Updated: 2025/12/18 13:21:33 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "display.h"

// bool	ray_direction(t_data *data)
// {
// 	int x = 0;
//
// 	double step_x;
// 	int map_x = (int)data->map.player.ray.pos.elements[0];
// 	int map_y = (int)data->map.player.ray.pos.elements[1];
// 	double side_dist_y;
// 	double side_dist_x;
// 	int pos_x = data->map.player.ray.pos.elements[0];
// 	int pos_y = data->map.player.ray.pos.elements[0];
// 	while (x < WIN_WIDTH)
// 	{
// 		double camera_x = 2 * x / (double)WIN_WIDTH - 1;
// 		double ray_dir_x = data->map.player.ray.dir.elements[0] + data->map.player.plane.elements[0] * data->map.player.camera.elements[0];
// 		double ray_dir_y = data->map.player.ray.dir.elements[1] + data->map.player.plane.elements[1] * data->map.player.camera.elements[0];
// 		double delta_dist_x = fabs(1 / ray_dir_x);
// 		double delta_dist_y = fabs(1 / ray_dir_y);
// 		if (ray_dir_x < 0) {
// 			step_x = -1;
// 			side_dist_x = (pos_x - map_x) * delta_dist_x;
// 		} else {
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
// 		}
// 		int stepX;
// 		int stepY;
// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?
// 		x++;
//       //calculate step and initial sideDist
//       if (ray_dir_x < 0)
//       {
//         stepX = -1;
//         side_dist_x = (pos_x - map_x) * delta_dist_x;
//       }
//       else
//       {
//         stepX = 1;
//         side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
//       }
//       if (ray_dir_y < 0)
//       {
//         stepY = -1;
//         side_dist_y = (pos_y - map_y) * delta_dist_y;
//       }
//       else
//       {
//         stepY = 1;
//         side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
//       }
// 	//perform DDA
//       while (hit == 0)
//       {
//         //jump to next map square, either in x-direction, or in y-direction
//         if (side_dist_x < side_dist_y)
//         {
//           side_dist_x += delta_dist_x;
//           map_x += stepX;
//           side = 0;
//         }
//         else
//         {
//           side_dist_y += delta_dist_y;
//           map_y += stepY;
//           side = 1;
//         }
//         //Check if ray has hit a wall
//         if (data->map.grid[map_x][map_y] > 0) hit = 1;
//       } 
// 	double perpWallDist;
//     //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
//       if(side == 0) 
// 		perpWallDist = (side_dist_x - delta_dist_x);
//       else
// 			perpWallDist = (side_dist_y - delta_dist_y);
// 	//Calculate height of line to draw on screen
//
// 		int h = 1000;
//       int lineHeight = (int)(h / perpWallDist);
//
//       //calculate lowest and highest pixel to fill in current stripe
//       int drawStart = -lineHeight / 2 + h / 2;
//       if(drawStart < 0)drawStart = 0;
//       int drawEnd = lineHeight / 2 + h / 2;
//       if(drawEnd >= h)drawEnd = h - 1;
//       //choose wall color
//       t_pixel color;
//       switch(data->map.grid[map_x][map_y])
//       {
//         case 1:  color.value = RED;  break; //red
//         case 2:  color.value = GREEN;  break; //green
//         case 3:  color.value = BLUE;   break; //blue
//         case 4:  color.value = WHITE;  break; //white
//         default: color.value = YELLOW; break; //yellow
//       }
//
//       //give x and y sides different brightness
//       if (side == 1) {color.value = color.value / 2;}
//
//       //draw the pixels of the stripe as a vertical line
//       verLine(x, drawStart, drawEnd, color);
//     }
//     //timing for input and FPS counter
//     oldTime = time;
//     time = getTicks();
//     double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//     print(1.0 / frameTime); //FPS counter
//     redraw();
//     cls();
//
//     //speed modifiers
//     double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//     double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// //    readKeys();
//     //move forward if no wall in front of you
//     if (keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if (keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if (keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if (keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
// }
