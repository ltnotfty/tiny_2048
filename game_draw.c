#include "game_draw.h"


void show_bound()
{

    // set upper_left point's br, bc
    int br = 0;
    int bc = 0;




    int map_cols = MAP_COLS * ( GRID_WIDTH + 1 ) + 1;
    int map_rows = MAP_ROWS * ( GRID_HEIGHT + 1 ) + 1;
    int r;
    int c;

    for ( int i = 0; i < MAP_ROWS + 1; ++i ) {
        r = i * (GRID_HEIGHT + 1);
	c = 0;

	mvhline( r + br, c + bc, BARR_H_CHAR, map_cols );
        
    }
    for ( int i = 0; i < MAP_COLS + 1; ++i ) {
        r = 0;
	c = i * ( GRID_WIDTH + 1 );

	mvvline( r + br, c + bc, BARR_V_CHAR, map_rows );
    }



}

void show_status( void )
{
   int br = 0;
   int bc = 0;

   int map_status_gap = 4;

   int scol = (GRID_WIDTH + 1) * MAP_COLS + 1;
   scol += map_status_gap;

   int srow = (GRID_HEIGHT + 1) * MAP_ROWS + 1;
   srow >>= 1;

   // 1. scores
   // 2. max_scores
   // 3. status

   // 4. a/s/d/w for op
   // 5. q: quit,r: a new game

   mvprintw( srow - 4, scol, "scores:%5d", scores );
   mvprintw( srow - 3, scol, "max_scores:%5d", max_scores );   mvprintw( srow - 2, scol, "status: ");
   mvprintw( srow - 2, scol, "status: ");
   if ( game_over )
	   printw("game_over o_O!");
   else
	   printw("gaming OvO!");

   mvprintw( srow + 2, scol, "a/s/d/w for op");
   mvprintw( srow + 3, scol, "q: quit, r: a new game");
   
}

void show_number( void )
{
    for ( int r = 0; r < MAP_ROWS; ++r) {
       for ( int c = 0; c < MAP_COLS; ++c) {
	   int v = grid[r][c];
           if ( !v )
		   continue;
	   int pr;
	   int pc;
           
           pr = get_kth_number_r( r );
           pc = get_kth_number_c( c );

           int color_idx = 1;
           
	   // get color pair idx
           for (int i = 1; i < 16;i++ ) {
	       if ( (1 << i) & v ) {
                   color_idx = i;
		   break;
	       }
	   }	   

	   attron( COLOR_PAIR( color_idx ) );
       
	  
	   mvprintw(pr, pc - 2, "%4d", v );

	   attroff( COLOR_PAIR( color_idx) );


       }
    }
}

void draw_frame( void )
{
    clear();
    show_bound();
    show_status();
    show_number(); 
    refresh();
}
