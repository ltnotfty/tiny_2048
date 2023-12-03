#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <ncurses.h>

#include "game_draw.h"
#include "game_dir.h"
#include "game_core.h"

extern int game_over;
extern int quit;

extern int scores;
extern int max_scores;

void init_ncurse_settings( void );
void init_game( void );
void init_sys_settings( void );


int process_input( int ch );


void game_init( void );
void game_loop( void );
void game_end( void );



#endif
