#include "game_dir.h"


int dir_to[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };


void advance_kth( int *pr, int *pc, enum direction dir, int k)
{
    if ( !pr || !pc)
	  return ;

    int r = *pr;
    int c = *pc;

    r += k * dir_to[dir][0];
    c += k * dir_to[dir][1];

    *pr = r;
    *pc = c;
}


void advance(int *pr, int *pc, enum direction dir)
{
   return advance_kth(pr, pc, dir, 1);
}



