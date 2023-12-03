#include "game_core.h"

int MAP_ROWS = 4;
int MAP_COLS = 4;
int cur_empty_grids = 0;


int grid[100][100] = {0};

void get_kth_begin_rc(int kth, enum direction dir, int *pr, int *pc)
{
    switch ( dir )
    {
        case LEFT:
		*pr  = kth;
		*pc  = 0;
		break;
	case RIGHT:
		*pr = kth;
                *pc = MAP_COLS - 1;
		break;
	case UP:
		*pr = 0;
		*pc = kth;
		break;
	case DOWN:
		*pr = MAP_ROWS - 1;
		*pc = kth;
		break;
	default:
                *pr = MAP_ROWS;
		break;
    }
}

void put_new_number( int target_num )
{
    if ( cur_empty_grids == 0)
	    return ;
    int put_pos = rand() % cur_empty_grids;
    int num = 0;

    if ( ~target_num  ) {
	for ( int i = 1;i <= 10; ++i)
		if ( target_num == (1 << i))
        		num = target_num; 
    }
    else {
	num = rand() % 5 ? 2 : 4;
    }

    int cnt = 0;

    for ( int i = 0;i < MAP_ROWS * MAP_COLS; ++i ) {
        int r = i / MAP_COLS;
	int c = i % 4;

	if ( grid[r][c] )
		continue;
        if ( cnt == put_pos) {
	    grid[r][c] = num ; 
	    --cur_empty_grids;
	    break;
	}
	++cnt;
    }
}

void remove_kth_space( int i, enum direction dir ) 
{
   int r,c;
   get_kth_begin_rc(i, dir, &r, &c);

   int cr = r,cc = c;
   int offset = 0;
   int pr;
   int pc;

   while (is_valid_pos(cr, cc) ) {
//	mv_next(cr, cc, REVERSE(dir), 1);
          

	  if ( grid[cr][cc] ) {
	     int v = grid[cr][cc];
             pr = cr;
	     pc = cc;
	     advance_kth( &pr, &pc, dir, offset);
	     grid[cr][cc] = 0;
	     grid[pr][pc] = v;
	  } 
	  else {
              ++offset;
	  }
	 

          advance( &cr, &cc, reverse_dir( dir ) );
   }
   
      

}
void merge_kth_line(int i, enum direction dir)
{
    int r,c;
    get_kth_begin_rc(i, dir, &r, &c);

    int offset = 0;
    int nr,nc;

    while ( is_valid_pos (r,c) && grid[r][c] ) {
	 nr = r;
	 nc = c;
         advance( &nr, &nc, reverse_dir( dir ) );

	 if ( is_valid_pos(nr, nc) && grid[r][c] == grid[nr][nc]) {
              int v = grid[r][c];
	      grid[r][c] = grid[nr][nc] = 0;

	      ++cur_empty_grids;
              int pr = r;
	      int pc = c;
	      advance_kth( &pr, &pc, dir, offset);
              grid[pr][pc] = 2 * v;

	      scores += 2 * v;
	      max_scores = scores > max_scores ? scores : max_scores;
	      ++offset;
              
	      advance( &r, &c, reverse_dir(dir) );
	 }

              advance( &r, &c, reverse_dir(dir) );
    }

}


void move_to( enum direction dir)
{
    int logical_line = 4;

    for ( int i = 0; i < logical_line; ++i) {
	remove_kth_space(i, dir);
	merge_kth_line(i, dir);
	remove_kth_space(i, dir);
    }

}



bool is_end( void )
{
    if ( cur_empty_grids > 0 )
	    return false;


    for ( int i = 0; i < MAP_ROWS; ++i) {
        for ( int j = 0; j < MAP_COLS; ++j) {

	    int nr;
	    int nc;


	    for ( int k = 0;k < DIR_NUMS; ++k ) {
                nr = i;
		nc = j;
		advance( &nr, &nc, k );

		if ( is_valid_pos( nr, nc) && grid[i][j] == grid[nr][nc] )
			return false;
	    }	    
	     
	}
    }

    return true;
}
void init_grid( void )
{
   memset(grid, 0, sizeof( grid ) );
   cur_empty_grids = MAP_ROWS * MAP_COLS;

   put_new_number( 4 );
   put_new_number( 2 );


}

