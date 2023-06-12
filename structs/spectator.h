/*
* header file for spectator.h
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "mem.h"
#include "message.h"

typedef struct spectator spectator_t;

/**** spectator_new() ****/
/* 
 * This function creates an spectator object which holds and addr_t object and returns a spectator_t* object. 
 * Caller provides: 
 *   Valid server address 
 * We do: 
 *   Returns a spectator_t* object
 *   Returns NULL if the spectator object it creates or if the parameter is NULL
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
spectator_t* spectator_new(addr_t* address);

/****** spectator_getAddress ******/
/* 
 * This function takes in a spectator_t pointer.
 * Caller provides: 
 *   spectator object 
 * We do: 
 *   Returns the spectator's address variable which is a addr_t object
 *   Returns a NULL pointer otherwise
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
addr_t* spectator_getAddress(spectator_t* spectator);

/****** spectator_delete ****/
/* 
 * This function takes in a spectator pointer, if it is NULL, does nothing 
 * Caller provides: 
 *   spectator object pointer
 * We do: 
 *   Deletes this spectator and frees the memory of the objects
 *   If the spectator pointer is NULL, does nothing
 *   Returns NULL if the spectator object it creates or if the parameter is NULL
 * We assume: 
 *   The message is not malformed (is of form ERROR [explanation])
 */
void spectator_delete(spectator_t* spectator);