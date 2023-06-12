/* Group 13 - Lost at C
 * visibility.h - header file for the visibility program
 * 
 */

#ifndef __VISIBILITY_H
#define __VISIBILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "grid.h"
#include "message.h"

/********** is_visible *********/
/* 
 * This function creates a line between the player coordinates and each of the coordinates on the map 
 * Increments from the lower coordinate to the higher coordinate and checks if the line is obstructed by any obstacles
 * If the line is not obstructed, the coordinate is visible to the player
 * Caller provides: 
 *   grid map, coordinates of the point in the grid and of the player 
 * We do: 
 *   Returns True if visible, False if not
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
bool is_visible(grid_t* grid, const int pc, const int pr, const int c, const int r);

/********* return_visible ********/
/* 
 * runs the is_visible method across the entire map then returns a grid representative of the player's visibility
 * Caller provides: 
 *   String of the grid map, width and height of the map, coordinates of the point checking if visible 
 * We do: 
 *   Returns a grid_t object of the visible grid
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
grid_t* return_visible(grid_t* grid, int width, int height, int x, int y);

/********* join_two_grid **********/
/* 
 * This function takes in the old grid and the current grid and merges them together
 * Caller provides: 
 *   grid_t pointers of the two maps and width and height of the maps 
 * We do: 
 *   Returns a subset of the master mapgrid
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
void join_two_grid(grid_t* old, grid_t* merge, int width, int height);

#endif 