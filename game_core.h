#ifndef GAME_CORE_H
#define GAME_CORE_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game_control.h"
#include "game_dir.h"


extern int grid[100][100];

extern int MAP_ROWS;
extern int MAP_COLS;
extern int cur_empty_grids;

void get_kth_begin_rc( int kth, enum direction dir, int *pr, int *pc);

void merge_kth_line(int i, enum direction dir);
void remove_kth_space( int i, enum direction dir );

void move_to( enum direction dir );
bool is_end( void );
void put_new_number( int target_num );
void init_grid( void );


static inline bool is_valid_pos( int r, int c)
{
    return r >= 0 && r < MAP_ROWS && c >= 0 && c < MAP_COLS;
}



#endif
