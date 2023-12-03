#ifndef GAME_DRAW_H
#define GAME_DRAW_H

#include <ncurses.h>

#include "game_core.h"
#include "game_control.h"


#define BARR_V_CHAR '|'
#define BARR_H_CHAR '-'



static int GRID_WIDTH = 8;
static int GRID_HEIGHT = 4;



static inline int get_kth_number_r( int kth )
{
    return kth * ( GRID_HEIGHT + 1) + ( GRID_HEIGHT >> 1); 
}

static inline int get_kth_number_c( int kth )
{
    return kth * ( GRID_WIDTH + 1) + ( GRID_WIDTH >> 1) ;
}



void show_number( void );
void show_status( void );
void show_bound ( void );

void draw_frame( void );

#endif
