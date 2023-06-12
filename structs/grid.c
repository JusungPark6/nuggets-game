/* 
 * grid.c - 'grid' module
 * 
 * See grid.h for more information.
 *
 * Robert Vogt (Lost at C) CS50 WI23
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mem.h"
#include "file.h"
#include <string.h>
#include <stdbool.h>

/**************** file-local global variables ****************/
/* none */

/**************** global types ****************/
typedef struct grid{
  int width;
  int height;
  char** array;
}grid_t;

/**************** global functions ****************/
/* see grid.h for comments about exported functions */

/**************** grid_get_array ****************/
/* see grid.h for description */
char** grid_get_array(grid_t* grid)
{
  if (grid != NULL) {
    return grid->array;
  } 
  return NULL;
}

/**************** grid_get_height ****************/
/* see grid.h for description */
int grid_get_height(grid_t* grid)
{
  if (grid == NULL) {
    return -1;
  }
  return grid->height;
}

/**************** grid_get_width ****************/
/* see grid.h for description */
int grid_get_width(grid_t* grid)
{
   if (grid == NULL) {
    return -1;
  }
  return grid->width;
}

/**************** grid_load ****************/
/* see grid.h for description */
grid_t* grid_load(char* filename)
{
  if (filename == NULL) {
    return NULL;
  }

  FILE* gridFile = fopen(filename, "r");
  if (gridFile == NULL) {
    return NULL;
  }
  grid_t* grid = mem_malloc(sizeof(grid_t));

  // (assuming we want to use coords starting at 0) 
  // set height and width
  grid->height = file_numLines(gridFile) - 1;
  char* line = file_readLine(gridFile);
  grid->width = strlen(line);
  grid->array = (char**)mem_malloc((grid->height+1)*sizeof(char*));
  
  // put each line into the array and set the length of the longest
  // read lined from the file into the array
  for(int i = 0; i <= grid->height; i++) {
    grid->array[i] = line;
    line = file_readLine(gridFile);
  }
  
  free(line);
  fclose(gridFile);
  return grid;
}

char grid_get_char_at(grid_t* grid, int x, int y)
{
  if (grid == NULL) {
    return '\0';
  }
  if (x > grid->width || x < 0 || y > grid->height || y < 0) {
    return '\0';
  } else {
    return grid->array[y][x];
  }
}

/**************** grid_change_char_at ****************/
/* see grid.h for description */
bool grid_change_char_at(grid_t* grid, int x, int y, char c)
{
  // validate grid and coordinates
  if (grid == NULL || x > grid->width || x < 0 || y > grid->height || y < 0) {   
    // return false if the character could not be replaced
    return false;
  }
  // return true if character was replaced
  grid->array[y][x] = c;
  return true;
}

/**************** grid_toString****************/
/* see grid.h for description */
char* grid_toString(grid_t* grid)
{
  if (grid == NULL || grid->array == NULL) {
    return NULL;
  }
  // allocate memory for returned string
  char* gridStr = calloc(((grid->width+1) * (grid->height+1)), sizeof(char));
  for (int i = 0; i <= grid->height; i++) {          
    strcat(gridStr, grid->array[i]); 
  }
  return gridStr;
}

/**************** grid_new ****************/
/* see grid.h for description */
grid_t* grid_new(char** array, int width, int height)
{
  grid_t* grid = mem_malloc(sizeof(grid_t));
  if (grid == NULL || array == NULL) {
    return NULL;
  }
  grid->array = array;
  grid->height = height;
  grid->width = width;
  return grid;
}

/**************** grid_delete ****************/
/* see grid.h for description */
void grid_delete(grid_t* grid) {
  if (grid == NULL) {
    return;
  }
  for (int i = 0; i <= grid->height; i++) {
    mem_free(grid->array[i]);
  }
  mem_free(grid->array);
  mem_free(grid);
}