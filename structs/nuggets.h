/*
* Header file for the Nuggets 'nuggets' data structure
*
* A 'nugget' is a module providing the data structure to represent a nugget in the Nuggets game. 
* Each nugget keeps track of the pile's x and y location and the amount of gold it represents.
*
* CS50, Winter 2023
*/

#ifndef __NUGGETS_H
#define __NUGGETS_H

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "message.h"

/**************** global types ****************/
typedef struct nuggets {
    int value;
    int x;
    int y;
} nuggets_t;

/**************** nuggets_init() ****************/
/* A function to create a new nugget struct. */
/* 
* Caller provides: 
*   the location of the nugget and the number of nuggets in the pile
* We do: 
*   allocate memory for a new nugget
*   set the nugget's pile value, and x and y location
* We return: 
*   the nugget pile, if everything is successful
*   NULL, on error
*/
nuggets_t* nuggets_init(int value, int x, int y);

/**************** nuggets_delete() ****************/
/* A function to delete a nugget struct and free all of its memory */
/*
* We do: 
*   if the nugget is not null:
*     free nugget
* We return: 
*   nothing
*/
void nuggets_delete(nuggets_t* nugget);

/******** nuggets_getX ************/
/* A function to return the x coordinate location of the nugget pile */
/* 
* Caller provides: 
*   a nugget object
* We return: 
*   the nugget's x location, if the nugget is not null 
*    null otherwise 
*/
int nuggets_getX(nuggets_t* nugget);

/******** nuggets_getY ************/
/* A function to return the y coordinate location of the nugget pile */
/* 
* Caller provides: 
*   a nugget object
* We return: 
*   the nugget's y location, if the nugget is not null 
*    null otherwise 
*/
int nuggets_getY(nuggets_t* nugget);

/******** nuggets_getValue ************/
/* A function to return the amount of gold in a nugget pile */
/* 
* Caller provides: 
*   a nugget object
* We return: 
*   the amount of gold in the nugget pile, if the nugget is not null 
*    null otherwise 
*/
int nuggets_getValue(nuggets_t* nugget);

#endif