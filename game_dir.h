#ifndef GAME_DIR_H
#define GAME_DIR_H


#include <stdbool.h>




enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DIR_NUMS,
};

extern int dir[4][2]; 


static inline enum direction reverse_dir( enum direction dir )
{
    if ( dir & 1)
	    return dir - 1;
    return dir + 1;
}

void advance_kth( int *pr, int *pc, enum direction dir, int k);

void advance( int *pr, int *pc, enum direction dir);



#endif
