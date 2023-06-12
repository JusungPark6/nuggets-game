/*
* player module : implements data structure to hold key player information
* no Makefile or test yet
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "mem.h"
#include "message.h"
#include "grid.h"

typedef struct player {
    int x;
    int y;
    int purse;
    char* name;
    addr_t* address;
    char playerChar;
    grid_t* visibleGrid;
} player_t;

/* getter methods */
int player_getX(player_t* player) {
    return player ? player->x : -1;
}
int player_getY(player_t* player) {
    return player ? player->y : -1;
}
int player_getPurse(player_t* player) {
    return player ? player->purse : -1;
}
char* player_getName(player_t* player) {
    if (player!=NULL) {
        return player->name;
    }
    return NULL;
}
addr_t* player_getAddress(player_t* player) {
    return player ? player->address : NULL;
}
char* player_getChar(player_t* player) {
    //printf("%c\n", player->playerChar);
    return player ? &player->playerChar : '\0';
}
grid_t* player_getGrid(player_t* player) {
    if (player!=NULL) {
        return player->visibleGrid;
    }
    return NULL;
}

// initialize a new player with the passed position (randomly generated numbers in server). Initialize purse to be empty
player_t* player_new(int x, int y, char* name, addr_t* address) {
    player_t* player = mem_malloc(sizeof(player_t));
    if (x>0 && y>0 && name!=NULL) {                         // impossible for player to be at (0,0)
        player->x = x;
        player->y = y;
        player-> name = name;
        player->purse = 0;
        player->address = address;
        player->playerChar = '\0';
        player->visibleGrid = NULL;
        return player;
    }   
    return NULL;
}

// new x and y positions are passed from the server where they are validated to be within grid
void player_updatePos(player_t* player, int x, int y) {
    if (player!=NULL && x>0 && y>0) {
        player->x = x;
        player->y = y;
    }
}

// updates the player's purse after they have collected gold
void player_updatePurse(player_t* player, int nuggets) {
    if (player!=NULL && nuggets>0) {
        player->purse = player->purse + nuggets;
    }
}

bool player_setChar(player_t* player, char c) {
   if (player!=NULL) {
    player->playerChar = c;
    return true;
   }
   else {
    return false;
   }
}

bool player_setGrid(player_t* player, grid_t* grid) {
    if (player!=NULL && grid!=NULL) {
        player->visibleGrid = grid;
        return true;
    }
    return false;
}

bool player_setAddress(player_t* player, addr_t* address) {
    if (player!=NULL) {
        player->address = address;
        return true;
    }
    else {
        return false;
    }
}

void player_delete(player_t* player) {
    if (player!=NULL) {
        if (player->address != NULL) {
            mem_free(player->address);
        }
        if (player->name!=NULL) {
            mem_free(player->name);
        }
        if (player->visibleGrid!=NULL) {
            grid_delete(player->visibleGrid);
            player->visibleGrid = NULL;
        }
        mem_free(player);
    }
}